#include<iostream>
using namespace std;

char p[3072][6144];
void starfractal(int n, int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	// �迭 �ʱ�ȭ *��ǥ���������*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++) // ����
		{
			if (j == 2 * n - 1) p[i][j] = NULL;
			else p[i][j] = ' ';
		}
	}

	starfractal(n, n - 1, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << p[i][j];
		}
		cout << '\n';
	}
	return 0;
}

void starfractal(int n, int x, int y)
{
	if (n == 3)
	{
		p[y][x] = '*'; // ������
		p[y + 1][x - 1] = '*'; // ���� ������ �·� ��ĭ (x-1)
		p[y + 1][x + 1] = '*'; // ���� ������ ��� ��ĭ (x+1)
		p[y + 2][x - 2] = '*'; //  ���� ������ �·� ��ĭ
		p[y + 2][x - 1] = '*'; // ���� ������ �·� ��ĭ
		p[y + 2][x] = '*'; // ���� ������ �״��
		p[y + 2][x + 1] = '*'; // ���� ������ ��� ��ĭ
		p[y + 2][x + 2] = '*'; // ���� ������ ��� ��ĭ
		return; // �ݺ������� ��ͷ� �����ϴµ� ���̻� �ڱ��ڽ� ȣ�����������
	}
	starfractal(n / 2, x, y);
	starfractal(n / 2, x - (n / 2), y + (n / 2));
	starfractal(n / 2, x + (n / 2), y + (n / 2));
}