#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
	/*������Ǯ��������Ʒ��*/
	int M, Q;
	cout << "Please input Money and Quantity: " << endl;
	cin >> M >> Q;
	M++; // ʹ�õ�Ǯ����0~M���ܹ�M+1�����
	Q++;

	/*�������ÿ����Ʒ�ļ۸����ֵ*/
	double* value = new double[Q];
	int* price = new int[Q];
	for (size_t i = 1; i < Q; i++)
	{
		value[i] = rand() % 10 / 10.0; // ÿ����Ʒ�ļ�ֵ��0~1�ĸ�������ʾ���˴���ʹ����������ӣ�ÿ�β������������ͬ��
		price[i] = rand() % 5 + 1;     // ÿ����Ʒ�ļ�ֵ��1~6��������ʾ
	}

	/*���ÿ����Ʒ�ļ۸�*/
	cout << endl << "price:" << endl;
	for (size_t i = 1; i < Q; i++)
		cout << setw(4) << setfill(' ') << price[i] << ",";

	/*���ÿ����Ʒ�ļ�ֵ*/
	cout << endl << endl << "value:" << endl;
	for (size_t i = 1; i < Q; i++)
		cout << setw(4) << setfill(' ') << value[i] << ",";

	/*�����ܼ�ֵ����*/
	double** t_value = new double* [Q]; // �����ܼ�ֵ����ʹ��jԪ����i����Ʒ��i����Ʒ�ܼ�ֵΪtotal_value[i][j]
	for (size_t i = 0; i < Q; i++)
		t_value[i] = new double[M];

	for (size_t i = 0; i < Q; i++) // ��ʼ���ܼ�ֵΪ0
		for (size_t j = 0; j < M; j++)
			t_value[i][j] = 0;

	/*��ʼ��̬�滮*/
	for (size_t i = 1; i < Q; i++)
	{
		for (size_t j = price[i]; j < M; j++)
		{
			t_value[i][j] = t_value[i - 1][j] > t_value[i - 1][j - price[i]] + value[i] ?
				t_value[i - 1][j] : t_value[i - 1][j - price[i]] + value[i];
		}
	}

	/*����ܼ�ֵ����*/
	cout << endl << endl << "t_value:" << endl;
	for (size_t i = 0; i < Q; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cout << setw(4) << setfill(' ') << t_value[i][j] << ",";
		}
		cout << endl;
	}

	return 0;
}