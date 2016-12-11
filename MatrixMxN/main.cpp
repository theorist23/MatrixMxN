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
			num[i] = rand() / (RAND_MAX / 10);
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
			printf("  %-3d\n", dt.num[i]);
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
		vec = new VectorND[n];
		for (int i = 0;i < n;i++)
			vec[i] = VectorND(m);
	}
	MatrixMxN()
	{
		m = 1;
		n = 1;
		vec = new VectorND;
		*vec = VectorND(m);
	}

	friend ostream& operator << (std::ostream& os, const MatrixMxN& dt)
	{
		for (int i = 0;i < dt.m;i++)
		{
			for (int j = 0;j < dt.n;j++)
				printf("  %-3d", dt.vec[j].num[i]);
			cout << endl;
		}
		return os;
	}

	MatrixMxN& operator+(MatrixMxN a)
	{
		MatrixMxN output(this->m, a.n);
		for (int i = 0;i < output.m; i++)
			for (int j = 0; j < output.n; j++)
				output.vec[j].num[i] = this->vec[j].num[i] + a.vec[j].num[i];
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
					temp += this->vec[k].num[i] * a.vec[j].num[k];
				output.vec[j].num[i] = temp;
			}
		}
		return output;
	}
	VectorND& operator*(VectorND a)
	{
		VectorND output(this->m);
		for (int i = 0;i < this->m; i++)
		{
			int temp = 0;
			for (int k = 0; k < this->n; k++)
				temp += this->vec[k].num[i] * a.num[k];
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

	MatrixMxN t(5, 4), s(4, 2), z;
	VectorND d(4), e;
	e = t * d;
	z = t * s;
	cout << t << endl;
	cout << s << endl;
	cout << e << endl;
	cout << z << endl;
	return 0;
}