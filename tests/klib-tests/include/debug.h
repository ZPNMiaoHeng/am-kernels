#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>

#define N 32
//#define __NATIVE_USE_KLIB__
#define CONFIG_LOG_ENABLE true
#define CONFIG_TEST_PRINTF 

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_NONE       "\33[0m"
// macro testing
// See https://stackoverflow.com/questions/26099745/test-if-preprocessor-symbol-is-defined-inside-macro
#define CHOOSE2nd(a, b, ...) b
#define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma a, b)
#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)
#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE               //: str color
bool log_enable() {
  return MUXDEF(CONFIG_LOG_ENABLE, true, false);
}

#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
  } while (0)

#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

__attribute__((noinline))
void check(bool cond) {
  if (!cond) assert(0)/*halt(1)*/;
}

#endif