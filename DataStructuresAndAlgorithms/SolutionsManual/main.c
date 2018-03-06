#include <stdio.h>
#include "function.h"

int main()
{
   int a = 1,b =2;
   int c = add(a,b);   //这里是对function.c中的add函数的调用
   printf("c=%d",c);

   return 0;   
}