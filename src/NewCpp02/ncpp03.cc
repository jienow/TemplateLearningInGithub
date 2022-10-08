#include <iostream>

using std::cout;
using std::endl;

template<class T> class RemovePointer {
public:
	typedef T Result;
};
template<class T> class RemovePointer<T*> {
public:
	typedef RemovePointer<T>::Result Result;
};

int main() {
	cout << typeid(RemovePointer<int**>::Result).name() << endl;
	return 0;
}

/*
v0 : 5
v1 : 5
v2 : 1
v3 : 6
v4 : 6
v5 : 7
v6 : 7
v7 : 5
v8 : 2
*/