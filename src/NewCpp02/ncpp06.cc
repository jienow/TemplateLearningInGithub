#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;

template<class T,bool IsFloat = std::is_floating_point<T>::value>
struct SaftDiv {

};

template<class T> struct SaftDiv<T,true> {
	static T Do(T lhs, T rhs) {
		return lhs / rhs;
	}
};

template<class T> struct SaftDiv<T, false> {
	static T Do(T lhs, T rhs) {
		return lhs;
	}
};

int main() {
	cout << SaftDiv<float>::Do(1.0f,2.0f) << endl;
	cout << SaftDiv<int>::Do(1, 2) << endl;
	return 0;
}