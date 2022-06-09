#include <debug.h>

static struct data {
    int num;
    char d[128];
} data[N];

char str[N+1] = "0123456789abcdef0123456789abcdef";
char *p = str;
/*复位*/
void reset() {
  int i;
//  printf("reset data:\t");
  for (i = 0; i < N; i ++) {
    data[i].num = i;
    memset(data[i].d, '\0', sizeof(data[i].d));
//    printf("%d %s\t", data[i].num, data[i].d);
  }
//  printf("\n");
}

void check_eq(int l){
  int i;
  for(i = 0; i < N; i ++) {
    assert(strcmp(data[l].d, p+l));
  }
}

void test_strcpy(){
  int l;
  for (l = 0; l < N; l ++) {
      reset();
      strcpy(data[l].d, p);
      p = p + 1;
//      printf("%d\t:%s\n", l, data[l].d);
      check_eq(l);
  }
}

int main(int argc, char const *argv[])
{
//    test_strcpy();
//    reset();
    test_strcpy();
//    strcpy(data[2].d, "a");
//    printf("str=%s\n", p);
//    strcpy(p, "abcd");
//    printf("str=%s\n", p);
    return 0;
}
