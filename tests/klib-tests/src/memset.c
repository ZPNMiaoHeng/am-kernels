#include <debug.h>

uint8_t data[N];
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

void test_memset() {
  int l, r;
  for (l = 0; l < N; l ++) {
    for (r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
      memset(data + l, val, r - l);
#ifndef __NATIVE_USE_KLIB__
      print_data(val, l, r);
#endif
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
#ifndef __NATIVE_USE_KLIB__
  Log("Pass %d test\n",l*r);
#endif
}

int main(){
    test_memset();
    return 0;
}
