#pragma once

#include "Chess/ChessTile.h"
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

typedef struct
{
    ChessTile tiles[8][8];
    sfRectangleShape* gridShape;
    sfTexture* piecesSpriteSheet;
} ChessGrid;

void ChessGrid_init(ChessGrid* grid, sfRenderWindow* window);
void ChessGrid_deinit(ChessGrid* grid);
void ChessGrid_scaleToFit(ChessGrid* grid, sfVector2f size);
void ChessGrid_render(ChessGrid* grid, sfRenderWindow* window);
