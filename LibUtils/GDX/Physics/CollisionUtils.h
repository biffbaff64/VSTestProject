#ifndef __COLLISION_UTILS_H
#define __COLLISION_UTILS_H

namespace GDX
{
	class CollisionUtils
	{
	public:
		CollisionUtils() = default;
		virtual ~CollisionUtils() = default;

		void Tidy();
	};
}

#endif // __COLLISION_UTILS_H
