#include "Rectangle.h"

namespace GDX
{
	template <typename T>
	Rectangle<T>::Rectangle()
		:
		m_x(0),
		m_y(0),
		m_width(0),
		m_height(0)
	{
	}

	template <typename T>
	Rectangle<T>::Rectangle(T x, T y, T width, T height)
		:
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height)
	{
	}

	template <typename T>
	bool Rectangle<T>::Contains(T x, T y) const
	{
		return (m_x <= x) && ((m_x + m_width) >= x)
			&& (m_y <= y) && ((m_y + m_height) >= y);
	}

	template <typename T>
	bool Rectangle<T>::Overlaps(const Rectangle<T> &rect) const
	{
		return (m_x < (rect.left + rect.width))
			&& ((m_x + m_width) > rect.left)
			&& (m_y < (rect.top + rect.height))
			&& ((m_y + m_height) > rect.top);
	}
}

