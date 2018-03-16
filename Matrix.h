#pragma once
#include <cmath>

#define pi 3.14159265

class Matrix
{
public:
	Matrix();
	~Matrix();

	int M[4][4];
	void LoadIdentityMatrix(void);
	Matrix getInverseMatrix(void);
	Matrix getTransposeMatrix(void);
	float Determinant(void);
	Matrix Translate(float x, float y, float z);
	Matrix Rotate(float angle, float x, float y, float z);

	Matrix operator * (Matrix M);
	Matrix operator + (Matrix M);
	Matrix operator - (Matrix M);
	Matrix operator * (float k);
	Matrix operator / (float k);
	void operator *= (Matrix M) { *this = *this*M; }
	void operator += (Matrix M) { *this = *this + M; }
	void operator -= (Matrix M) { *this = *this - M; }
	void operator *= (float k) { *this = *this*k; }
	void operator /= (float k) { *this = *this / k; }


private:
	inline float Determinant(float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33);

};

