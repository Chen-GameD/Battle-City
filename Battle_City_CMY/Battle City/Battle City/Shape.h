#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "Rect.h"

class Shape
{
public:
	/*The CheckPointInRect() function is responsible for determining whether a point is in the range of a rectangle. 
	The CheckIntersect() function is responsible for determining whether two rectangles are coincident*/
	static bool CheckPointInRect(Point& point, Rect& rect);
	static bool CheckIntersect(Rect& rectA, Rect& rectB);
};

#endif