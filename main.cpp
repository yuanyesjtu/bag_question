#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
	/*读入总钱数与总商品数*/
	int M, Q;
	cout << "Please input Money and Quantity: " << endl;
	cin >> M >> Q;
	M++; // 使用的钱数有0~M，总共M+1种情况
	Q++;

	/*随机生成每件商品的价格与价值*/
	double* value = new double[Q];
	int* price = new int[Q];
	for (size_t i = 1; i < Q; i++)
	{
		value[i] = rand() % 10 / 10.0; // 每件商品的价值用0~1的浮点数表示（此处不使用随机数种子，每次产生的随机数相同）
		price[i] = rand() % 5 + 1;     // 每件商品的价值用1~6的整数表示
	}

	/*输出每件商品的价格*/
	cout << endl << "price:" << endl;
	for (size_t i = 1; i < Q; i++)
		cout << setw(4) << setfill(' ') << price[i] << ",";

	/*输出每件商品的价值*/
	cout << endl << endl << "value:" << endl;
	for (size_t i = 1; i < Q; i++)
		cout << setw(4) << setfill(' ') << value[i] << ",";

	/*创建总价值矩阵*/
	double** t_value = new double* [Q]; // 创建总价值矩阵，使用j元购买i件商品，i件商品总价值为total_value[i][j]
	for (size_t i = 0; i < Q; i++)
		t_value[i] = new double[M];

	for (size_t i = 0; i < Q; i++) // 初始化总价值为0
		for (size_t j = 0; j < M; j++)
			t_value[i][j] = 0;

	/*开始动态规划*/
	for (size_t i = 1; i < Q; i++)
	{
		for (size_t j = price[i]; j < M; j++)
		{
			t_value[i][j] = t_value[i - 1][j] > t_value[i - 1][j - price[i]] + value[i] ?
				t_value[i - 1][j] : t_value[i - 1][j - price[i]] + value[i];
		}
	}

	/*输出总价值矩阵*/
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