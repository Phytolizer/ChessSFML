#include "Chess/ChessGrid.h"
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <string.h>

void ChessGrid_init(ChessGrid* grid)
{
    memset(grid, 0, sizeof(ChessGrid));
    sfImage* piecesImage = sfImage_createFromFile("Resources/Images/pieces.png");
    grid->piecesSpriteSheet = sfTexture_createFromImage(piecesImage, NULL);
    sfImage_destroy(piecesImage);
    grid->gridShape = sfRectangleShape_create();
    sfRectangleShape_setPosition(grid->gridShape, (sfVector2f){.x = 0, .y = 0});
    sfRectangleShape_setSize(grid->gridShape, (sfVector2f){.x = 100, .y = 100});
    sfRectangleShape_setFillColor(grid->gridShape, (sfColor){.r = 0x80, .g = 0x80, .b = 0x80, .a = 0xFF});
}

void ChessGrid_scaleToFit(ChessGrid* grid, sfVector2f size)
{
    float aspectRatio = size.x / size.y;
    if (aspectRatio > 1.0f)
    {
        sfRectangleShape_setPosition(grid->gridShape,
                                     (sfVector2f){.x = (size.x - size.y) / 2.0f, .y = 0});
        sfRectangleShape_setSize(grid->gridShape, (sfVector2f){.x = size.y, .y = size.y});
    }
    else
    {
        sfRectangleShape_setPosition(grid->gridShape,
                                     (sfVector2f){.x = 0, .y = (size.y - size.x) / 2.0f});
        sfRectangleShape_setSize(grid->gridShape, (sfVector2f){.x = size.x, .y = size.x});
    }
}

void ChessGrid_render(ChessGrid* grid, sfRenderWindow* window)
{
    sfRenderWindow_drawRectangleShape(window, grid->gridShape, NULL);
}
