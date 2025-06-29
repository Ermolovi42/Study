#include <iostream>
#include <limits>
#include <vector>

class Shape
{
public:

    virtual std::ostream& print(std::ostream& out) = 0;

    friend std::ostream& operator<<(std::ostream& out, Shape& shape)
    {
        shape.print(out);
		return out;
    }

    virtual ~Shape() = default;

};

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};


class Triangle : public Shape
{
private:
	Point m_x;
	Point m_y;
	Point m_z;

public:
	Triangle (Point x, Point y, Point z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	virtual std::ostream& print(std::ostream& out) override
	{
		out << "Triangle(" << Point(1, 2, 3) << Point(4, 5, 6) << Point(7, 8, 9) << ")" << std::endl;
		return out;
	}
					
};

class Circle: public Shape
{
private:
	Point m_o;
	int m_r;


public:
	Circle(Point o, int r)
		: m_o(o), m_r(r)
	{

	}

	virtual std::ostream& print(std::ostream& out) override
	{
		out << "Circle(" << Point(1, 2, 3) << "radius" << m_r << ")";
		return out;
	}

	int getRud() const
	{
		return m_r;
	}

};

int  getLargestRadius(std::vector<Shape*> &v)
{
	int Largest = 0;
	for (auto& const shape : v)
	{
		if (Circle* c = dynamic_cast<Circle*>(shape))
		{
			if (c->getRud() > Largest)
				Largest = c->getRud();
		}
	}
	return Largest;

}

int main()
{


	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	for (Shape*& const shape : v)
	{
		std::cout << *shape << '\n';

	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

	// Удаление элементов вектора v здесь

	


	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}