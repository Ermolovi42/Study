#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <cmath>

class FixedPoint
{
private:
	int16_t m_mant;
	int8_t  m_expo;

public:
	FixedPoint(int16_t mant, int8_t expo) 
		:m_mant(mant), m_expo(expo)
	{ 
		assert(m_expo < 100 && m_expo > -100);

		if (m_mant < 0.0 || m_expo < 0.0)
		{
			if (m_mant > 0.0)
				m_mant = -m_mant;
			if (m_expo > 0.0)
				m_expo = -m_expo;
		}	
	}
	FixedPoint(double num) 
	{ 

		m_mant = static_cast<int16_t>(num); 
		m_expo = static_cast<std::int8_t>(round((num - m_mant) * 100));

		if (m_mant < 0.0 || m_expo < 0.0)
		{
			if (m_mant > 0.0)
				m_mant = -m_mant;
			if (m_expo > 0.0)
				m_expo = -m_expo;
		}	
	}

	operator double() const
	{
		return static_cast<double>(m_mant) + static_cast<double>(m_expo) / 100;
	}
	FixedPoint operator-()
	{
		
		return FixedPoint(- m_mant, -m_expo);
	}

	friend bool operator==(FixedPoint& fp1, FixedPoint& fp2);
	friend std::ostream& operator<<(std::ostream& out, FixedPoint fp);
	friend std::istream& operator>>(std::istream& in, FixedPoint& fp);
	friend FixedPoint operator+(FixedPoint& fp1, FixedPoint& fp2);

};

bool operator==(FixedPoint& fp1, FixedPoint& fp2)
{
	return (fp1.m_mant == fp2.m_mant && fp1.m_expo == fp2.m_expo);
}

std::ostream& operator<<(std::ostream& out, FixedPoint fp)
{
	out << static_cast<double>(fp);
	return out;
}

std::istream& operator>>(std::istream& in, FixedPoint& fp)
{
	double num;
	in >> num;
	fp = FixedPoint(num);
	return in;
}

FixedPoint operator+(FixedPoint& fp1, FixedPoint& fp2)
{
	return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
}

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}

int main()
{
	SomeTest();

	FixedPoint a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';


	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}