#pragma once
#include <raylib.h>
#include <string>

namespace raylib
{
	class DrawSession
	{
	public:
		DrawSession();
		DrawSession(Color clearColor);

		~DrawSession();

		// move/copy construct
		DrawSession(DrawSession&& b) = delete;
		DrawSession(DrawSession& b) = delete;
		DrawSession& operator=(DrawSession& b) = delete;
		DrawSession& operator=(DrawSession&& b) = delete;

		void DrawRectangle(int x, int y, int width, int height, Color color);
		void DrawText(const std::string& text, int x, int y, int fontSize, Color color);
		void DrawFPS(int posX, int posY, int height);
	};
} // namespace raylib
