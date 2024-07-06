/*

*/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#define GPIO_DIR  	"/sys/class/gpio"
#define GPIO_EXPORT 	"/sys/class/gpio/export"
#define GPIO_UNEXPORT  	"/sys/class/gpio/unexport"

#define GPIO_IN		0
#define GPIO_OUT	1

/*

 */
int file_exist(char *path);
int write_gpio_port(int pin, int val);
int read_gpio_port(int pin);
int setup_gpio_port(int pin, int direction);
int unsetup_gpio_port(int pin);
char * gen_port(char *f);
