#pragma once
#include <string>

namespace raylib
{
	class Window
	{
	public:
		Window(const uint16_t width, const uint16_t height, const uint16_t fps, const std::string& title = "raylib::Window");
		Window() = delete;
		~Window();

		// move/copy constuct
		Window(Window&& b) = delete;
		Window(Window& b) = delete;
		Window& operator=(Window& b) = delete;
		Window& operator=(Window&& b) = delete;

		bool ShouldClose() const noexcept;
	};
} // namespace raylib
