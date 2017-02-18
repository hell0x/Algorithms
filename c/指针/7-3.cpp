#include <stdio.h>
int main(){
	void copy_string(char *from,char *to);
	char a[] = "weixing";
	char b[] = "coding changes the world";
	printf("a: ");
	printf("%s\n", a);
	printf("b: ");
	printf("%s\n", b);
	copy_string(a, b);
	printf("a: ");
	printf("%s\n", a);
	printf("b: ");
	printf("%s\n", b);
	return 0;
}
void copy_string(char *from,char *to)
{
	for(; *from!='\0'; from++, to++){
		*to = *from;
	}
	*to = '\0';
}