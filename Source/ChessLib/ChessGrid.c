#include "Chess/ChessGrid.h"
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <string.h>

void ChessGrid_init(ChessGrid* grid, sfRenderWindow* window)
{
    memset(grid, 0, sizeof(ChessGrid));
    sfImage* piecesImage = sfImage_createFromFile("Resources/Images/pieces.png");
    grid->piecesSpriteSheet = sfTexture_createFromImage(piecesImage, NULL);
    sfImage_destroy(piecesImage);
    grid->gridShape = sfRectangleShape_create();
    sfVector2u size = sfRenderWindow_getSize(window);
    ChessGrid_scaleToFit(grid, (sfVector2f){.x = size.x, .y = size.y});
    sfRectangleShape_setFillColor(grid->gridShape, (sfColor){.r = 0x80, .g = 0x80, .b = 0x80, .a = 0xFF});
}

void ChessGrid_deinit(ChessGrid* grid)
{
    sfRectangleShape_destroy(grid->gridShape);
    sfTexture_destroy(grid->piecesSpriteSheet);
}

void ChessGrid_scaleToFit(ChessGrid* grid, sfVector2f size)
{
    float aspectRatio = size.x / size.y;
    if (aspectRatio > 1.0f)
    {
        sfRectangleShape_setSize(grid->gridShape, (sfVector2f){.x = size.y, .y = size.y});
        sfRectangleShape_setOrigin(grid->gridShape, (sfVector2f){.x = size.y / 2, .y = size.y / 2});
    }
    else
    {
        sfRectangleShape_setSize(grid->gridShape, (sfVector2f){.x = size.x, .y = size.x});
        sfRectangleShape_setOrigin(grid->gridShape, (sfVector2f){.x = size.x / 2, .y = size.x / 2});
    }
    sfRectangleShape_setPosition(grid->gridShape, (sfVector2f){.x = size.x / 2, .y = size.y / 2});
}

void ChessGrid_render(ChessGrid* grid, sfRenderWindow* window)
{
    sfRenderWindow_drawRectangleShape(window, grid->gridShape, NULL);
}
