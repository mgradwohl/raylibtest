#include <locale>
#include <string>
#include <format>
#include <iostream>

#include <gsl/gsl>

#include "raylib.h"
#include "RLWindow.h"
#include "RLDrawSession.h"

#include "Board.h"
#include "Cell.h"

static const uint16_t screenWidth = 1200;
static const uint16_t screenHeight = 1200;
static const std::string windowTitle = "Conway's Game of Life";

bool drawBoard(Board& board)
{
    raylib::DrawSession drawSession(BLACK);

    const float cellWidth = static_cast<float>(screenWidth) / board.Width();

    for (uint16_t i = 0; i < board.Width(); i++)
    {
        for (uint16_t j = 0; j < board.Height(); j++)
        {
            if (board.Alive(i, j))
            {
                // Draw alive square
                Cell cell = board.GetCell(i, j);
                const float h{ gsl::narrow_cast<float>(cell.Age())};
                drawSession.DrawRectangle(i * cellWidth, j * cellWidth, cellWidth, cellWidth, ColorFromHSV(h, 0.6f, 0.7f));
            }
            else
            {
                // Draw dead square
                // do nothing, leave it black
            }
        }
    }

    drawSession.DrawFPS(10, 10, 30);
    
    return true;
}

int main(void)
{
    // http://utf8everywhere.org/
    auto UTF8 = std::locale("en_US.UTF-8");
    std::locale::global(UTF8);
    std::cout.imbue(UTF8);
    setlocale(LC_ALL, "en_us.utf8");

    raylib::Window window(screenWidth, screenHeight, 120, windowTitle);
    {
        Board board;
        board.Resize(400, 400, 1000);
        board.RandomizeBoard(.3f, 1000);

        while (!window.ShouldClose())
        {
            board.Update(BoardRules::FastConway);
            drawBoard(board);
        }
	}

    return 0;
}