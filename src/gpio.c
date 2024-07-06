/*

*/
#include "gpio.h"

static char dev[64];

int
file_exist(char *path) {
  struct stat st;

  if (stat(path, &st) != 0) {
    return 0;
  }
  return  1;
}

int
write_gpio_port(int pin, int val) {
  FILE *fd;
  char devName[64];

  sprintf(devName, "%s/gpio%d/value", GPIO_DIR, pin);
  if ((fd = fopen(devName, "w")) == NULL) {
    fprintf(stderr, "Fail to open %s\n", devName);
    return -1;
  } else {
    fprintf(fd, "%d\n", val);
    fclose(fd);
  }
  return 0;
}

int
read_gpio_port(int pin) {
  FILE *fd;
  int val;
  char devName[64];

  sprintf(devName, "%s/gpio%d/value", GPIO_DIR, pin);
  if ((fd = fopen(devName, "r")) == NULL) {
    fprintf(stderr, "Fail to open %s\n", devName);
    return -1;
  } else {
    fscanf(fd, "%d\n", &val);
    fclose(fd);
  }
  return val;
}

int
setup_gpio_port(int pin, int direction) {
  FILE *fd;
  char devPort[64];
  char *devName = GPIO_EXPORT;

  sprintf(devPort, "%s/gpio%d", GPIO_DIR, pin);
  if (file_exist(devPort) == 1){
    fprintf(stderr, "GPIO %d is already registered\n", pin);
    return 0;
  }

  if ((fd = fopen(devName, "w")) == NULL) {
    fprintf(stderr, "Fail to open: %s\n", devName);
    return -1;
  } else {
    fprintf(fd, "%d\n", pin);
    fclose(fd);
  }

  if (file_exist(devPort) == 0){
    fprintf(stderr, "Fail to setup GPIO %d\n", pin);
    return -1;
  }

  sprintf(devPort, "%s/gpio%d/direction", GPIO_DIR, pin);
  if ((fd = fopen(devPort, "w")) == NULL) {
    fprintf(stderr, "Fail to open: %s\n", devPort);
    return -1;
  } else {
    if (direction == GPIO_OUT) {
      fprintf(fd, "out\n");
    } else {
      fprintf(fd, "in\n");
    }

    fclose(fd);
  }
  
  fprintf(stderr, "setup GPIO: %d(%d)\n", pin, direction);
  return 0;
}

int
unsetup_gpio_port(int pin) {
  FILE *fd;
  int res=-1;
  char *devName = GPIO_UNEXPORT;

  if ((fd = fopen(devName, "w")) == NULL) {
    fprintf(stderr, "Fail to open: %s\n", devName);
  } else {
    fprintf(fd, "%d\n", pin);
    fclose(fd);
  }
  fprintf(stderr, "unexport GPIO: %d\n", pin);
  return res;
}

char *
gen_port(char *f) {
  sprintf(dev, "%s/%s", GPIO_DIR, f); 
  return (char *)dev;
}


#ifdef MAIN_
int
main(int argc, char **argv) {
  int pin = 79;
  int dir = GPIO_IN;

  if (argc < 2) { 
    fprintf(stderr, "Usage: %s [pin] [dir] \n", argv[0]);
    return -1;
  }

  pin = atoi(argv[1]);

  if (argc > 2) { 
    dir = atoi(argv[2]);
  }

  if (dir <  0) { 
    unsetup_gpio_port(pin);
  } else {
    setup_gpio_port(pin, dir);
    int val = read_gpio_port(pin);

    int outVal=0;
    if (val == 0){ outVal=1; }
    write_gpio_port(pin, outVal);
    val = read_gpio_port(pin);
    fprintf(stderr, "====> %d\n", val);

  }

  return 0;
}


#endif
