#include <stdio.h> // 引入标准输入输出函数库
#include <string.h> // 引入字符串处理函数
#include <stdbool.h> // 引入bool类型
#include <stdbool.h>

#define PI 3.14159//宏定义
struct Student {
    int age, id;
    char name[50];
};

void cutimeFunction2();
int cutimeFunction(int a,int b);
void cutimeFunction3();
int main(){
    int cutimeFunctionResult = cutimeFunction(5,3);
    cutimeFunction2();
    cutimeFunction3();
    return 0;
}
int cutimeFunction(int a, int b){
    printf("sizeof(a): %zu\n",sizeof(a));
    int max = (a > b) ? a : b;  // 判断a和b哪个大
    printf("max: %d\n",max);
    printf("a & b: %d\n",a & b);
    printf("&a(adress of a): %p\n",&a);// &a 表示变量 a 的地址。%p 以十六进制格式输出这个地址。
    int *p = &a;
    printf("*p %d\n",*p);//*p 是一个指针变量，它指向变量 a 的地址，所以 *p 输出了a的value值。
    return 0;
}
// 定义一个结构体变量，并给成员变量赋值 通过.出来 访问成员变量
void cutimeFunction2(){
    char sprintfBuffer[50];
    struct Student student;//定义一个结构体变量
    //给成员变量赋值
    // strcpy(student.name,"zhangmengyao");//strcpy函数用来拷贝字符串  只复制字符串内容，不会进行格式化操作 不会检查缓冲区大小  可能会导致缓冲区溢出
    sprintf(student.name,"beautiful girl");//sprintf函数用来格式化字符串  会检查缓冲区大小  不会导致缓冲区溢出
    sprintf(sprintfBuffer,"she is %s",student.name);
    printf("sprintfBuffer: %s\n",sprintfBuffer);
    char buffer[50];
    int age = 25;
    sprintf(buffer, "I am %d years old.", age);  // buffer现在包含"I am 25 years old."
    //访问成员变量 
    printf("student.name: %s\n",student.name);
    printf("buffer: %s\n",buffer);
}

void cutimeFunction3(){
    // 常用数据类型
    // 整型
    int num = 42;                     // 带符号整数	4 字节 -2,147,483,648 到 2,147,483,647
    unsigned int unum = 42;           // 无符号整数 4 字节 0 到 4,294,967,295
    short snum = 42;                  // 带符号短整数 2 字节 -32,768 到 32,767
    unsigned short usnum = 42;        // 无符号短整数 2 字节 0 到 65,535
    long lnum = 42;                   // 带符号长整数 8 字节 -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
    unsigned long ulnum = 42;         // 无符号长整数 8 字节 0 到 18,446,744,073,709,551,615
    long long llnum = 42;             // 带符号长长整数 8 字节 -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807

    //浮点型
    float fnum = 3.14159;             // 单精度浮点型 4 字节
    double dnum = 3.14159;            // 双精度浮点型 8 字节
    long double ldnum = 3.14159;       // 长双精度浮点型 16 字节

    // 字符型
    char c = 'a';                     // 单个字符 1 字节
    char str[] = "hello world";       // 字符串 11 字节
    char str2[50] = "hello world";   // 字符串 50 字节

    // 布尔型
    bool boolb = true;                    // 布尔型 1 字节

    // 指针型
    int *p = &num;                    // 指向整型的指针 4 字节
    double *pd = &dnum;               // 指向浮点型的指针 8 字节
    char *pc = &c;                    // 指向字符型的指针 4 字节

    // 数组型
    int arr[10];                     // 整型数组 40 字节
    double darr[10];                 // 浮点型数组 80 字节
    char strarr[10][50];             // 字符串数组 500 字节 二维数组 十行 50个字节
    // 结构体型
    struct Student stu;               // 结构体 大概是成员相加的字节 
    // 枚举型
    enum Color { RED, GREEN, BLUE };  // 枚举 1 字节
    // 宏定义
    #define PI 3.14159                // 宏定义 4 字节
    // 常量
    const int MAX_SIZE = 100;         // 常量 4 字节

    // 枚举变量声明
    enum Color color;                 // 枚举变量声明 1 个枚举变量 1 字节
    // 宏定义声明
    #define PI 3.14159                // 宏定义声明 4 字节
    // 指针常量声明
    const int *const pnum = &num;     // 指针常量声明 4 字节    
    // 变量定义
   
 
    char str1[50] = "hello";
       strcpy(str2, "new string"); // 替换整个字符串
       str2[0] = 'H'; // 修改第一个字符
       strcat(str2, "ello"); // 追加字符串
    // 结构体变量定义
    struct Student stu1 = { 25, 1001, "zhangmengyao" };  // 结构体变量定义 1 个结构体变量 100 字节
    struct Student stu2 = { 30, 1002, "beautiful girl" };  // 结构体变量定义 1 个结构体变量 100 字节
    // 数组变量定义
    int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // 数组变量定义 1 个数组变量 80 字节
    int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };  // 数组变量定义 1 个数组变量 80 字节
    // 枚举变量定义
    color = BLUE;           // 枚举变量定义 1 个枚举变量 1 字节
    printf("int: %d\n", num);                  // 输出 int
    printf("unsigned int: %u\n", unum);         // 输出 unsigned int
    printf("short: %d\n", snum);                // 输出 short
    printf("unsigned short: %u\n", usnum);       // 输出 unsigned short
    printf("long: %ld\n", lnum);                // 输出 long
    printf("unsigned long: %lu\n", ulnum);       // 输出 unsigned long
    printf("long long: %lld\n", llnum);          // 输出 long long
    printf("float: %f\n", fnum);                // 输出 float
    printf("double: %lf\n", dnum);               // 输出 double
    printf("long double: %Lf\n", ldnum);         // 输出 long double
    printf("char: %c\n", c);                    // 输出 char
    printf("string: %s\n", str);                // 输出 string
    printf("string2: %s\n", str2);              // 输出 string2                 // 输出 bool
    printf("pointer: %p\n", p);                 // 输出 pointer
    printf("double pointer: %p\n", pd);          // 输出 double pointer
    printf("char pointer: %p\n", pc);            // 输出 char pointer
    printf("array: %d\n", arr[0]);              // 输出 array第一个元素
    printf("Array address (equiv): %p\n", &arr[0]); // 等价的首地址
    printf("double array: %lf\n", darr[0]);       // 输出 double array
    printf("string array: %s\n", strarr[0]);     // 输出 string array
    printf("student.name: %s\n", stu.name);      // 输出 student.name
    printf("color: %d\n", color);               // 输出 color
    printf("PI: %f\n", PI);                     // 输出 PI
    printf("MAX_SIZE: %d\n", MAX_SIZE);         // 输出 MAX_SIZE
}

