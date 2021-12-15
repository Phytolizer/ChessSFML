#pragma once

#include "Chess/ChessPiece.h"
#include <stdbool.h>

typedef struct
{
    bool piecePresent;
    ChessPiece piece;
} ChessTile;
