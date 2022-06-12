#include <debug.h>

static struct data {
  int num;
  char d[N+1];
} data[N];

char str[N+1] =  "0123456789abcdef0123456789abcdef";
char *p = str;

/*复位*/
void reset() {
  static int i;
  static char *q = str;
//  printf("reset data:\t");
//  printf("num\t\tdata\n");
  for (i = 0; i < N; i ++) {
    data[i].num = i;
    memset(data[i].d, '\0', sizeof(data[i].d));
    memset(data[i].d, *q, 1);
//    printf("%d\t%s\t", data[i].num, data[i].d);  
//    printf("%s\t", q);
    if(*q != '\0' )
      q ++;
    else 
      q = q -N;
//    printf("\n");
  }
//  printf("\n");
}

void test_memmove(){
  int l, r;
  for (l = 0; l < N; l ++) {
    for(r = l + 1; r <= N; r ++) {
      reset();
      uint8_t val = r - l;
//      printf("%s\t", data[l].d);
      memcpy(data[l].d, p, val);
      printf("r=%d\tl=%d\tmemcpy(data[%d].d, p, %d)\t:%s\n", r, l, l, r-l, data[l].d);
//      check_eq(r - l);
    }
  }
}


int main(int argc, char const *argv[])
{
    reset();
//    reset();
    test_memmove();
//    strcpy(data[2].d, "a");
//    printf("str=%s\n", p);
//    strcpy(p, "abcd");
//    printf("str=%s\n", p);
    return 0;
}

