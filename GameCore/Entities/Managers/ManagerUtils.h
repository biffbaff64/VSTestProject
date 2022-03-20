#ifndef __MANAGER_UTILS_H
#define __MANAGER_UTILS_H

#include <vector>

#include "Enums/GraphicID.h"
#include "GDX/Maths/Vec3.h"
#include "Entities/SpriteDescriptor.h"

namespace Game
{
	class ManagerUtils
	{
	public:
		std::vector<SpriteDescriptor> GetDescriptorList(const Enums::GraphicID targetGID);
		std::vector<GDX::Vec3Int> FindMultiCoordinates(const Enums::GraphicID targetGID);
		GDX::Vec3Int FindCoordinates(const Enums::GraphicID targetGID);

	private:
		std::vector<SpriteDescriptor>	m_descriptors;
		std::vector<GDX::Vec3Int>		m_coords;
		GDX::Vec3Int					m_coord;
	};
}

#endif // __MANAGER_UTILS_H
