#include <stdio.h>
int main(){
	void copy_string(char from[],char to[]);
	char a[] = "weixing";
	char b[] = "coding changes the world";
	char *from=a, *to=b;
	printf("a: ");
	printf("%s\n", a);
	printf("b: ");
	printf("%s\n", b);
	copy_string(from, to);
	printf("a: ");
	printf("%s\n", a);
	printf("b: ");
	printf("%s\n", b);
	return 0;
}
void copy_string(char from[],char to[])
{
   int i=0;
   while(from[i]!='\0')
   {
      to[i]=from[i];
      i++;
   }
   to[i]='\0';
}