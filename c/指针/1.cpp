/**
 * 为了使在函数中改变了的变量值能被主调函数main所用，不能采取上述的把要改变的变量作为参数的办
 * 法，而应该用指针变量作为函数参数，在函数执行过程中使指针变量所指向的变量值发生变化，函数调
 * 用结束后，这些变量值依然保留了下来。
 */
#include <stdio.h>
int main(){
	void exchange(int *p1, int *p2, int *p3);
	int a, b, c, *p1, *p2, *p3;
	printf("Please input three integer number:\n");
	scanf("%d%d%d", &a, &b, &c);
	p1 = &a;
	p2 = &b;
	p3 = &c;
	exchange(p1, p2, p3);
	printf("Order: %d %d %d\n", a, b, c);
	return 0;
}
void exchange(int *p1, int *p2, int *p3){
	void swap(int *q1, int *q2);
	if(*p1 < *p2) swap(p1, p2);
	if(*p1 < *p3) swap(p1, p3);
	if(*p2 < *p3) swap(p2, p3);
}
void swap(int *q1, int *q2){
	int temp;
	temp = *q1;
	*q1 = *q2;
	*q2 = temp;
}
