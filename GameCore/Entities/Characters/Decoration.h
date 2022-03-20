#ifndef __DECORATIONS_H
#define __DECORATIONS_H

#include "Enums/GraphicID.h"
#include "Entities/SpriteDescriptor.h"
#include "Entities/Objects/GdxSprite.h"

namespace Game
{
	class Decoration : public GDXSprite
	{
	public:
		Decoration() = default;
		Decoration(Enums::GraphicID graphicID);
		virtual ~Decoration() = default;

		void Initialise(SpriteDescriptor& descriptor) override;
		void Update() override;
		void Draw() override;

	private:
		bool m_isMoveable = false;
	};
}

#endif // __DECORATIONS_H
