#include<stdio.h>
#define N 8
int max(int a, int b) 
{
   if(a>b)
   return a;
   else
   return b; 
}
 
int cut(int p[], int n)
{
   if (n <= 0)
     return 0;
   int max_p=0;//赋初值 
   for (int i = 0; i<n; i++) 
         max_p = max(max_p, p[i] + cut(p, n-i-1));
   return max_p;
}
 
int main()
{
    int s[N];
    int i;
    printf("输入对应木棍长度的销售价格：");
    for(i=0;i<N;i++)//循环输入每个木棍长度对应的价格 
    {
	scanf("%d",&s[i]);
    }
    int L= sizeof(s)/sizeof(s[0]);//求数组的长度；为数组总长除一个元素的长度 
    printf("最大销售价值：%d", cut(s, L));
    return 0;
}

