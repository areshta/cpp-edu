#ifndef BTGLOBAL_H
#define BTGLOBAL_H

#include <array>

using namespace std;

struct GConst
{
    const static int ChessSz = 10;
    const static int CellSz = 20;
    const static int Margin = 2;
    const static int Begin  = 30;
};

enum class CellType
{
    non,
    water,
    shipOK,
    shipBad,
    shipKilled,
    out,
    marked
};

using FieldArray = array<array<CellType, GConst::ChessSz>, GConst::ChessSz>;

#endif // BTGLOBAL_H
