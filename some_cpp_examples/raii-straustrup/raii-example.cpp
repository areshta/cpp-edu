#include <iostream>

using namespace std;

template<typename F> struct Final_action
{
	Final_action(F f) : clean{ f } {}
	~Final_action() { clean(); }
	F clean;
};

template<class F>
Final_action<F> finally(F f)
{
	return Final_action<F>(f);
}

void test() {
	int* p = new int{ 7 };
	auto act1 = finally([&] {delete p; cout << "Goodbye,cruel world\n"; });
}


int32_t main()
{
	test();
	cout << "exit" << endl;
	cin.ignore();
    return 0;
}
