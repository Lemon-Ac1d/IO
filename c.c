#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int a[1010];
char s[1010];
// 计算一个整数的逆序数
int merge_sort(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    int res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    int tmp[1010];
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
        {
            res += mid - i + 1;
            // printf("%d %d\n", a[i], a[j]);
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];

    for (int i = l, j = 0; j < k;)
        a[i++] = tmp[j++];
    return res;
}

// 生成随机数
int get_random_number(int max_num)
{
    return rand() % max_num + 1;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    // 计算自己学号的逆序数
    
    int id = 20416323; 
    int old = id;
    for(int i = 7; i >= 0; i--){
        a[i] = id % 10;
        id /= 10;
    }  
    
    printf("学号 %d 的逆序数是: %d\n", old,merge_sort(0, 7));
    puts("");
    // 生成100个随机数，并计算它们的逆序数
    printf("从1到1000里随机有房蝴蝶挑选的100个数是\n");
    for (int i = 0; i < 100; i++)
    {
        a[i] = get_random_number(1000);
        if((i+1) % 20 == 0)  puts("");
        printf("%d ", a[i]);
    }
    printf("\n从1到1000里随机有放回的挑选的100个数的逆序数是: %d\n", merge_sort(0, 99));
    puts("");

    // 从文件中读取数列，并计算它们的逆序数
    FILE *fp ;
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("打开 %s 文件失败\n", argv[1]);
        return 1;
    }
    
    printf("file文件中的数列是: ");
    int num, n = 0;
    while (fscanf(fp, "%d", &num) == 1)
    {
        a[n++] = num;
        printf("%d ", num);
    }
    printf("\t逆序数是%d", merge_sort(0,n));

    fclose(fp);

    return 0;
}