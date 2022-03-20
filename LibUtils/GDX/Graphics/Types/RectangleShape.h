#ifndef __RECTANGLE_SHAPE_H
#define __RECTANGLE_SHAPE_H

#include <GDX/Maths/Box.h>
#include <GDX/Maths/Vec2.h>

#include "Shape.h"

namespace GDX
{
	/// @brief Rectangle DRAWABLE shape, as opposed
	/// to the Maths Rectangle and Box classes.
	class RectangleShape : public Shape
	{
	public:
		RectangleShape();
		explicit RectangleShape(const Vec2<int>& size = Vec2<int>(0, 0));
		RectangleShape(const Box& box);
	};
}

#endif // __RECTANGLE_SHAPE_H

