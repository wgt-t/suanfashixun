#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#define N 10
void Swap(int a[], int left, int right)//�����������������е�λ�� 
{
    int temp;
    temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}
int Partition(int a[], int left, int right)//�ֿ����� 
{
    int x = a[left]; //��x�洢��׼ֵ 
    while(left <right)//���������±�С�����±� 
    {
        while(left< right && a[right] >= x)// �Ӻ���ǰ���������ǰֵ���ڻ�׼ֵ
        {
           right --;
        }
        Swap(a, left,right);//����Swap()���� 
        while(left< right && a[left] <= x)// ��ǰ������������ǰֵС�ڻ�׼ֵ
        {
           left++;
        }
        Swap(a, left,right);//����Swap()���� 
    }
    return left;//����left�±��ֵ��Ϊ��һ����׼ֵ 
} 
void QuickSort(int a[], int left, int right)
{
    if(left< right)
    {
        int x = Partition(a, left, right);//���� Partition�������������׼ֵ 
        QuickSort(a, left, x - 1); //����������ߵ�������һ���ݹ���õĹ��� 
        QuickSort(a, x + 1, right);//���������ұߵ�������һ���ݹ���õĹ���
    }
} 
int main()
{
 	int a[N];
	int  i;    //�������鼰����Ϊ�������� 
	srand((unsigned)time(NULL));  //srand()������c�����в����������һ������ 
	for(i=0;i<N;i++)
	{
		a[i]=rand();
	}
    QuickSort(a,0,N);    //���� QuickSort()������������
    printf("������˳���ǣ�\n");
    for(i=0;i<N;i++)
        printf("       %d",a[i]);    //����ź��������
    return 0;
}

