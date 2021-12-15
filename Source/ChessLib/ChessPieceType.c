#include "Chess/ChessPieceType.h"
#include <stddef.h>

const char* ChessPieceType_toString(ChessPieceType type)
{
    switch (type)
    {
#define X(x)                                                                                                           \
    case CHESS_PIECE_TYPE_##x:                                                                                         \
        return #x;
        CHESS_PIECE_TYPE_VALUES_
#undef X
    default:
        return NULL;
    }
}
