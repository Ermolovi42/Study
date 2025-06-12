#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <array>  
#include <ctime>
#include <cstdlib>
#include <functional>

#define MAX_CIN 32767

typedef int (*arithmeticFnc)(int, int);

inline void getNum(int& num)
{
	std::cin >> num;

	std::cin.clear();
	std::cin.ignore(MAX_CIN, '\n');
}

inline void getOperetion(std::string* op)
{

	do
	{
		std::cout << "enter the operation :";
		std::cin >> *op;


	} while (*op != "*" && *op != "/" && *op != "+" && *op != "-");
}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

struct arithmetic
{
	std::string oper;
	arithmeticFnc  fncPtr;
};

static std::array<arithmetic, 4> arithmeticArray 
{ {
	{"+",  add},
	{"-",  subtract},
	{"/", divide },
	{"*", multiply }
}};

arithmeticFnc getArithmeticFnc(std::string op)
{
	for (const auto whyOp : arithmeticArray)
	{
		if (whyOp.oper == op)
		{
			return whyOp.fncPtr;
		}
	}
	return add; 
}

int calculation(int num1, int num2, arithmeticFnc fncPtr)
{
	return fncPtr(num1, num2);
}



int main()
{
	int num1;
	std::cout << "enter the num 1 :";
	getNum(num1);

	int num2;
	std::cout << "enter the num 2 :";
	getNum(num2);

	std::string op;
	getOperetion(&op);
	arithmeticFnc fncPtr{ getArithmeticFnc(op) };

	std::cout << calculation(num1, num2, fncPtr);

	return 0;
}
