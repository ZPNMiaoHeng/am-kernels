#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>

#define N 32
//#define __NATIVE_USE_KLIB__
#define CONFIG_LOG_ENABLE true

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

uint8_t data[N];
char str[99];

#endif