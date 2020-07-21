#include<stdio.h>
#define N 4	//物品的个数
#define W 5//背包容量
int D[N][W] = {0};//初始化动态规划表 
int w[5] ;	//物品重量
int val[5];//物品价值
void beibao()
{
	int k;	//第K个物品
	int C;	//背包剩余重量
	//运用循环来填写动态规划表 
	for (k = 0; k <N; k++)
	{
		for (C = 0; C<=W; C++)
		{
			if (w[k] > C)//第k件物品放不进去 此时背包的价值 = 判断完上一件物品之后背包的价值
			{
				D[k][C] = D[k - 1][C];
			}
			else
			{
				int val1 = D[k - 1][C - w[k]] + val[k];	 //放入第k件物品后 背包总价值 = 剩余的背包大小能装进的最大价值 + 这件物品的价值
				int val2 = D[k - 1][C];	//不放入第k件物品 背包总价值 = 当前背包大小能装进的最大价值(就是判断完上一件物品之后背包的价值)
				if (val1 > val2)
				{
					D[k][C] = val1;
				}
				else
				{
					D[k][C] = val2;
					if (val1 < val2)
					printf("k=%d C=%d\n", k, C);
				}
			}
		}
	}
}
int main()
{
	int i,j;
	printf("输入物品的重量："); //循环输入物品的重量与价值 
	for(i=0;i<N;i++){
	scanf("%d",&w[i]);
    }
	printf("输入物品的价值：");
	for(i=0;i<N;i++)
	{
	scanf("%d",&val[i]);
    }
	beibao();//调用函数 
	for (i = 0; i <N; i++)//输出动态规划表 
	{
		for ( j = 0; j <= W; j++)
		{
			printf("%2d ", D[i][j]);
		}
		printf("\n");
	}

}
