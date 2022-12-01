#pragma once

struct Vec2 {
	float x;
	float y;
};

struct Matrix2x2
{
	float m1[2][2];
};

struct Matrix3x3
{
	float m2[3][3];
};

Matrix2x2 Inverse(Matrix2x2 matrix);

Matrix3x3 Inverse(Matrix3x3 matrix);

static const int kRowHeight = 30;
static const int kColumnWidth = 54;

//	s—ñ‚Ì•`‰æ
void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix);
void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix);