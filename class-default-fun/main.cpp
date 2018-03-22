#include <QCoreApplication>
#include <iostream>

using namespace std;

template <class T>
class SomeClass
{
public:
    SomeClass():
        mSz(0),
        mpData(nullptr)
    {
    }
    SomeClass(T t, int n):
        mSz(n),
        mpData(new T[n])
    {
        for(int i=0; i < mSz; ++i)
        mpData[i]=t;
    }
    SomeClass(const SomeClass& sc)
    {
        mpData =  new T[sc.mSz];
        for(int i=0; i< sc.mSz; ++i)
        {
            mpData[i] = sc.mpData[i];
        }
        mSz = sc.mSz;
    }
    SomeClass(SomeClass&& sc)
    {
        cout << "moving constructor" << endl;
        mpData = sc.mpData;
        mSz = sc.mSz;
        sc.mpData = nullptr;
        sc.mSz = 0;
    }
    SomeClass& operator=(const SomeClass& sc)
    {
        T *p = new T [sc.mSz];
        copy(sc.mpData, sc.mpData+sc.mSz, p);
        delete [ ] mpData;
        mpData = p;
        mSz = sc.mSz ;
        return *this;

    }

    SomeClass& operator=(SomeClass&& sc)
    {
        cout << "moving assigment" << endl;
        if(this != &sc)
        {
            mpData = sc.mpData;
            mSz = sc.mSz;
            sc.mpData = nullptr;
            sc.mSz = 0;
        }
        return *this;
    }

    ~SomeClass()
    {
        delete[] mpData;
    }
    void Out()
    {
        for(int i=0; i<mSz; i++)
        {
            cout << mpData[i] << endl;
        }
    }
private:
    int mSz;
    T *mpData;
};

SomeClass<int> Create()
{
    SomeClass<int> sc(777, 3);
    return sc;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SomeClass<int> sc(555, 7);
    sc.Out();

    SomeClass<int> s1(sc);

    cout << "after copy constructor" << endl;
    s1.Out();

    SomeClass<int> s2(sc);
    s2 = sc;
    cout << "after operator =" << endl;
    s2.Out();

    SomeClass<int> s3(sc);
    s3 = move(sc);
    cout << "after moving operator =" << endl;
    s3.Out();

    SomeClass<int> s4;
    cout << "after moving constructor" << endl;
    s4 = Create();
    s4.Out();

    return a.exec();
}
