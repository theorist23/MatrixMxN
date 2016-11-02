#include <iostream>
#include <vector>

using namespace std;

class VectorND
{
public:
	int n;
	int *num;
	VectorND(int components)
	{
		n = components;
		num = new int[n];
		for (int i = 0;i < n;i++)
		{
			num[i] = rand() / (RAND_MAX / 10);
		}
	}

	VectorND()
	{
		n = 1;
		num = new int;
		*num = 1;
	}

	friend ostream& operator << (ostream& os, const VectorND& dt)
	{
		for (int i = 0;i < dt.n;i++)
		{
			printf("  %-2d", dt.num[i]);
		}
		cout << endl;
		return os;
	}

	VectorND& operator+(VectorND a)
	{
		VectorND output(a.n);
		for (int i = 0;i < output.n; i++)
			output.num[i] = this->num[i] + a.num[i];
		return output;
	}
	//VectorND& operator*(MatrixMxN a)		//º¤ÅÍ ÇÏ³ª¸¦ ÇÏ³ªÀÇ ÇàÀ¸·Î ºÃÀ» ¶§ÀÇ °ö¼À
	//{
	//	VectorND output;
	//	int temp = 0;
	//	for (int k = 0; k < this->n; k++)
	//	{
	//		temp += this->num[k] * a.vec[k].num[0];
	//	}
	//	output.num[0] = temp;
	//	return output;
	//}
};

class MatrixMxN
{
public:
	int m, n;
	VectorND *vec;
	MatrixMxN(int rows, int columns)
	{
		m = rows;
		n = columns;
		vec = new VectorND[m];
		for (int i = 0;i < m;i++)
		{
			vec[i] = VectorND(n);
		}
	}
	MatrixMxN()
	{
		m = 1;
		n = 1;
		vec = new VectorND;
		*vec = VectorND(n);
	}

	friend ostream& operator << (std::ostream& os, const MatrixMxN& dt)
	{
		for (int i = 0;i < dt.m;i++)
		{
			for (int j = 0;j < dt.n;j++)
			{
				printf("  %-2d", dt.vec[i].num[j]);
			}
			cout << endl;
		}
		return os;
	}

	MatrixMxN& operator+(MatrixMxN a)
	{
		MatrixMxN output(this->m, a.n);
		for (int i = 0;i < output.m; i++)
		{
			for (int j = 0; j < output.n; j++)
			{
				output.vec[i].num[j] = this->vec[i].num[j] + a.vec[i].num[j];
			}
		}
		return output;
	}

	MatrixMxN& operator*(MatrixMxN a)
	{
		MatrixMxN output(this->m, a.n);
		for (int i = 0;i < output.m; i++)
		{
			for (int j = 0; j < output.n; j++)
			{
				int temp = 0;
				for (int k = 0; k < this->n; k++)
				{
					temp += this->vec[i].num[k] * a.vec[k].num[j];
				}
				output.vec[i].num[j] = temp;
			}
		}
		return output;
	}
	//MatrixMxN& operator*(VectorND a)		//º¤ÅÍ ÇÏ³ª¸¦ ÇÏ³ªÀÇ ÇàÀ¸·Î ºÃÀ» ¶§ÀÇ °ö¼À
	//{
	//	MatrixMxN output(this->m, a.n);
	//	for (int i = 0;i < output.m; i++)
	//	{
	//		for (int j = 0; j < output.n; j++)
	//		{
	//			int temp = 0;
	//			for (int k = 0; k < this->n; k++)
	//			{
	//				temp += this->vec[i].num[k] * a.num[j];
	//			}
	//			output.vec[i].num[j] = temp;
	//		}
	//	}
	//	return output;
	//}
	VectorND& operator*(VectorND a)		//º¤ÅÍ ÇÏ³ª¸¦ ÇÏ³ªÀÇ ¿­·Î ºÃÀ» ¶§ÀÇ °ö¼À
	{
		VectorND output(this->m);
		for (int i = 0;i < this->m; i++)
		{

			int temp = 0;
			for (int k = 0; k < this->n; k++)
			{
				temp += this->vec[i].num[k] * a.num[k];
			}
			output.num[i] = temp;
		}
		return output;
	}
};

int main()
{
	//VectorND a(7), b(5), c;
	//b = VectorND(7);
	//c = a + b;
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	//cout << endl;

	//MatrixMxN z(5, 4), y(4, 5), x, w(5, 4), v(4, 1), u;
	//y = MatrixMxN(4, 3);
	//u = z + w;
	//x = z * y;
	//cout << z << endl;
	//cout << y << endl;
	//cout << u << endl;
	//cout << x << endl;

	MatrixMxN t(5, 4);
	VectorND d(4), e;
	e = t * d;
	cout << t << endl;
	cout << d << endl;
	cout << e << endl;

	return 0;
}