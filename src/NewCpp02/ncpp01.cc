#include <iostream>

template<class T> class TypeToId {
public:
	static int const ID = -1;
};

template<> class TypeToId<float> {
public:
	static int const ID = 0xF10A7;
};

template<> class TypeToId<void*> {
public:
	static int const ID = 0x401d;
};
class B{};
using std::cout;
using std::endl;
int main() {
	cout << TypeToId<void*>::ID << endl;
	cout << TypeToId<float>::ID << endl;
	cout << TypeToId<double>::ID << endl;


	return 0;
}