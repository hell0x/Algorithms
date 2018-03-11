#include <stdio.h>
#include <time.h>

clock_t start, stop;
/*clock_t是clock()函数返回的变量类型*/
double duration;

int main(){
	start = clock();
	/*要测试执行时间的函数*/
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	return 0;
}