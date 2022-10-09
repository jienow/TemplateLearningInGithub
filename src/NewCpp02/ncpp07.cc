#include <iostream>
#include <type_traits>
#include <complex>
using std::cout, std::endl;

template<class T> T DustomDiv(T l1, T l2) {
	T v = NULL;
	return v;
}

//template<
//	class T,
//	bool is_float = std::is_floating_point<T>::value,
//	bool is_int = std::is_integral<T>::value
//> struct SafeDiv {
//	static T Do(T lhs, T rhs) {
//		return DustomDiv(lhs, rhs);
//	}
//};
//
//template<class T> struct SafeDiv<T, true, false> {
//	static T  Do(T lhs, T rhs) {
//		return lhs / rhs;
//	}
//};
//template<class T> struct SafeDiv<T, false, true> {
//	static T Do(T lhs, T rhs) {
//		return rhs == 0 ? 0 : lhs / rhs;
//	}
//};

template<
	class T,
	typename Enable = std::true_type
> struct SafeDiv {
	static T Do(T lhs, T rhs) {
		return DustomDiv(lhs, rhs);
	}
};
template<class T> struct SafeDiv<T,typename std::is_floating_point<T>::type>{
	static T Do(T lhs, T rhs) {
		return lhs / rhs;
	}
};
template<class T> struct SafeDiv<T, typename std::is_integral<T>::type> {
	static T Do(T lhs, T rhs) {
		return rhs == 0 ? 0 : lhs / rhs;
	}
};

int main() {
	cout << SafeDiv<float>::Do(1.0f, 2.0f) << endl;
	cout << SafeDiv<int>::Do(2, 1) << endl;
	cout << SafeDiv<std::complex<float>>::Do({ 1.f,2.f }, { 1.f,-2.f }) << endl;
	return 0;
}