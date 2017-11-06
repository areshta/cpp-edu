#ifndef BTVIEW_H
#define BTVIEW_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <vector>
#include <memory>
#include "btglobal.h"
#include "btmodel.h"

using namespace std;



// ----------------------------------------------------------------
class CDrawObj
{
public:
    CDrawObj(QPoint pt = QPoint(GConst::CellSz, GConst::CellSz), QSize sz = QSize(GConst::CellSz,GConst::CellSz));
    virtual void Draw(QPainter& painter) const = 0;
    virtual bool OnMouseMove(QPoint mousPt) = 0;
    virtual ~CDrawObj();
protected:
    QPoint mPt;
    QSize mSz; //pixels for CCell, lines and collumns for CChess
};

//-----------------------------------------

class CCell: public  CDrawObj
{
public:
    explicit CCell(QPoint pt = QPoint(GConst::CellSz, GConst::CellSz), QSize sz = QSize (GConst::CellSz, GConst::CellSz) );

    inline void SetType(CellType type);
    inline CellType GetType() const;

    void Draw(QPainter& painter) const override;
    virtual bool OnMouseMove(QPoint mousPt) override;

    ~CCell() override;

private:
    bool mUnderMouse;
    CellType mType;
};

//---------------------------------------------


class CChess: public  CDrawObj
{
public:
    using ChessSize = QSize;
    explicit CChess( const FieldArray fieldArray );
    void Init(QPoint pt = QPoint(GConst::Begin, GConst::Begin), ChessSize lineColCount = ChessSize(GConst::ChessSz,GConst::ChessSz));
    void SetCells();
    void Draw(QPainter& painter) const override;
    virtual bool OnMouseMove(QPoint mousPt) override;
    ~CChess() override;

private:
    using CellMatrix = vector< vector< unique_ptr< CDrawObj > > >;

    CellMatrix mChess;
    const FieldArray& mFieldArray;
};

// ----------------------------------------------------

class BtView
{
public:
    BtView(const BtModel& btModel);
    void Draw(QPainter& painter);
    bool OnMouseMove(QPoint mousePt);

private:

    vector< CDrawObj* > mObjects; // is not pointers owner! No delete!

    const BtModel& mBtModel;
    CChess mBotChess;
    CChess mPlayerChess;

signals:

public slots:
};

#endif // BTVIEW_H
