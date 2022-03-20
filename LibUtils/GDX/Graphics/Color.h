#ifndef __COLOR_H
#define __COLOR_H

namespace GDX
{
	class Color
	{
	public:
		Color();
		Color(const Color & color);
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);
		Color(int r, int g, int b);
		Color(int r, int g, int b, int a);
		Color(int rgba8888);

		Color &operator += (const Color &color);
		Color &operator -= (const Color &color);
		Color &operator *= (const Color &color);

		[[nodiscard]] float ToFloatBits();
		[[nodiscard]] float ToFloatBits(int r, int g, int b, int a);
		[[nodiscard]] float ToFloatBits(float r, float g, float b, float a);

		[[nodiscard]] int ToIntBits();
		[[nodiscard]] int ToIntBits(int r, int g, int b, int a);
		[[nodiscard]] int ToIntBits(float r, float g, float b, float a);

		[[nodiscard]] static int RGB565(float r, float g, float b);
		[[nodiscard]] static int RGBA4444(float r, float g, float b, float a);
		[[nodiscard]] static int RGB888(float r, float g, float b);
		[[nodiscard]] static int RGBA8888(float r, float g, float b, float a);
		[[nodiscard]] static int ARGB8888(float a, float r, float g, float b);
		[[nodiscard]] static int RGB565(Color color);
		[[nodiscard]] static int RGBA4444(Color color);
		[[nodiscard]] static int RGB888(Color color);
		[[nodiscard]] static int RGBA8888(Color color);
		[[nodiscard]] static int ARGB8888(Color color);
		[[nodiscard]] static Color RGB565ToColor(int value);
		[[nodiscard]] static Color RGBA4444ToColor(int value);
		[[nodiscard]] static Color RGB888ToColor(int value);
		[[nodiscard]] static Color RGBA8888ToColor(int value);
		[[nodiscard]] static Color ARGB8888ToColor(int value);
		[[nodiscard]] static Color ABGR8888ToColor(float value);
		[[nodiscard]] static Color FromHsv(float h, float s, float v);
		[[nodiscard]] static Color ValueOf(char* hexString);

	public:
		static const Color WHITE;
		static const Color LIGHTGREY;
		static const Color GREY;
		static const Color DARKGREY;
		static const Color BLACK;

		static const Color BLUE;
		static const Color NAVY;
		static const Color ROYALBLUE;
		static const Color SLATE;
		static const Color SKYBLUE;
		static const Color CYAN;
		static const Color TEAL;

		static const Color GREEN;
		static const Color CHARTREUSE;
		static const Color LIME;
		static const Color FOREST;
		static const Color OLIVE;

		static const Color YELLOW;
		static const Color GOLD;
		static const Color ORANGE;

		static const Color BROWN;
		static const Color TAN;
		static const Color FIREBRICK;

		static const Color RED;
		static const Color SCARLET;
		static const Color CORAL;
		static const Color SALMON;
		static const Color PINK;
		static const Color MAGENTA;

		static const Color PURPLE;
		static const Color VIOLET;
		static const Color MAROON;

		float m_red;
		float m_green;
		float m_blue;
		float m_alpha;
	};
}

#endif // __COLOR_H
