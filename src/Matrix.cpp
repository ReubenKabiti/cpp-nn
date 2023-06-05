#include "Matrix.h"
#include <iostream>
#include <string.h>

Matrix::Matrix(int nr, int nc)
{
	_entries = new double[nr * nc];
	_nr = nr;
	_nc = nc;
}

Matrix::Matrix(const Matrix& copy)
{
	_nr = copy._nr;
	_nc = copy._nc;
	_entries = new double[_nr * _nc];
	memcpy(_entries, copy._entries, _nr * _nc);
}

Matrix::~Matrix()
{
	delete _entries;
}


double Matrix::get(int i, int j) const
{
	int index = _nr * i + j;
	return _entries[index];
}

void Matrix::set(int i, int j, double v)
{
	int index = _nr * i + j;
	_entries[index] = v;
}

Matrix Matrix::operator*(const Matrix& mat) const
{
	Matrix out(_nr, mat._nc);

	// highschool matrix multiplication
	for (int i = 0; i < out._nr; i ++)
	{
		for (int j = 0; j < out._nc; j++)
		{
			double ans = 0;
			for (int k = 0; k < _nc; k++)
				ans += get(i, k) * mat.get(k, j);
			out.set(i, j, ans);
		}
	}
	return out;
}


void Matrix::print()
{
	for (int i = 0; i < _nr; i++)
	{
		for (int j = 0; j < _nc; j++)
		{
			std::cout << get(i, j) << ' ';
		}
		std::cout << std::endl;
	}
}

Matrix Matrix::forEach(const MatrixForEachCallback& callback)
{
	Matrix out = Matrix(*this);
	for (int i = 0; i < _nr * _nc; i++)
	{
		callback.run(out, i, out._entries[i]);
	}
	return out;
}

