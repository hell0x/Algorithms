/**
 * 有一个整型数组a，有10个元素，要求输出数组中的全部元素。
 * 用指针变量指向数组元素
 */
#include <stdio.h>
int main(){
	int a[10], *p;
	printf("Please enter 10 integer numbers: \n");
	for(p=a; p<(a+10); p++)
		scanf("%d", p);
	for(p=a; p<(a+10); p++)
		printf("%d ", *p);
	return 0;
}