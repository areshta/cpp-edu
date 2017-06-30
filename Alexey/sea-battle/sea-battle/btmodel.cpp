#include "btmodel.h"

CModelObj::CModelObj(QPoint point):
    mPoint {point},
    mStatusType {ObjStatusType::free}
{
}

//------------------------------------------------

inline void CModelObj::SetPoint(QPoint point)
{
    mPoint = point;
    mStatusType = ObjStatusType::placed;
}

//------------------------------------------------

CShip::CShip(QPoint point, int len, DerectionType dir):
    CModelObj{point},
    mLen {len},
    mDir {dir}
{
    mCells.resize(len);
    for(auto &i: mCells)
    {
        i = CellType::shipOK;
    }
}

//------------------------------------------------

BtModel::BtModel()
{
    for( size_t i=0; i<GConst::ChessSz; ++i )
    {
        for( size_t j=0; j<GConst::ChessSz; ++j )
        {
            mBotField[i][j] = CellType::water;
            mPleyerField[i][j] = CellType::water;
        }
    }
}

const BtModel::FieldArray& BtModel::GetBotField() const
{
    return mBotField;
}

const BtModel::FieldArray& BtModel::GetmPleyerField() const
{
    return  mPleyerField;
}
