#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#define N 10
void Swap(int a[], int left, int right)//交换两个数在数组中的位置 
{
    int temp;
    temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}
int Partition(int a[], int left, int right)//分开遍历 
{
    int x = a[left]; //用x存储基准值 
    while(left <right)//需满足左下标小于右下标 
    {
        while(left< right && a[right] >= x)// 从后往前遍历如果当前值大于基准值
        {
           right --;
        }
        Swap(a, left,right);//调用Swap()函数 
        while(left< right && a[left] <= x)// 从前往后遍历如果当前值小于基准值
        {
           left++;
        }
        Swap(a, left,right);//调用Swap()函数 
    }
    return left;//返回left下标的值作为下一个基准值 
} 
void QuickSort(int a[], int left, int right)
{
    if(left< right)
    {
        int x = Partition(a, left, right);//调用 Partition（）函数定义基准值 
        QuickSort(a, left, x - 1); //继续处理左边的数，是一个递归调用的过程 
        QuickSort(a, x + 1, right);//继续处理右边的数，是一个递归调用的过程
    }
} 
int main()
{
 	int a[N];
	int  i;    //定义数组及变量为基本整型 
	srand((unsigned)time(NULL));  //srand()函数是c语言中产生随机数的一个函数 
	for(i=0;i<N;i++)
	{
		a[i]=rand();
	}
    QuickSort(a,0,N);    //调用 QuickSort()函数进行排序
    printf("排序后的顺序是：\n");
    for(i=0;i<N;i++)
        printf("       %d",a[i]);    //输出排好序的数组
    return 0;
}

