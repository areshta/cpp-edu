#ifndef BTMODEL_H
#define BTMODEL_H

#include <array>
#include <QPoint>
#include "btglobal.h"

using namespace std;



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
};

//-------------------------

class BtModel
{
public:

    BtModel();

    const FieldArray& GetBotField() const;
    const FieldArray& GetPleyerField() const;

private:
    FieldArray mBotField;
    FieldArray mPleyerField;
};

#endif // BTMODEL_H
