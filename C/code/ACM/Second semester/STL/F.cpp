#include <stdio.h>
#define MAXN 20

int n = 4, W = 31;
int w[] = {0, 11, 13, 24, 7}; // ���������������Ҫ�±�Ϊ0��Ԫ��
int count = 0;                // �ۼƽ����
void dispsolution(int x[])
{
    int i;
    printf("��%d����:\n", ++count);
    for (int i = 1; i <= n; i++)
        if (x[i] == 1)
            printf("%d ", w[i]);
    printf("\n");
}
void dfs(int tw, int rw, int x[], int i) // ����Ӽ���
{
    // tw ���ǵ�i������ʱѡȡ�������ͣ�rwΪʣ�µ�������
    if (i > n) // �ҵ�һ��Ҷ�ӽ��
    {
        if (tw == W) // �ҵ�һ�����������Ľ����
            dispsolution(x);
    }
    else // ��δ������������
    {
        if (tw + w[i] <= W) // ���ӽ���֦��ѡȡ��������������w[i]
        {
            x[i] = 1; // ѡȡ��i������
            dfs(tw + w[i], rw - w[i], x, i + 1);
        }
        if (tw + rw > W) // �Һ��ӽ���֦�����������ܴ��ڽ�Ľ��
        {
            x[i] = 0; // ��ѡȡ��i������������
            dfs(tw, rw - w[i], x, i + 1);
        }
    }
}
int main()
{
    int x[MAXN]; // ���һ��������
    int rw = 0;
    for (int j = 1; j <= n; j++) // ������������
        rw += w[j];
    dfs(0, rw, x, 1); // i��1��ʼ
}
