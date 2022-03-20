#ifndef __GDX_SHAPE_H
#define __GDX_SHAPE_H

#include "../../Maths/Box.h"

namespace GDX
{
	enum ShapeType
	{
		Rectangle,
		Circle
	};

	class Shape
	{
	protected:
		Shape();

	public:
		virtual ~Shape();

		virtual void SetSize(Vec2<int> size);
		virtual void SetSize(Vec2<float> size);

		virtual int GetX() const;
		virtual int GetY() const;
		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual Vec2<int> GetSize() const;

	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;

		Vec2<int> m_size;
	};
}

#endif // __GDX_SHAPE_H

