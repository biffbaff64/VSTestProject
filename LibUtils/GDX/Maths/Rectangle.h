#ifndef __RECTANGLE_H
#define __RECTANGLE_H

namespace GDX
{
	template <typename T>
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(T x, T y, T width, T height);
		virtual ~Rectangle() = default;

		[[nodiscard]] virtual bool Contains(T x, T y) const;
		[[nodiscard]] virtual bool Overlaps(const Rectangle<T> &rect) const;

		T m_x;
		T m_y;
		T m_width;
		T m_height;
	};

	template <typename T>
	inline bool operator ==(const Rectangle<T>& left, const Rectangle<T>& right)
	{
		return (left.m_x == right.m_x) && (left.m_width == right.m_width)
			&& (left.m_y == right.m_y) && (left.m_height == right.m_height);
	}

	template <typename T>
	inline bool operator !=(const Rectangle<T> &left, const Rectangle<T> &right)
	{
		return !(left == right);
	}

	typedef Rectangle<int>		IntRect;
	typedef Rectangle<float>	FloatRect;
}

#endif // __RECTANGLE_H
