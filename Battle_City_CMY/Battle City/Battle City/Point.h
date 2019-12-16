#ifndef __POINT_H__
#define __POINT_H__

/*In the process of game design, a lot of location information needs to be recorded. 
If only (x, y) coordinates are used, it is easy to make mistakes.
Therefore, two simple data structures are defined to store the information of points and rectangles: Point & Rect*/

/*This header file creates a point class, which has two member variables m_x and m_y to record the horizontal and vertical coordinates of a point. 
A set of public methods are used to assign values to objects and read coordinate values*/
class Point
{
public:
	Point(int x = 0, int y = 0) : m_x(x), m_y(y) {};
	~Point() {};

	/*Here we use the operator overloading function of C++. 
	We overload the "=" function, which is convenient for us to use one point object to assign values to another point object, 
	and also enables us to pass points as parameters*/
	Point& operator=(const Point& p)
	{
		m_x = p.m_x;
		m_y = p.m_y;

		return *this;
	}

	void Set(int x, int y);

	void SetX(int x);
	void SetY(int y);

	int GetX() const;
	int GetY() const;

private:
	int m_x;
	int m_y;
};

#endif