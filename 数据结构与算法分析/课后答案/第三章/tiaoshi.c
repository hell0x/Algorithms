#include <stdio.h>

int ComputeValue(int n);    //����1+2+...+n��ֵ
void UpperCase(char * str); //���ַ���str�е�Сд��ĸת��Ϊ��д��ĸ

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