/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

tmxlite - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#pragma once

#include "Config.hpp"
#include "Types.hpp"

#include <string>
#include <cassert>

namespace pugi
{
    class xml_node;
}

namespace tmx
{
    /*!
    \brief Represents a custom property.
    Tiles, objects and layers of a tmx map may have custom
    properties assigned to them. This class represents a
    single property and provides access to its value, the
    type of which can be determined with getType()
    */
    class TMXLITE_EXPORT_API Property final
    {
    public:

        enum class Type
        {
            Boolean,
            Float,
            Int,
            String,
            Colour,
            File,
            Undef
        };

        Property();
        ~Property() = default;

        /*!
        \brief Attempts to parse the given node as a property
        */
        void parse(const pugi::xml_node&);
        /*!
        \brief Returns the type of data stored in the property.
        This should generally be called first before trying to
        read the proprty value, as reading the incorrect type
        will lead to undefined behaviour.
        */
        [[nodiscard]] Type getType() const { return m_type; }
        /*!
        \brief Returns the name of this property
        */
        [[nodiscard]] const std::string& getName() const { return m_name; }
        /*!
        \brief Returns the property's value as a boolean
        */
        [[nodiscard]] bool getBoolValue() const { assert(m_type == Type::Boolean); return m_boolValue; }
        /*!
        \brief Returns the property's value as a float
        */
        [[nodiscard]] float getFloatValue() const { assert(m_type == Type::Float); return m_floatValue; }
        /*!
        \brief Returns the property's value as an integer
        */
        [[nodiscard]] int getIntValue() const { assert(m_type == Type::Int); return m_intValue; }
        /*!
        \brief Returns the property's value as a string
        */
        [[nodiscard]] const std::string& getStringValue() const { assert(m_type == Type::String); return m_stringValue; }
        /*!
        \brief Returns the property's value as a Colour struct
        */
        [[nodiscard]] const Colour& getColourValue() const { assert(m_type == Type::Colour); return m_colourValue; }
        /*!
        \brief Returns the file path property as a string, relative to the map file
        */
         [[nodiscard]] const std::string& getFileValue() const { assert(m_type == Type::File); return m_stringValue; }


    private:
        union
        {
            bool m_boolValue;
            float m_floatValue;
            int m_intValue;
        };
        std::string m_stringValue;
        std::string m_name;
        Colour m_colourValue;

        Type m_type;
    };
}
