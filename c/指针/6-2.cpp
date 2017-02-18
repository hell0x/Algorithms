#include <stdio.h>
int main(){
	char a[]="fighting", b[10], *p, *q;
	p=a; q=a;
	for(; *p!='\0'; p++, q++)
		*q = *p;
	*q = '\0';
	printf("a: ");
	printf("%s\n", a);
	printf("b: ");
	printf("%s\n", b);
	return 0;
}