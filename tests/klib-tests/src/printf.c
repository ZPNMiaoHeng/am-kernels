#include <debug.h>

static struct data {
    int num;
    char d[128];
} data[N];

  char str[129] = "0123456789abcdef0123456789abcdef";
void reset() {
  static int i;
  static char *q = str;
//  printf("reset data:\t");
  printf("num\tdata\n");
    for (i = 0; i < N; i ++) {
      data[i].num = i;
      memset(data[i].d, '\0', sizeof(data[i].d));
      memset(data[i].d, *q, 128);
//      memcpy(data[i].d, q, 128);
//      memccpy(data[i].d, *q, 16);
    printf("%d %s %c\t", data[i].num, data[i].d, data[i].d);
//    printf("%x",data[i].num);
//    printf("%d\t", data[i].num);  
//    printf("%c\t", data[i].d);
      if(*q != '\0' )
        q ++;
      else 
        q = q -N+1;
    printf("\n");
    }
  printf("\n");
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
void test_printf(){
  int l, r;
  for (l = 0; l < N; l ++) {
    for(r = l + 1; r <= N; r ++) {
      reset();
      pdata();
    }
  }
}

int main(int argc, char const *argv[])
{
    reset();
//    test_printf();
    return 0;
}
