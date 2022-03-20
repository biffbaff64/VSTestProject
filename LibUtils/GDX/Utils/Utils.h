#ifndef __GDX_UTILS_H
#define __GDX_UTILS_H

#include <stdlib.h>

namespace GDX
{
	class Utils
	{
	public:
		Utils() = default;
		~Utils() = default;

		template <typename T>
		constexpr inline T Clamp(T value, T minValue, T maxValue)
		{
			return min(max(minValue, value), maxValue);
		}
	};
}

#endif // __GDX_UTILS_H
