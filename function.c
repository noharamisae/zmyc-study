#include <stdio.h>  // 引入标准输入输出函数库
#include <string.h> // 引入字符串处理函数库
#include <stdlib.h> // 引入动态内存分配函数库
#include <ctype.h>  // 引入字符处理函数库

struct Data
{
    int id;
    float value;
    char name[10];
};
int main()
{

    printf("Hello, %s!\n", "world 张梦瑶");          // 输出：Hello, world!
    printf("输出整数和浮点格式%d, %4f\n", 10, 3.14); // 输出：整数: 10, 浮点数: 3.14

    // sprintf函数用于格式化字符串输出
    char buffer[50];
    sprintf(buffer, "Name: %s, Age: %d", "Alice", 25);
    printf("sprintf函数用于格式化字符串输出: %s\n", buffer); // 输出：Formatted String: Name: Alice, Age: 25

    // snprintf は sprintf に似ていますが、バッファサイズ n を指定することで、バッファオーバーフローを防ぎます。
    char buffer2[100];
    snprintf(buffer2, sizeof(buffer2), "snprintf函数与sprintf函数类似，但会指定缓冲区大小 n，避免缓冲区溢出。Data: %d, %2f", 123, 4.56); // sizeof(buffer) 指定这个缓冲区大小
    printf("Buffer: %s\n", buffer2);                                                                                                     // 输出：Buffer: Data: 123, 4.56

    // memset方法 void *memset(void *s, int c, size_t n);
    // memset はメモリをバイト単位で均一に埋めるためのものであり、構造体の異なるメンバーに異なる値を設定することはできません。
    int arr[5];
    // 配列名を直接渡します。配列名は配列の先頭アドレスを指すポインタです。
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < 5; i++)
    {
        printf("memset数组可以进行统一填充%d\n", arr[i]);
    }
    struct Data data;

    // 各メンバーに個別に値を割り当てます。
    data.id = 101;
    data.value = 99.99;
    strcpy(data.name, "John Doe");                                                    // 字符串赋值需要使用 strcpy
    printf("结构体赋值: id=%d, value=%f, name=%s\n", data.id, data.value, data.name); // 输出：结构体赋值: id=101, value=99.99, name=John Doe

    struct Data data2 = {101, 99.99, "amy"};
    printf("结构体直接赋值语句: id=%d, value=%2f, name=%s\n", data2.id, data2.value, data2.name); // 输出：结构体赋值: id=101, value=99.99, name=John Doe

    struct Data *ptr = &data2;
    // ポイントを使用して構造体のメンバーにアクセスと値を割り当てます。
    ptr->id = 300;
    ptr->value = 11.99;
    strcpy(ptr->name, "John Doe2");
    printf("指针对结构体成员赋值语句: id=%d, value=%2f, name=%s\n", data2.id, data2.value, data2.name); // 输出：结构体赋值: id=101, value=99.99, name=John Doe

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memset(arr2, 0, 5 * sizeof(int));
    memset(&arr2[3], 0, 5 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr2[i]); // 输出：1 2 0 0 0 0 0 8 9 10
    }

    // memcpy 函数
    // memcpy 函数是 C 语言和 C++ 标准库中提供的一个函数，用于将一块内存区域的数据复制到另一块内存区域
    void *memcpy(void *dest, const void *src, size_t n);
    // dest: 数据复制的目标内存地址（目的地）。
    // src: 数据复制的源内存地址（源头）。
    // n: 复制的字节数。
    // 返回值：返回指向目标内存地址的指针。
    char src[] = "Hello, World!";
    char dest[20];
    // //复制src到dest strlen函数是为了计算字符串的长度 加1是因为在c语言中，字符串实际上是一个字符数组，\0用来标记字符串的结束位置
    memcpy(dest, src, strlen(src) + 1);
    printf("memcpy函数用于将一个内存区域的数据复制到另一块内存区域: %s\n", dest); // 输出HELLO, WORLD!

    // memcmp函数用来比较两块内存区域的内容
    //  int memcmp(const void *s1, const void *s2, size_t n);这个方法签名前两个是内存的指针地址，不是单纯变量
    // s1是第一个内存区域的地址
    // s2是第二个内存区域的地址
    // n是需要比较的字节数
    // 返回值：如果s1和s2的前n个字节相同，则返回0；如果s1的字节数小于s2的字节数，则返回-1；如果s1的字节数大于s2的字节数，则返回1。
    // 如果比较的前n个字节完全相同，则返回0
    char memcmp_str1[] = "HELLO";
    char memcmp_str2[] = "HELLO c";
    int result = memcmp(&memcmp_str1[2], &memcmp_str2[2], 2);
    printf("使用memcmp函数比较字符串%d\n", result);
    // 返回-1
    //  //使用场景 比较二进制数据 比较字符串 数据完整性比较  大小写敏感

    /**
     * memchr函数用来在内存区域中查找指定字符的首次出现位置
     */
    // void *memchr(const void *s， int c， size_t n);
    // s: 内存区域的起始地址
    // c: 要查找的字符。
    // n: 内存区域的字节数
    // memchr函数会从s所指的内存块中搜索前n个字节，查找是否存在c的值（按字节逐一比较）
    // 成功时，返回指向首次找到字符的指针。
    // 失败时，返回Null
    char str_memchr[] = "Hello, World!";
    char target = 'l';

    char *result4 = (char *)memchr(&str_memchr[2], target, strlen(str_memchr) - 2); // 这里加*是解引用 * 用于获取指针所指向内存地址中的值

    if (result4)
    {
        printf("使用 memchr 函数查找到的字符是: %c\n", *result4);
        printf("查找到字符的地址: %p\n", (void *)result4);
    }

    /**
     * malloc函数 用来动态分配内存 引入 <stdlib.b>
     */

    // void *malloc(size_t size);  分配一个内存地址，返回指向该内存地址的指针。
    // size: 要分配的内存字节数
    // 成功时: 返回分配的内存块的首地址（void* 类型，需要进行类型转换）。
    // 失败时: 返回 NULL，表示分配失败（通常由于内存不足
    // malloc 从堆中分配指定字节数的连续内存块，分配的内存不会初始化，内容是未定义的（随机值）。

    // *用于定义一个指针变量，表示该变量存储的是一个内存地址
    int *arr_malloc;
    size_t n = 5;
    arr_malloc = malloc(n * sizeof(int));
    printf("arr_malloc的起始地址是: %p\n", (void *)arr_malloc); // 输出分配给arr的起始地址 ,%p 是用于打印指针地址的标准格式。(void*) 是将指针强制转换为 void* 类型，这是 %p 格式说明符的要求。
    // 初始化分配的内存
    // 指针变量可以像数组一样通过下表[i]来访问·
    for (int i = 0; i < 5; i++)
    {
        arr_malloc[i] = i;
        printf("%d ", arr_malloc[i]); // 输出 0 1 2 3 4
    }

    // 释放内存
    free(arr_malloc);
    // c语言不进行边界检查
    // 访问数组时候，编译器只根据指针算出地址，然后直接访问地址 即使越界也不会报错
    // 所以在使用指针访问数组的时候，只要系统允许访问该内存区域，程序然后可以继续运行 。
    // free(arr);//释放内存

    studyFunction();
    functionTest2();
    return 0;
}

/**
 * 文字列操作関数
 */
int studyFunction()
{

    /**
     * int atoi(char *ptr)  将字符串转换为int类型
     */
    char str1[] = "12345";
    int num = atoi(str1); // 转换字符串为int类型
    printf("使用atoi函数转换字符串为int类型: %d\n", num);

    /**
     *  long atol（char *ptr）将字符串转换为long类型
     */
    long num2 = atol(str1);
    printf("使用atol函数转换字符串为long类型: %ld\n", num2);

    /**
     * double atof(char *ptr) 将字符串转换为double类型
     */
    double num3 = atof(str1);
    printf("使用atof函数转换字符串为double类型: %f\n", num3);

    /**
     * char *strcpy(char *dest, const char *src)  复制字符串
     */

    char str2[] = "Hello, World!";
    char str3[20];
    char *result = strcpy(str3, str2);
    printf("使用strcpy函数复制字符串: %s\n", result);

    /**
     * char *strncpy(char *d, char *s, int n);  复制字符串的前n个字符
     */
    char str11[] = "12345";
    char str12[10];
    strncat(str12, str11, 3); // 复制字符串的前3个字符
    printf("11111111111111111111111111111使用strncat函数复制字符串的前3个字符: %s\n", str12);
    // 字符串变量前不需要加*的情况
    // 1 定义字符串数组 char str[] = "Hello, World!";
    // 2 将字符串名传递给函数  printString(str);

    // 字符串变量前必须加*的情况
    // 1 定义一个指向字符串的指针 char *str = "Hello, World!";
    // 2 引用指针以访问或修改字符串内容的时候   *str = "change";
    // 3 函数参数中，定义一个接受字符串指针的变量 void printString(char *str){...}
    // 4 动态分配内存时，指针存储分配的地址  char *str = (char*)malloc(100);

    /**
     * char *strcat(char *dest, char *a) 连接两个字符串 将a追加到dest的末尾
     */
    // char *str4[20] = "Hello"; 这里报错了 因为 这里试图对一个不可写的字符串常量区进行操作
    // strcat 的第一个参数必须是一个可写的字符数组，并且需要足够的空间容纳追加后的字符串。
    char str4[20] = " World!";
    char *str5 = " World!";
    char *result2 = strcat(str4, str5);
    printf("使用strcat函数连接两个字符串: %s\n", result2);

    // 还有一种字符串连接方式 ，动态分配内存
    char *str6 = "Hello";
    char *str7 = " World!";
    char *result3 = (char *)malloc(strlen(str6) + strlen(str7) + 1); // ·+1是为了留出\0的位置
    if (result3)
    {
        strcpy(result3, str6); // 拷贝str6到result3
        strcat(result3, str7); // 追加
        printf("使用动态内存分配连接字符串: %s\n", result3);
        free(result3); // 释放内存
    }

    // 第三种连接方式  strncat函数  安全的连接两个字符串
    char *result4 = strncat(str4, str5, sizeof(str4) - strlen(str4) - 1); // 保证追加后不会溢出str4的空间
    // sizeof表示str4的总大小（20 字节）包括了存储字符和字符串结束符 \0 所需要的空间。
    // strlen(str4) 表示 str4 中已经使用的字符长度（不包括字符串结束符 \0）。
    printf("使用strncat函数安全的连接两个字符串: %s\n", result4);

    /**
     * 字符串如何从中间插入
     */
    char str8[30] = "Hello, World!";  // 原始字符串
    char insertStr[] = " insertTest"; // 要插入的字符串
    int position = 3;
    int len_str8 = strlen(str8);
    int len_insertStr = strlen(insertStr);

    // 检查空间是否足够
    if (len_str8 + len_insertStr > sizeof(str8))
    {
        printf("字符串空间不足！\n");
        return -1;
    }
    // void *memmove(void *dest, const void *src, size_t n);
    // memmove 用于将内存中从 src 开始的 n 个字节的数据复制到 dest 所指向的内存区域。
    // memmove(insertStr, str8 , position);
    // 移动后面的字符
    // 插入新内容

    /**
     * void *memcpy(void *dest, const void *src, size_t n);  复制内存块
     * memcpy 函数是 C 语言和 C++ 标准库中提供的一个函数，用于将一块内存区域的数据复制到另一块内存区域。
     * dest: 数据复制的目标内存地址（目的地）。
     * src: 数据复制的源内存地址（源头）。
     * n: 复制的字节数。
     * 返回值：返回指向目标内存地址的指针。
     */

    char src_memcpy[] = "Hello, World!";
    char dest_memcpy[20] = "hi, i am zmy/0";

    // 将 src 的内容复制到 dest
    memcpy(&dest_memcpy[3], &src_memcpy[3], 5); // +1 包括 '\0'

    printf("源字符串: %s\n", src_memcpy);
    printf("目标字符串 得出结果 memcpy函数在复制字符串,会覆盖掉目标区域原有的内容 : %s\n", dest_memcpy);

    /**
     * memmove(void *dest, const void *src, size_t n)  移动内存块
     */
    char dest_memmove[30] = "Hello, World!"; // 目标字符串，需预留足够空间
    char src_memmove[] = "INSERTTTT";        // 要插入的字符串
    int insert_pos = 7;                      // 插入位置（索引）

    int dest_len = strlen(dest_memmove); // 目标字符串当前长度
    printf("目标字符串长度: %d\n", dest_len);
    int src_len = strlen(src_memmove); // 插入字符串长度
    printf("插入字符串长度: %d\n", src_len);

    // 检查目标数组空间是否足够
    if (dest_len + src_len + 1 > sizeof(dest_memmove))
    {
        printf("目标空间不足，无法插入！\n");
        return 1;
    }

    // 第一步：使用 memmove 移动目标字符串的内容，腾出插入位置   待补充
    // memmove第一个参数是数据将被拷贝到的位置，第二个参数数据将从这里开始被复制，第三个参数表示从这里开始复制多少字节。
    memmove(&dest_memmove[3], &src_memmove[1], 4);
    printf("目标字符串移动后 待操作补充 字符串不覆盖的去进行插入操作 : %s\n", dest_memmove);

    // // 第二步：将插入字符串复制到目标字符串的插入位置
    // memcpy(&dest_memmove[insert_pos], src_len, src_len);

    // printf("插入后的字符串: %s\n", dest_memmove);

    /**
     * char *strncat(char *s, char *a, int n);
     *连接字符串的前 n 个字符到目标字符串。
     */

    char dest_strncat[20] = "Hello, ";
    char src_strncat[] = "World!";
    strncat(dest_strncat, src_strncat, 3); // 连接a的前3个字符
    printf("strncat部分连接的字符串: %s\n", dest_strncat);

    /**
     * int strcmp(char *s1, char *s2); 比较两个字符串，返回差值。
     */

    char z[] = "apple";
    char y[] = "banam";

    int result_strcmp = strcmp(z, y);
    if (result_strcmp == 0)
        printf("字符串相等\n");
    else if (result_strcmp < 0)
        printf("z 小于 y,strcmp函数一般只用来比较两个字符串是否完全相等,以及字符串长度\n");
    else
        printf("z大于 y\n");

    int result_strncmp = strncmp(z, y, 3);
    if (result_strncmp == 0)
        printf("前3个字符相等\n");
    else
        printf("前3个字符不相等,strncmp函数比较字符串前n个字符是否相等\n");

    /**
     * char *strchr(char *s, int c); 查找字符在字符串中第一次出现的位置之后的字符串
     */
    char s_strchr[] = "Hello, World!";
    char *result_strchr = strchr(s_strchr, 'o');

    if (result_strchr != NULL)
        printf("字符 'o' 首次出现的位置后的所有字符: %s\n", result_strchr);

    /**
     * char *strrchr(char *s, int c); 查找字符在字符串中最后一次出现的位置之前的字符串
     */
    char *strrchr_result = strrchr(s_strchr, 'l');
    if (strrchr_result != NULL)
        printf("字符 'l' 最后出现的位置后的所有字符: %s\n", strrchr_result);

    /**
     * char *strstr(char *haystack, char *needle); 查找字符串在另一个字符串中第一次出现的位置
     */
    char *result_strstr = strstr(s_strchr, "ello");
    printf("查找字符串 'ello' 在字符串中第一次出现的位置后的所有字符: %s\n", result_strstr);

    /**
     *  strtok 函数用来分割字符串
     * char *strtok(char *str, const char *delim);
     * str: 要分割的字符串。
     * delim: 分隔符。
     * 返回值：返回一个指向分割出的子字符串的指针，如果没有更多的子字符串，则返回 NULL。
     */

    char str_strtok[] = "Hello,World,Example";
    char *token = strtok(str_strtok, ",");

    while (token != NULL)
    {
        printf("分割的子字符串: %s\n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}


/**
 * 文件操作相关函数 
 */
int functionTest2 () {
    FILE *fp = fopen("newfile.text", "w");//以写模式打开文件（创建文件）
    if (fp == NULL) {
        printf("文件创建失败。 \n");
        return 1;
    }
    fprintf(fp, "新文件已经创建。 \n");
    fclose(fp);// 关闭文件
    printf("文件已创建。 \n");
    fopen("newfile.text", "r");// 以读模式打开文件
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), fp) != NULL){
        printf("読み取った内容:  %s", buffer);
    }
    
    // 第二次以追加模式打开文件 
    fp = fopen("newfile.text", "a+");
    if (fp == NULL){
        printf("文件打开失败。 \n");
        return 1;
    }

    //写入追加的内容 
    fprintf(fp, "追加的内容，こんにちは、世界！\n");

    //移动文件指针到开头以读取内容 
    rewind(fp);

    //读取并打印文件内容
    while (fgets(buffer, sizeof(buffer), fp) != NULL){
        printf("追加后的内容:  %s", buffer);
    }
    fclose(fp);// 关闭文件

    // wb是以二进制模式
    FILE *fp2 = fopen("binary.dat", "wb");
    int data[5] = {1, 2, 3, 4, 5};
    /**
     * size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
     * ptr: 要写入的数据的指针。
     * size: 单个数据对象的大小。
     * count: 要写入的数据对象的个数。
     * stream: 要写入数据的流。
     * 返回值：返回实际写入的对象个数。
     */
    if (fp2 !=NULL){
        size_t written = fwrite(data, sizeof(int), 5, fp2);// 写入整个数组 
         if (written < 5) {
        perror("写入文件失败");
    } else {
        printf("成功写入了 %zu 个元素。\n", written);
    }
        fclose(fp2);// 关闭文件
    }
    return 0;
}