#include <stdio.h>

int ComputeValue(int n);    //计算1+2+...+n的值
void UpperCase(char * str); //将字符串str中的小写字母转换为大写字母

int main(int argc, char *argv[])
{
    char szMyStr[] = "C-Free Debug";

    printf("%d\n",ComputeValue(1000));
    UpperCase(szMyStr);
    printf(szMyStr);
    
    return 0;
}

int ComputeValue(int n)
{
    int i,s=0;
    for(i=1; i<=n; i++)
    {
        s += i;
    }
    return s;
}

void UpperCase(char *str)
{
    char *p = str;
    while(*p)
    {
        if(*p>='a' && *p<='z')
        {
            *p = *p - 'a'+ 'A';
        }
        p++;
    }
}