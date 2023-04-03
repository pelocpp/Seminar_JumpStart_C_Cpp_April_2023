#include <iostream>

// textual substitution
#define Maximum 40   // old-fashioned

// C++ 11 and upon
constexpr int Maximum2 = 20;  // new style


void fillArray();

void exercise_01()
{
	fillArray();
}

// Special Libraries: BigInteger
long long faculty(long long n)
{
	int i;
	long long result;

	result = 1;

	for (i = 2; i <= n; i++)
		result *= i;

	return result;
}

void fillArray()
{
	// int n = 20;

	// read value n from console
	// std::cin >> n;

	long long faculties[Maximum];

	for (int i = 0; i < Maximum; ++i) {
		faculties[i] = faculty(i);
	}

	for (int i = 0; i < Maximum; ++i) {
		std::cout << faculties[i] << std::endl;
	}
}

