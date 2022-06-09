#ifndef __TEST_H__
#define __TEST_H__

#include <config.h>
#include <log.h>

__attribute__((noinline))
void check(bool cond) {
  if (!cond) assert(0)/*halt(1)*/;
}
void str_reset(){
  memset(str, 0, 99);
}

/*复位*/
void reset() {
  int i;
//  printf("reset data:\t");
  for (i = 0; i < N; i ++) {
    data[i] = i + 1;
//    printf("%d ", data[i]);
  }
//  printf("\n");
}
// 检查[l,r)区间中的值是否依次为val, val + 1, val + 2...
void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val + i - l);
  }
//  Log("check_seq success\n");
}
// 检查[l,r)区间中的值是否均为val
void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val);
  }
//  Log("check_eq success\n");
}

void print_data(int val, int l, int r){
  int i;
  printf("l:%d\tr:%d\tval:%d\t data: ", l, r, val);
  for (i = 0; i < N; i ++) {
    printf("%d ", data[i]);
  }
  printf("\t\tmemset(data+%d, %d, %d);\n", l, val, r-l);
}

#endif