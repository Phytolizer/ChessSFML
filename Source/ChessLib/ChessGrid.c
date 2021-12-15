#include "Chess/ChessGrid.h"
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Texture.h>
#include <string.h>

void ChessGrid_init(ChessGrid* grid)
{
    memset(grid, 0, sizeof(ChessGrid));
    sfImage* piecesImage = sfImage_createFromFile("Resources/Images/pieces.png");
    grid->piecesSpriteSheet = sfTexture_createFromImage(piecesImage, NULL);
    sfImage_destroy(piecesImage);
}

void ChessGrid_render(ChessGrid* grid, sfRenderWindow* window)
{
}
