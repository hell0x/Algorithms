#include <stdio.h>
#include <stdlib.h>
#include <stk.h>

/**
 * isNumber 
 * 判断元素是否是数字
 */
int isNumber(char c){
	int ret = 0;
	ret = (c >= '0') && (c <= '9');
	return ret;
}

/**
 * isMark
 * 判断元素是否是加减乘除这四个运算符
 */
int isMark(char c){
	int ret = 0;
	ret = (c == '+') || (c == '-') || (c == '*') || (c == '/');
	return ret;
}

/**
 * isLBracket
 * 判断元素是否是左括号
 */
int isLBracket(char c){
	int ret = 0;
	ret = (c == '(');
	return ret;
}

/**
 * isRBracket
 * 判断元素是否是右括号
 */
int isRBracket(char c){
	int ret = 0;
	ret = (c == ')');
	return ret;
}

/**
 * Priority
 * 对传进来的元素划分优先级
 */
int Priority(char c){
	if(c == '+' || c == '-')
		ret = 1;
	else if(c == '*' || c == '/')
		ret = 2;
	else
		ret = 3;
	return ret;
}
