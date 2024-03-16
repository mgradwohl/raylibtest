#include <string>
#include <raylib.h>

#include "RLWindow.h"
namespace raylib
{
    Window::Window(const uint16_t width, const uint16_t height, const uint16_t fps, const std::string& title)
    {
        InitWindow(width, height, title.c_str());
        SetTargetFPS(fps);
    }

    Window::~Window()
    {
        CloseWindow();
    }

    bool Window::ShouldClose() const noexcept
    {
        return WindowShouldClose();
    }
} // namespace raylib

