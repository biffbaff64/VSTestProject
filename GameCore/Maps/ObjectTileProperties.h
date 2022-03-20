#ifndef __OBJECTTILEPROPERTIES_H
#define __OBJECTTILEPROPERTIES_H

namespace Game
{
    class ObjectTileProperties
    {
    public:
        ObjectTileProperties() = default;
        ~ObjectTileProperties() = default;

        bool m_hasDirection;
        bool m_hasDistance;
        bool m_hasSpeed;
        bool m_isLinked;
    };
}

#endif // __OBJECTTILEPROPERTIES_H
