#include <cmath>

class Matrix;

class MatrixForEachCallback
{
public:
	/*! Go through all the elements of the matrix
	 * @param mat the matrix the values are coming from
	 * @param i the index of the element (if the matrix was flattened
	 * @param v the value at index i of the matrix
	 * */
	virtual void run(const Matrix& mat, int i, double v) const {}
};

class Matrix
{
public:
	Matrix(int nr, int nc);
	Matrix(const Matrix& copy);
	~Matrix();

	double get(int i, int j) const;
	void set(int i, int j, double v);
	void print();
	Matrix forEach(const MatrixForEachCallback& callback);

	Matrix operator*(const Matrix& mat) const;


private:

	double* _entries;
	int _nr, _nc;
};

