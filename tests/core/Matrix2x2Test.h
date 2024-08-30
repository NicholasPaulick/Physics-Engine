#ifndef MATRIX2X2_TEST_H
#define MATRIX2X2_TEST_H

bool approxEqual(double a, double b);

void testMatrix2x2Addition();
void testMatrix2x2Subtraction();
void testMatrix2x2Multiplication();
void testMatrix2x2VectorMultiplication();
void testMatrix2x2Determinant();
void testMatrix2x2Inverse();
void testMatrix2x2Transpose();
void testMatrix2x2Rotation();
void testMatrix2x2Scale();

int testMatrix2x2();

#endif // MATRIX2X2TEST_H