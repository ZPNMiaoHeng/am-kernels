#include <am.h>
#include <klib-macros.h>

int main(const char *args) {
  const char *fmt =
    "Hello, AbstractMachine!\n"
    "mainargs = '%'.\n";
/* putstr:put all strings*/
  for (const char *p = fmt; *p; p++) {
    (*p == '%') ? putstr(args) : putch(*p);
  }
  return 0;
}
