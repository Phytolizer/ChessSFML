#pragma once

#include "Chess/ChessPieceType.h"
#include <SFML/Graphics/RenderTexture.h>

typedef struct
{
    ChessPieceType type;
    sfTexture* spriteSheet;
} ChessPiece;
