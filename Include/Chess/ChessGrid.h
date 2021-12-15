#pragma once

#include "Chess/ChessTile.h"
#include <SFML/Graphics/Texture.h>

typedef struct
{
    ChessTile tiles[8][8];
    sfTexture* piecesSpriteSheet;
} ChessGrid;

void ChessGrid_init(ChessGrid* grid);
void ChessGrid_render(ChessGrid* grid, sfRenderWindow* window);
