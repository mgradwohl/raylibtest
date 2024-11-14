#include "raylib.h"
#include "RLDrawSession.h"
#include "Render.h"
#include "Board.h"

bool Render::DrawBoard(Board& board)
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
                const float h{ gsl::narrow_cast<float>(cell.Age()) };
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