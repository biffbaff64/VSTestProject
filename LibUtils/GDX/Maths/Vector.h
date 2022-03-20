#ifndef __GDX_VECTOR_H
#define __GDX_VECTOR_H

namespace GDX
{
    class Vector
    {
	public:
		Vector();
		Vector(const Vector &vector);
		Vector(const float both);
		Vector(const float x, const float y);
		Vector(const int both);
		Vector(const int x, const int y);
		Vector(const unsigned int both);
		Vector(const unsigned int x, const unsigned int y);

		float Dot(const Vector &other);
		float Length();

		Vector Normalized();
		Vector &Normalize();

		Vector &operator += (const Vector &vector);
		Vector &operator -= (const Vector &vector);
		Vector &operator *= (const Vector &vector);
		Vector &operator /= (const Vector &vector);
		Vector &operator *= (const float f);
		Vector &operator /= (const float f);

		Vector operator + (const Vector &vector) const;
		Vector operator - (const Vector &vector) const;
		Vector operator * (const Vector &vector) const;
		Vector operator / (const Vector &vector) const;
		Vector operator * (const float f) const;
		Vector operator / (const float f) const;
		Vector operator - () const;

		bool operator == (const Vector &vector) const;
		bool operator != (const Vector &vector) const;

		float m_x;
		float m_y;
	};
}

#endif // __GDX_VECTOR_H
