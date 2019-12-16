#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <list>

#include "Graphic.h"

using namespace std;

enum Dir { UP, DOWN, LEFT, RIGHT };

/*Object class as the base class of all classes in future programs*/
class Object
{
public:
	// Mapping
	virtual void Display() = 0;

	// Move
	virtual void Move() = 0;

	// Boom :Explosion effect of bullets and tanks
	/*This function is used to create a new Object object and add it to the list passed in. 
	The function of this method is the same as that of shot function.*/
	virtual void Boom(list<Object*>& lstBombs) = 0;

	// Set disappear
	virtual void SetDisappear() = 0;

	// Judge whether it disappears
	virtual bool IsDisappear() = 0;

	virtual Rect GetSphere() = 0;

protected:
	// Calculate sphere of influence
	virtual void CalculateSphere() = 0;

	// Position
	Point m_pos;

	// Sphere of influence
	Rect m_rectSphere;

	// Colour
	COLORREF m_color;
	// Direction
	Dir m_dir;
	// Existence state
	bool m_bDisappear;
	// Single step forward
	int m_step;
};

#endif