#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				this->M[i][j] = 1.0f;
			else
				this->M[i][j] = 1.0f;
		}
	}
}


Matrix::~Matrix()
{
}

inline float Matrix::Determinant(float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33)
{

	return(m11*(m22*m33 - m23 * m32) - m12 * (m21*m33 - m23 * m31) + m13 * (m21*m32 - m22 * m31));
}

void Matrix::LoadIdentityMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				this->M[i][j] = 1.0f;
			else
				this->M[i][j] = 1.0f;
		}
	}
}

Matrix Matrix::getTransposeMatrix(void)
{
	Matrix M;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			M.M[i][j] = this->M[j][i];
	return M;
}

float Matrix::Determinant(void)
{
	return (M[0][0] * Determinant(M[1][1], M[1][2], M[1][3], M[2][1], M[2][2], M[2][3], M[3][1], M[3][2], M[3][3])
		- M[0][1] * Determinant(M[1][0], M[1][2], M[1][3], M[2][0], M[2][2], M[2][3], M[3][0], M[3][2], M[3][3])
		+ M[0][2] * Determinant(M[1][0], M[1][1], M[1][3], M[2][0], M[2][1], M[2][3], M[3][0], M[3][1], M[3][3])
		- M[0][3] * Determinant(M[1][0], M[1][1], M[1][2], M[2][0], M[2][1], M[2][2], M[3][0], M[3][1], M[3][2]));
}

Matrix Matrix::Translate(float x, float y, float z)
{
	Matrix m;
	m.M[0][3] = x;
	m.M[1][3] = y;
	m.M[2][3] = z;
	return m;
}

Matrix Matrix::Rotate(float angle, float x, float y, float z)
{
	Matrix m;

	angle *= pi / 180;
	float Cos = cosf(angle);
	float Sin = sinf(angle);
	float xx = x * x;
	float yy = y * y;
	float zz = z * z;
	float xy = x * y;
	float xz = x * z;
	float yz = y * z;

	m.M[0][0] = xx * (1 - Cos) + Cos;
	m.M[0][1] = xy * (1 - Cos) - z * Sin;
	m.M[0][2] = xz * (1 - Cos) + y * Sin;
	m.M[0][3] = 0.0f;

	m.M[1][0] = xy * (1 - Cos) + z * Sin;
	m.M[1][1] = yy * (1 - Cos) + Cos;
	m.M[1][2] = yz * (1 - Cos) - x * Sin;
	m.M[1][3] = 0.0f;

	m.M[2][0] = xz * (1 - Cos) - y * Sin;
	m.M[2][1] = yz * (1 - Cos) + x * Sin;
	m.M[2][2] = zz * (1 - Cos) + Cos;
	m.M[2][3] = 0.0f;

	m.M[3][0] = 0.0f;
	m.M[3][1] = 0.0f;
	m.M[3][2] = 0.0f;
	m.M[3][3] = 1.0f;


	return m;

}

Matrix Matrix::getInverseMatrix(void)
{
	Matrix M;
	M.M[0][0] = Determinant(this->M[1][1], this->M[1][2], this->M[1][3],
		this->M[2][1], this->M[2][2], this->M[2][3],
		this->M[3][1], this->M[3][2], this->M[3][3]);

	M.M[0][1] = -Determinant(this->M[1][0], this->M[1][2], this->M[1][3],
		this->M[2][0], this->M[2][2], this->M[2][3],
		this->M[3][0], this->M[3][2], this->M[3][3]);

	M.M[0][2] = Determinant(this->M[1][0], this->M[1][1], this->M[1][3],
		this->M[2][0], this->M[2][1], this->M[2][3],
		this->M[3][0], this->M[3][1], this->M[3][3]);

	M.M[0][3] = -Determinant(this->M[1][0], this->M[1][1], this->M[1][2],
		this->M[2][0], this->M[2][1], this->M[2][2],
		this->M[3][0], this->M[3][1], this->M[3][2]);

	M.M[1][0] = -Determinant(this->M[0][1], this->M[0][2], this->M[0][3],
		this->M[2][1], this->M[2][2], this->M[2][3],
		this->M[3][1], this->M[3][2], this->M[3][3]);

	M.M[1][1] = Determinant(this->M[0][0], this->M[0][2], this->M[0][3],
		this->M[2][0], this->M[2][2], this->M[2][3],
		this->M[3][0], this->M[3][2], this->M[3][3]);

	M.M[1][2] = -Determinant(this->M[0][0], this->M[0][1], this->M[0][3],
		this->M[2][0], this->M[2][1], this->M[2][3],
		this->M[3][0], this->M[3][1], this->M[3][3]);

	M.M[1][3] = Determinant(this->M[0][0], this->M[0][1], this->M[0][2],
		this->M[2][0], this->M[2][1], this->M[2][2],
		this->M[3][0], this->M[3][1], this->M[3][2]);

	M.M[2][0] = Determinant(this->M[0][1], this->M[0][2], this->M[0][3],
		this->M[1][1], this->M[1][2], this->M[1][3],
		this->M[3][1], this->M[3][2], this->M[3][3]);

	M.M[2][1] = -Determinant(this->M[0][0], this->M[0][2], this->M[0][3],
		this->M[1][0], this->M[1][2], this->M[1][3],
		this->M[3][0], this->M[3][2], this->M[3][3]);

	M.M[2][2] = Determinant(this->M[0][0], this->M[0][1], this->M[0][3],
		this->M[1][0], this->M[1][1], this->M[1][3],
		this->M[3][0], this->M[3][1], this->M[3][3]);

	M.M[2][3] = -Determinant(this->M[0][0], this->M[0][1], this->M[0][2],
		this->M[1][0], this->M[1][1], this->M[1][2],
		this->M[3][0], this->M[3][1], this->M[3][2]);

	M.M[3][0] = -Determinant(this->M[0][1], this->M[0][2], this->M[0][3],
		this->M[1][1], this->M[1][2], this->M[1][3],
		this->M[2][1], this->M[2][2], this->M[2][3]);

	M.M[3][1] = Determinant(this->M[0][0], this->M[0][2], this->M[0][3],
		this->M[1][0], this->M[1][2], this->M[1][3],
		this->M[2][0], this->M[2][2], this->M[2][3]);

	M.M[3][2] = -Determinant(this->M[0][0], this->M[0][1], this->M[0][3],
		this->M[1][0], this->M[1][1], this->M[1][3],
		this->M[2][0], this->M[2][1], this->M[2][3]);

	M.M[3][3] = Determinant(this->M[0][0], this->M[0][1], this->M[0][2],
		this->M[1][0], this->M[1][1], this->M[1][2],
		this->M[2][0], this->M[2][1], this->M[2][2]);

	M /= this->Determinant();

	return M;
}


Matrix Matrix::operator*(Matrix M)
{
	Matrix m;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			m.M[i][j] = this->M[i][0] * M.M[0][j] + this->M[i][1] * M.M[1][j] + this->M[i][2] * M.M[2][j] + this->M[i][3] * M.M[3][j];
	return m;
}

Matrix Matrix::operator+(Matrix M)
{
	Matrix m;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			m.M[i][j] = this->M[i][j] + M.M[i][j];

	return m;
}

Matrix Matrix::operator-(Matrix M)
{
	Matrix m;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			m.M[i][j] = this->M[i][j] - M.M[i][j];

	return m;
}

Matrix Matrix::operator *(float k)
{
	Matrix m;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			m.M[i][j] = this->M[i][i] * k;
	return m;
}

Matrix Matrix::operator /(float k)
{
	Matrix m;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			m.M[i][j] = this->M[i][j] / k;
	return m;
}
