#include <iostream>
#include <memory>
#include <chrono>

using namespace std;
using namespace std::chrono;

//some class, does not matter what it does.
class A
{
public:
    void inc()
    {
        ++counter;
    }
private:
    size_t counter {0};
};

void f_val(shared_ptr<A> a)
{
    //a->inc();
}

void f_ref(shared_ptr<A>& a)
{
    //a->inc();
}

int main()
{
    const size_t sz = 1000000;
    auto spa = std::make_shared<A>();

    milliseconds time1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    for( size_t i=0; i < sz; ++i){
        f_val(spa);
    }

    milliseconds time2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    for( size_t i=0; i < sz; ++i){
        f_ref(spa);
    }

    milliseconds time3 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    int d1 = (time2-time1).count();
    int d2 = (time3-time2).count();

    cout << d1 << endl << d2 << endl << "time val / time ref = " << static_cast<double>(d1)/d2 << endl;

    return 0;
}
