#include <stdio.h>
#define MAX 10000
int p[MAX+1]; 
int m[MAX][MAX];//�������˵����Ž��
int s[MAX][MAX];//��Ӧm[i][j]�ĶϿ�λ��k��Ϊs[i][j] 
int n;//����ĸ��� 
void juzhen(){
for (int i = 1; i <= n; i++)
    m[i][i] = 0; //��i=jʱ��֤��ֻ��һ�����󣬲��漰������⣬���Գ˻�Ϊ0  
for(int z=2; z<=n; z++) //���������ĳ��ȴ��ڵ���2ʱ,���Խ��о�������  
	{
		for(int i=1; i<=n-z+1; i++)//n-z+1Ϊ���һ��z��ǰ�߽�  
		{
			int j = i+z-1;//����ǰ�߽�Ϊz����Ϊz�ĵĺ�߽�  
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];//��ij����ΪA(i) * ( A[i+1:j] ) 
			s[i][j] = i;
			for(int k=i+1; k<j; k++)
			{
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];//i<j 
                if (t < m[i][j])
                 {
                      m[i][j] = t;
                      s[i][j] = k;
                 }
            }
        }
    }
    	
}

void cixu(int i, int j)
{//����ļ������Ϊ
if(i==j)   //i=j֤��ֻ��һ������ 
printf("A%d",i);
else{
printf("(");
cixu(i,s[i][j]); 
cixu(s[i][j]+1,j);
printf(")");
}
}
int main(){
int i;
printf("�����������˵ľ��������\n");
scanf("%d",&n);
printf("�������������ھ����������������\n") ;
for(i=0;i<n+1;i++)
{
scanf("%d",&p[i]);
}
juzhen();
printf("����������С����Ϊ:\n%d\n",m[1][n]);
printf("����ļ������Ϊ��\n");
cixu(1,n);
printf("\n");
return 0;
}

