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
   int max_p=0;//����ֵ 
   for (int i = 0; i<n; i++) 
         max_p = max(max_p, p[i] + cut(p, n-i-1));
   return max_p;
}
 
int main()
{
    int s[N];
    int i;
    printf("�����Ӧľ�����ȵ����ۼ۸�");
    for(i=0;i<N;i++)//ѭ������ÿ��ľ�����ȶ�Ӧ�ļ۸� 
    {
	scanf("%d",&s[i]);
    }
    int L= sizeof(s)/sizeof(s[0]);//������ĳ��ȣ�Ϊ�����ܳ���һ��Ԫ�صĳ��� 
    printf("������ۼ�ֵ��%d", cut(s, L));
    return 0;
}

