#ifndef __GDX_IMAGE2D_H
#define __GDX_IMAGE2D_H

#include "../../Maths/Vec2.h"
#include "../Color.h"

namespace GDX
{
	class Drawable2D
	{
	protected:
		Drawable2D() = default;
		~Drawable2D() = default;

	public:
		virtual void create(int width, int height) = 0;
		virtual void create(Vec2<int> size) = 0;
		virtual bool create(char* image_file) = 0;

		int m_width;
		int m_height;

		Color m_color;
	};
}

#endif __GDX_IMAGE2D_H


