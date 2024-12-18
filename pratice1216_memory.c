/**
 * 动态内存管理相关练习题 
 */
#include <stdio.h>
int main() {
    pratice01();//题目1: 基本动态内存分配题目
    pratice02();//题目2: 字符动态输入

    //题目3: 字符动态输入的情况下，如果用户输入的字符超过了初始缓冲区大小
    pratice03();
    return 0;
}
/**
 * 题目1 ： 基本动态内存分配 
 * 编写一个程序，使用 malloc 分配一个整数数组，长度由用户输入。程序要求：
 * 初始化数组，存储从 1 到 n 的整数。
 * 输出数组内容。
 * 使用 free 释放内存
 */
int pratice01() {
    int  n;//数组长度
    printf("请输入数组长度： \n");
    scanf("%d", &n);

    //动态分配内存 
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr ==NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    //初始化数组
    for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    //输出数组内容 
    for (int i = 0;i < n; i++){
        printf("初始化的数组内容为: %d \n", arr[i]);
    }
    
    //释放内存 
    free(arr);
    printf("释放内存成功！\n");
    return 0;
}

/**
 * 题目2 ： 字符动态输入 
*编写一个程序，让用户输入一行字符串。
*使用 malloc 动态分配内存存储该字符串。
*计算字符串的长度并输出。
*使用 free 释放内存。
 */

int pratice02() {
    char *str;
    int buffer_size = 100; //设置初始缓冲区大小

    //动态分配初始内存 
    str = malloc(buffer_size * sizeof(char));
    if (str ==NULL){
        printf("内存分配失败！\n");
        return 1;
    }

    //提示用户输出字符串 
    printf("请输入一行字符串：\n");
    fgets(str, buffer_size, stdin);

    //计算字符串长度
    size_t length = strlen(str);

    //移除换行符
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }
    
    //输出字符串长度
    printf("您输入的字符串时: %s\n", str);
    printf("字符串的长度为: %d\n", length);

    //释放内存
    free(str);
    printf("释放内存成功！\n");
    return 0;
}

/**
 * 题目3 ： 字符动态输入的情况下，如果用户输入的字符超过了初始缓冲区大小
 * 编写一个程序，让用户输入一行字符串。
 * 使用 malloc 动态分配内存存储该字符串。
 * 计算字符串的长度并输出。
 * 如果用户输入的字符超过了初始缓冲区大小，则重新分配内存，并将原有内容复制到新内存中。
 * 使用 free 释放内存。
 */

int pratice03() {
    char *str;
    int buffer_size = 10; //初期バッファサイズ
    char *buffer = (char *)malloc(buffer_size * sizeof(char));//動的メモリ割り当て

    if (buffer == NULL) { //メモリ割り当て失敗チック
        printf("メモリ割り当て失敗チェック \n"); 
        return 1;
    }

    //ユーザーに入力を促す
    printf("文字列を入力してください（Enterで終了）: \n");

    int position = 0; //現在の文字位置
    char ch;//ユーザーが入力する文字

    //1文字ずつ入力を読み取る 
    while ((ch = getchar()) != '\n' && ch != EOF) { //改行文字とファイル終端でないことを確認する
    printf("position :%d\n", position);
    printf("ch :%c\n", ch);
    printf("buffer_size :%d\n", buffer_size);
    buffer[position] = ch;
    position ++; 
    //・buffer[position++] = ch　==　buffer[position] = ch; position++;？？？？？？後で確認

        

    }
    return 0;
}
