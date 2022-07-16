#include <debug.h>

static struct data {
    int num;
    char d[128];
} data[N];

  char str[N+1] = "0123456789abcdef0123456789abcdef";
//  char *p = str;
/*复位*/
void reset() {
  static int i;
  static char *q = str;
  printf("reset data:\t");
//  printf("num\t\tdata\n");
  for (i = 0; i < N; i ++) {
    data[i].num = i;
    memset(data[i].d, '\0', sizeof(data[i].d));
    memset(data[i].d, *q, 1);
//    printf("%d\t%s\t", data[i].num, data[i].d);  
    printf("%s ", data[i].d);  
//    printf("%s\t", q);
    if(*q != '\0' )
      q ++;
    else 
      q = q -N+1;
//    printf("\n");
  }
  printf("\n");
}

void check_eq(int l){
  int i;
  char test[N];
  strcpy(test[N], );
  for(i = 0; i < N; i ++) {
    assert(strcmp(data[l].d, test));
  }
}

void pdata(){
  static int i;
  printf("Mmove data:\t");
  for(i=0; i < N; i ++) {
    printf("%s ", data[i].d);  
  }
  printf("\n");
  printf("----------------------------------------------------------------------------------------\n");
}
void test_memcpy(){
  int l, r;
  for (l = 0; l < N; l ++) {
    for(r = l + 1; r <= N; r ++) {
      reset();
//      uint8_t val = (l + r) / 2;
      uint8_t val = r - l;
//      printf("%s\t", data[l].d);
      memcpy(data[l].d, data[r].d, val);
//      printf("r=%d\tl=%d\t memcpy(data[%d].d, data.[%d].d, %d)\t\n", r, l, l, r, val);
      check_eq(r - l);
      pdata();
    }
  }
}

int main(int argc, char const *argv[])
{
    reset();
//    reset();
    test_memcpy();
//    strcpy(data[2].d, "a");
//    printf("str=%s\n", p);
//    strcpy(p, "abcd");
//    printf("str=%s\n", p);
    return 0;
}
