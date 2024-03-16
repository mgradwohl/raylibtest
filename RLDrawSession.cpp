#include <string>
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
} // namespace raylib
