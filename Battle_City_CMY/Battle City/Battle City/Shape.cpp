#include "Shape.h"

bool Shape::CheckPointInRect(Point& point, Rect& rect)
{
	if (point.GetX() < rect.GetStartPoint().GetX() || point.GetX() > rect.GetEndPoint().GetX() ||
		point.GetY() < rect.GetStartPoint().GetY() || point.GetY() > rect.GetEndPoint().GetY())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*The method of judging whether two rectangles coincide is very simple, 
as long as the four vertices of the first rectangle are within the range of the second rectangle*/
bool Shape::CheckIntersect(Rect& rectA, Rect& rectB)
{
	Point as = rectA.GetStartPoint();
	Point ae = rectA.GetEndPoint();
	Point at = rectA.GetTRPoint();
	Point ab = rectA.GetBLPoint();
	if (CheckPointInRect(as, rectB) ||
		CheckPointInRect(ae, rectB) ||
		CheckPointInRect(at, rectB) ||
		CheckPointInRect(ab, rectB))
	{
		return true;
	}
	else
	{
		return false;
	}

}
