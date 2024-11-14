#pragma once

static const uint16_t screenWidth = 800;
static const uint16_t screenHeight = 800; 

#include "Board.h"

class Render
{
public:
	// move/copy constuct
	Render(Render&& b) = delete;
	Render(Render& b) = delete;
	Render& operator=(Render& b) = delete;
	Render& operator=(Render&& b) = delete;

	static bool DrawBoard(Board& board);
};
