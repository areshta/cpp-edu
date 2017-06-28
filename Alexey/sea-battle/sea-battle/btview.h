#ifndef BTVIEW_H
#define BTVIEW_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QSize>
#include <vector>
#include <memory>

using namespace std;

struct GConst
{
    const static int ChessSz = 10;
    const static int CellSz = 20;
    const static int Margin = 2;
    const static int Begin  = 30;
};

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
    QSize mSz; //pixels for CCell, lines and calls for CChess
};

//-----------------------------------------

class CCell: public  CDrawObj
{
public:
    explicit CCell(QPoint pt = QPoint(GConst::CellSz, GConst::CellSz), QSize sz = QSize (GConst::CellSz, GConst::CellSz) );

    void Draw(QPainter& painter) const override;
    virtual bool OnMouseMove(QPoint mousPt) override;

    ~CCell() override;

private:
    bool mUnderMouse;
};

//---------------------------------------------


class CChess: public  CDrawObj
{
public:
    using ChessSize = QSize;
    explicit CChess( );
    void Init(QPoint pt = QPoint(GConst::Begin, GConst::Begin), ChessSize lineColCount = ChessSize(GConst::ChessSz,GConst::ChessSz));
    void Draw(QPainter& painter) const override;
    virtual bool OnMouseMove(QPoint mousPt) override;
    ~CChess() override;

private:
    using CellMatrix = vector< vector< unique_ptr< CDrawObj > > >;

    CellMatrix mChess;
};

// ----------------------------------------------------

class BtView : public QObject
{
    Q_OBJECT
public:
    explicit BtView(QObject *parent = nullptr);
    void Draw(QPainter& painter);
    bool OnMouseMove(QPoint mousePt);

private:
    CChess mBotChess;
    CChess mPlayerChess;

signals:

public slots:
};

#endif // BTVIEW_H
