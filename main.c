#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成一个随机数组
void random_array(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

// 打印数组
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 返回数组最大值
// TODO: 修改并实现所需功能
int max_element(int a[], int n)
{
    return 0;
}

// 对数组按照递增顺序排序
// TODO: 修改并实现所需功能
void sort_ascending(int a[], int n)
{

}

// 根据用户传入的比较函数comp对数组进行排序，
// 如果comp(a, b) > 0，则a排在后面
// TODO: 修改并实现所需功能
void sort(int a[], int n, int (*comp)(const int, const int))
{
}

// 比较函数
int greater_than(int x, int y)
{
    return x - y;
}

int less_than(int x, int y)
{
    return y - x;
}


#define N 10

int main() 
{
    int a[N];

    random_array(a, N);
    print_array(a, N);

    printf("Max value of a: %d\n", max_element(a, N));

    sort_ascending(a, N);
    print_array(a, N);

    sort(a, N, greater_than);
    print_array(a, N);


    sort(a, N, less_than);
    print_array(a, N);

    return 0;
}

