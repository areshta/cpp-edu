#include "btview.h"
#include <QDebug>


CDrawObj::CDrawObj(QPoint pt, QSize sz) :
mPt {pt},
mSz {sz}
{
}

CDrawObj::~CDrawObj()
{
}

//------------------------------------------

CCell::CCell(QPoint pt, QSize sz):
CDrawObj(pt,sz),
mUnderMouse {false},
mType {CellType::non}
{
}

void CCell::SetType(CellType type)
{
    mType = type;
}
inline CellType CCell::GetType() const
{
    return mType;
}

void CCell::Draw(QPainter& painter) const
{
    QRect rc(mPt,mSz);
    if( mUnderMouse )
    {
        QRect rc1( QPoint(mPt.x()+2, mPt.y()+2), QSize(mSz.width()-4,mSz.width()-4) );
        painter.drawRect(rc1);
        painter.drawRect(rc);
    }
    else
    {
        painter.drawRect(rc);
    }
}

bool CCell::OnMouseMove(QPoint mousePt)
{
    QRect rc(mPt,mSz);
    mUnderMouse = false;
    if( rc.contains(mousePt) )
    {
        mUnderMouse = true;
        return true;
    }
    return false;
}

CCell::~CCell()
{
}
//------------------------------------------z

CChess::CChess(const FieldArray fieldArray):
  CDrawObj(),
  mFieldArray(fieldArray)
{

}

void CChess::Init(QPoint pt, ChessSize lineColCount)
{
    mPt = pt;
    mSz = lineColCount;

    mChess.resize( mSz.height() );
    for( int i = 0; i < mSz.height(); ++i )
    {
        for(int j = 0; j < mSz.width(); ++j )
        {
            int placeHoder = GConst::CellSz + GConst::Margin;
            QPoint cellPt = mPt + QPoint(i*placeHoder,j*placeHoder);
            mChess[i].push_back( unique_ptr <CCell> ( new CCell( QPoint(cellPt) ) ) );
        }
    }

    SetCells();
}

void CChess::SetCells()
{
    for( int i = 0; i < mSz.height(); ++i )
    {
        for(int j = 0; j < mSz.width(); ++j )
        {
            dynamic_cast<CCell *>(mChess[i][j].get())->SetType(CellType::water);
        }
    }
}

void CChess::Draw(QPainter& painter) const
{    
    for( int i = 0; i < mSz.height(); ++i )
    {
        for(int j = 0; j < mSz.width(); ++j )
        {
            mChess[i][j]->Draw(painter);
        }
    }
}

bool CChess::OnMouseMove(QPoint mousePt)
{
    bool bRet = false;

    for( int i = 0; i < mSz.height(); ++i )
    {
        for(int j = 0; j < mSz.width(); ++j )
        {
            if( mChess[i][j]->OnMouseMove(mousePt) == true )
            {
                bRet = true;
                break;
            }
        }
    }

    return bRet;
}

CChess::~CChess()
{
}

// --------------------------------------------------------

BtView::BtView(const BtModel &btModel):
    mBtModel {btModel},
    mBotChess {btModel.GetBotField()},
    mPlayerChess {btModel.GetPleyerField()}
{
    mBotChess.Init( QPoint(30,30), QSize(10,10) );
    mObjects.push_back(& mBotChess);

    mPlayerChess.Init( QPoint(280 ,30), QSize(10,10) );
    mObjects.push_back(& mPlayerChess);
}

void BtView::Draw(QPainter& painter)
{
    for(auto p: mObjects)
    {
        p->Draw(painter);
    }
}

bool BtView::OnMouseMove(QPoint mousePt)
{
    bool bRet = false;
    for(auto p: mObjects)
    {
         bRet =  bRet || p->OnMouseMove(mousePt);
    }

    // return true if mouse present at least on one object
    return bRet;
}
