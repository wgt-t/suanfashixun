#include<stdio.h>
#include<string.h>
#define N 10
//定义全局变量 
int a[N];//长度为N的数组 
int t=1;//t赋值为1 
int n;//这一串数字中最大的一个数 
void back(){
 memset(a,0,sizeof(a)); //先把数组进行初始化  
while(t!=0)
{ 
if(a[t]<n)
{
  a[t]=a[t]+1;
  if(a[t]<=n)
  {
  if(t==n)
  {
  for(int i=1;i<=n;i++)
  printf("%d",a[i]);
  printf("\n");
  }
else 
 t++;
  }
}
else  
{
a[t]=0;
t--;
} 
}
}
int main(){
	printf("输入有序数组中最后一位数："); 
    scanf("%d",&n);
    back();
    return 0;
}

