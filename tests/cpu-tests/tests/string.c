#include "trap.h"

char *s[] = {
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	", World!\n",
	"Hello, World!\n",
	"#####"
};

char str1[] = "Hello";
char str[20];

int main() {

//	char ch = 'A';
	putch('a');
	putch(*s[0]);
	check(strcmp(s[0], s[2]) == 0);
	check(strcmp(s[0], s[1]) < 0);
	check(strcmp(s[0] + 1, s[1] + 1) < 0);
	check(strcmp(s[0] + 2, s[1] + 2) < 0);
	check(strcmp(s[0] + 3, s[1] + 3) < 0);
	check(strcmp( strcat(strcpy(str, str1), s[3]), s[4]) == 0);

	check(memcmp(memset(str, '#', 5), s[5], 5) == 0);
//	putch(*str1);

	check(strlen(s[5]) == 5);																		// check strlen 
	check(memcmp(memcpy(str, s[5], 5), s[5], 5) == 0);												// check memcpy
//	printf("%s\n",strncpy(str, str1,strlen(str1)));													
//	check(strcmp( strcat(strncpy(str, str1,strlen(str1)), s[3]), s[4]) == 0);						// check strncpy: error
	check(strncmp(s[0], s[2], 10) == 0);                                                            // check strncmp
	check(memcmp(memmove(str, s[5], 5), s[5], 5) == 0);                                             // check memmove

	return 0;
}
