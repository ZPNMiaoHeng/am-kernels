#include <debug.h>
static struct data {
  char d[n + 1];
} data[n + 1];

static struct ref_data {
  char d[n + 1];
} ref_data[n + 1];


char str[n+1] =  "0123456789abcdef";
char *p = str;

void init_ref() {
  static int i;
  static char *q = str;
  printf("ref data:\t");
  for (i = 0; i < n + 1; i ++) {
    memset(ref_data[i].d, '\0', sizeof(data[i].d));
    memset(ref_data[i].d, *q, 1);
    printf("%s\t", ref_data[i].d);
    if(*q != '\0' )
      q ++;
    else 
      q = q - n ;
  }
  printf("\n");
}

/*复位*/
void reset() {
  static int i;
  static char *q = str;
#ifndef CONFIG_RESET_NDISPLAY
  printf("reset data:\t");
  for (i = 0; i < n + 1; i ++) {
    memset(data[i].d, '\0', sizeof(data[i].d));
    memset(data[i].d, *q, 1);
    printf("%s\t", data[i].d);
    if(*q != '\0' )
      q ++;
    else 
      q = q - n ;
  }
  printf("\n");
}
#else 
  for (i = 0; i < n; i ++) {
    memset(data[i].d, '\0', sizeof(data[i].d));
    memset(data[i].d, *q, 1);
    if(*q != '\0' )
      q ++;
    else 
      q = q -N;
  }
}
#endif

void display_data(int l, int r){
  static int i, j;
  j ++;
  printf("display data:\t");
//  printf("num\tdata\n");
  for(i = 0; i < n + 1; i ++) {
    printf("%s\t", data[i].d);
  }
    printf("\n"LINE" %d "LINE"\n", j);
}

// 检查[l,r)区间中的值是否依次为ref相同 初始哈化字符串
void check_seq(int l, int r) {
  int i;
  for (i = l; i < r; i ++) {
    assert(!strcmp(data[i].d, ref_data[i].d));
    p ++;
  }
  Log("check_seq success\n");
}
// 检查[l,r)区间中的值是否均为val
/*
void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(data[i] == val);
  }
//  Log("check_eq success\n");
}
*/

void test_memmove(){
  int l, r;
  for (l = 0; l < n; l ++) {
    for(r = l + 1; r <= n; r ++) {
      reset();
      uint8_t val = (l + r) / 2;
#ifndef __NATIVE_USE_KLIB__
      memcpy((data + l) -> d, p + val, r - l);
      printf("r=%d\tl=%d\tval=%d\t", r, l, val);
      printf("memcpy((data + %d)->d, p + %d, %d)\t:%s\n", l, val, r - l, data[l].d);
      display_data(l ,r);


//      check_seq(0, l);
//      check_eq(l, r, val);
//      check_seq(r, n);
#else
      memcpy(data[l].d, p, val);
//      check_eq(r - l);
#endif
    }
  }
}

int main(int argc, char const *argv[])
{
    init_ref();
//    reset();
    test_memmove();
    return 0;
}

