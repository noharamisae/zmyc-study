#include <stdio.h>
#define PI 3.14159//宏定义
int cutimeFunction(int a,int b);
int main(){
    printf("hello\n");
    int cutimeFunctionResult = cutimeFunction(5,3);
    return 0;
}
int cutimeFunction(int a, int b){
    printf("sizeof(a): %zu\n",sizeof(a));
    int max = (a > b) ? a : b;  // 判断a和b哪个大
    printf("max: %d\n",max);
    printf("a & b: %d\n",a & b);
    printf("&a(adress of a): %p\n",&a);// &a 表示变量 a 的地址。%p 以十六进制格式输出这个地址。
    int *p = &a;
    printf("*p %d\n",*p);//*p 是一个指针变量，它指向变量 a 的地址，所以 *p 等于 a。
    printf("p -> a:\n",p->a);
    return 0;
    
}

