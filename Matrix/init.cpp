#include "stdafx.h"
#include "Matrix.h"
#include <catch.hpp>

SCENARIO("Matrix init", "[init]") {
	GIVEN("The number of rows and columns") {
		auto rows = 3;
		auto columns = 3;
		WHEN("Create instansce of Matrix") {
			matrix<int> m(rows, columns);
			matrix<int> a;
			THEN("The number of rows and columns must be preserved") {
				REQUIRE(m.get_num_rows() == rows);
				REQUIRE(m.get_num_cols() == columns);
				REQUIRE(a.get_num_rows() == 0);
				REQUIRE(a.get_num_cols() == 0);
			}
		}
	}
}

SCENARIO("Matrix: operator +", "[addition]") {
	matrix<int> A, B, expected;
	A.readFromFile("A2x2.txt");
	B.readFromFile("B2x2.txt");
	expected.readFromFile("A+B.txt");

	matrix<int> result = A + B;
	REQUIRE(result == expected);
}


SCENARIO("Matrix: operator *(matix, number)", "[multiplication]") {
	matrix<int> A, expected;
	A.readFromFile("A2x2.txt");
	expected.readFromFile("A2x2mult2.txt");

	matrix<int> result = A * 2;
	REQUIRE(result == expected);
}

SCENARIO("Matrix: operator *(matix, matrix)", "[multiplication]") {
	matrix<int> A, B, expected;
	A.readFromFile("A2x2.txt");
	B.readFromFile("B2x2.txt");
	expected.readFromFile("AxB.txt");

	matrix<int> result = A * B;
	REQUIRE(result == expected);
}

SCENARIO("Matrix: operator [](i)", "[get row]") {
	matrix<int> A;
	int* a = new int[2]; a[0] = 1; a[1] = 2;
	A.readFromFile("A2x2.txt");

	bool flag = true;
	int* res = A[0];
	for (int j = 0; j < 2; j++) {
		if (a[j] != res[j]) {
			flag = false;
		}
	}
	REQUIRE(flag);
}


SCENARIO("Matrix: get_num_rows()", "[rows number]") {
	matrix<int> A(3, 3);

	REQUIRE(A.get_num_rows() == 3);
}

SCENARIO("Matrix: get_num_cols()", "[columns number]") {
	matrix<int> A(3, 3);

	REQUIRE(A.get_num_cols() == 3);
}
