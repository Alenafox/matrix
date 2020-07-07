#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class matrix {   // клас матриця
private:
	int *p_m;
	int n;
public:
	matrix(int count_n);
	matrix(const matrix& m);
	matrix operator+(const matrix my);
	matrix operator-(const matrix my);
	matrix operator*(const matrix my);
	void   operator=(const matrix my);
	void   In_put();
	void   Out_put();
	~matrix();
};

matrix  matrix::operator*(const matrix my)
{
	int my_n = (n*n - n) / 2 + n;
	matrix m_ret(n);
	for (int i = 0; i < my_n; i++)
		m_ret.p_m[i] = p_m[i] * my.p_m[i];
	return m_ret;
};

matrix  matrix::operator+(const matrix my)
{
	int my_n = (n*n - n) / 2 + n;
	matrix m_ret(n);
	for (int i = 0; i < my_n; i++)
		m_ret.p_m[i] = p_m[i] + my.p_m[i];
	return m_ret;
};

matrix  matrix::operator-(const matrix my)
{
	int my_n = (n*n - n) / 2 + n;
	matrix m_ret(n);
	for (int i = 0; i < my_n; i++)
		m_ret.p_m[i] = p_m[i] - my.p_m[i];
	return m_ret;
};

void matrix::operator=(const matrix my)
{
	int my_n = (n*n - n) / 2 + n;
	for (int i = 0; i < my_n; i++)
		p_m[i] = my.p_m[i];
};

matrix::matrix(int count_n)
{
	n = count_n;
	int my_n = (n*n - n) / 2 + n;
	p_m = new int[my_n];
	for (int i = 0; i < my_n; i++)
		p_m[i] = 0;
};

matrix::matrix(const matrix& m) {
	n = m.n;
	int my_n = (n*n - n) / 2 + n;
	p_m = new int[my_n];
	for (int i = 0; i < my_n; i++)
		p_m[i] = m.p_m[i];
};

matrix::~matrix()
{
	delete p_m;
};

void matrix::Out_put()
{
	int y = 0, out_ch = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < y; k++)
		{
			cout.width(4);
			cout << "0";
		}
		for (int j = 0; j < n - y; j++)
		{
			cout.width(4);
			cout << p_m[out_ch];
			out_ch++;
		}
		cout << "\n";
		y++;
	}
};

void matrix::In_put()
{
	int y = 0, in_ch = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - y; j++)
		{
			cout << "[" << i << "," << j << "]: ";
			cin >> p_m[in_ch];
			in_ch++;
		}
		y++;
	}
};

int main()
{
	int size;
	cout << "Matrix [Size]: ";
	cin >> size;
	matrix m1(size), m2(size), m(size);
	cout << "\nMatrix 1: \n";
	m1.In_put();
	cout << "\nMatrix 2: \n";
	m2.In_put();
	m = m1 + m2;
	cout << "\n Matrix 1 + Matrix 2 : \n";
	m.Out_put();
	cout << "\n";
	m = m1 - m2;
	cout << "\n Matrix 1 - Matrix 2 : \n";
	m.Out_put();
	cout << "\n";
	m = m1 * m2;
	cout << "\n Matrix 1 * Matrix 2 :\n";
	m.Out_put();
	cout << "\n";
	return 0;
};
