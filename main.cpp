#include <locale>
#include <string>
#include <format>
#include <iostream>

#include <gsl/gsl>

#include "raylib.h"
#include "RLWindow.h"
#include "RLDrawSession.h"
#include "Render.h"

#include "Board.h"
#include "Cell.h"

static const std::string windowTitle = "Conway's Game of Life";

int main(void)
{
    // http://utf8everywhere.org/
    auto UTF8 = std::locale("en_US.UTF-8");
    std::locale::global(UTF8);
    std::cout.imbue(UTF8);
    setlocale(LC_ALL, "en_us.utf8");

    raylib::Window window(screenWidth, screenHeight, 120, windowTitle);
    {
        Board board(400, 400, 1000);
        board.RandomizeBoard(.3f);

        while (!window.ShouldClose())
        {
            board.Update(BoardRules::FastConway);
            Render::DrawBoard(board);
        }
	}

    return 0;
}