#include <stdio.h>
int main(){
	char a[] = "fighting", b[10];
	int i;
	for(i=0; *(a+i)!='\0'; i++)
		*(b+i) = *(a+i);
	*(b+i) = '\0';
	printf("a: ");
	printf("%s\n", a);
	printf("b: ");
	printf("%s\n", b);
	return 0;
}