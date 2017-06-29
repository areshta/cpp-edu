#ifndef BTMODEL_H
#define BTMODEL_H

#include "btglobal.h"

enum class CellType
{
    water,
    ship,
    killed,
    out,
    nonPlay
};

class ModelObj
{
public:
    ModelObj();

};

//-------------------------


//-------------------------

class BtModel
{
public:
    BtModel();
private:
    CellType mBotField[GConst::ChessSz][GConst::ChessSz];
    CellType mPleyerField[GConst::ChessSz][GConst::ChessSz];
};

#endif // BTMODEL_H
