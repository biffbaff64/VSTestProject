#ifndef __BOX_H
#define __BOX_H

#include "SFML/Graphics.hpp"

#include "GDX/Maths/Vec2.h"

namespace GDX
{
	class Box
	{
	public:
		Box();
		Box(int width, int height);
		Box(int x, int y, int width, int height);
		virtual ~Box() = default;

		void Set(int x, int y, int width, int height);
		void Set(const Box& box);

		[[nodiscard]] bool Contains(int x, int y) const;
		[[nodiscard]] bool Overlaps(const sf::FloatRect& rect) const;
		[[nodiscard]] Vec2Int GetSize() const;

		int m_x;
		int m_y;
		int m_width;
		int m_height;

	private:
		Vec2Int m_size;
	};
}

#endif // __BOX_H
