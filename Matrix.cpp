#include "Matrix.h"
#include <Novice.h>

Matrix2x2 Transpose(Matrix2x2 matrix) {
	Matrix2x2 result;
	result.m1[0][0] = matrix.m1[0][0];
	result.m1[0][1] = matrix.m1[1][0];
	result.m1[1][0] = matrix.m1[0][1];
	result.m1[1][1] = matrix.m1[1][1];

	return result;
}

Matrix3x3 Transpose(Matrix3x3 matrix) {
	Matrix3x3 result;
	result.m2[0][0] = matrix.m2[0][0];
	result.m2[0][1] = matrix.m2[1][0];
	result.m2[0][2] = matrix.m2[2][0];

	result.m2[1][0] = matrix.m2[0][1];
	result.m2[1][1] = matrix.m2[1][1];
	result.m2[1][2] = matrix.m2[2][1];

	result.m2[2][0] = matrix.m2[0][2];
	result.m2[2][1] = matrix.m2[1][2];
	result.m2[2][2] = matrix.m2[2][2];

	return result;
}

//	çsóÒÇÃï`âÊ
void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix) {
	for (int row = 0; row < 2; ++row)
	{
		for (int column = 0; column < 2; ++column)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m1[row][column]);
		}
	}
}

void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix) {
	for (int row = 0; row < 3; ++row)
	{
		for (int column = 0; column < 3; ++column)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m2[row][column]);
		}
	}
}