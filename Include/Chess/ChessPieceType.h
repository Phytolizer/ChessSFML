#pragma once

#define CHESS_PIECE_TYPE_VALUES_                                                                                       \
    X(PAWN)                                                                                                            \
    X(ROOK)                                                                                                            \
    X(KNIGHT)                                                                                                          \
    X(BISHOP)                                                                                                          \
    X(QUEEN)                                                                                                           \
    X(KING)

typedef enum
{
#define X(x) CHESS_PIECE_TYPE_##x,
    CHESS_PIECE_TYPE_VALUES_
#undef X
} ChessPieceType;

const char* ChessPieceType_toString(ChessPieceType type);
