#include<stdio.h>
#include<string.h>
#define N 10
//����ȫ�ֱ��� 
int a[N];//����ΪN������ 
int t=1;//t��ֵΪ1 
int n;//��һ������������һ���� 
void back(){
 memset(a,0,sizeof(a)); //�Ȱ�������г�ʼ��  
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
	printf("�����������������һλ����"); 
    scanf("%d",&n);
    back();
    return 0;
}

