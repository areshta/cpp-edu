#ifndef BTMODEL_H
#define BTMODEL_H

#include <array>
#include <QPoint>
#include "btglobal.h"

using namespace std;

enum class CellType
{
    water,
    shipOK,
    shipBad,
    shipKilled,
    out,
    marked
};

enum class DerectionType
{
    right,
    down
};

enum class ObjStatusType
{
    free,
    placed,
};

//--------------------------

class CModelObj
{
public:
    CModelObj(QPoint point = QPoint(-1,-1));
    inline void SetPoint(QPoint point);
protected:
    QPoint mPoint;
    ObjStatusType mStatusType;
};

//-------------------------

class CShip: public CModelObj
{
public:
    CShip(QPoint point = QPoint(-1,-1), int len =  1, DerectionType dir = DerectionType::down );
 private:
    int mLen;
    DerectionType mDir;
    vector<CellType> mCells;
};

//-------------------------

class BtModel
{
public:
    using FieldArray = array<array<CellType, GConst::ChessSz>, GConst::ChessSz>;
    BtModel();

    const FieldArray& GetBotField() const;
    const FieldArray& GetmPleyerField() const;

private:
    FieldArray mBotField;
    FieldArray mPleyerField;
};

#endif // BTMODEL_H
