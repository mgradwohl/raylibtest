#include <string>
#include <format>

#include <raylib.h>

#include "RLDrawSession.h"
namespace raylib
{
    DrawSession::DrawSession(Color clearColor)
    {
        BeginDrawing();

        ClearBackground(clearColor);
    }

    DrawSession::DrawSession()
    {
        BeginDrawing();
    }

    DrawSession::~DrawSession()
    {
        EndDrawing();
    }

    void DrawSession::DrawRectangle(int x, int y, int width, int height, Color color)
    {
        ::DrawRectangle(x, y, width, height, color);
    }

    void DrawSession::DrawText(const std::string& text, int x, int y, int fontSize, Color color)
    {
        ::DrawText(text.c_str(), x, y, fontSize, color);
    }

    void DrawSession::DrawFPS(int posX, int posY, int height)
    {
        Color color = LIME;
        const int fps = GetFPS();

        if ((fps < 60) && (fps >= 30))
        {
            color = ORANGE;
        }
        else if (fps < 30)
        {
            color = RED;
        }

        const std::string fpsStr = std::format("FPS: {}", GetFPS());
        DrawText(fpsStr, 10, 10, height, color);
    }
} // namespace raylib
