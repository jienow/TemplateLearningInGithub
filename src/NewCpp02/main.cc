#include <iostream>
#include "MTemplate.cc"
float data[1024];

template<class T> T GetValue(int i) {
	return static_cast<T>(data[i]);
}
template<class Res_T, class Src_T> Res_T c_type_cast(Src_T date) {
	return Res_T(date);
}
template<int x> int add(int b) {
	return x + b;
}
template<double x> double add1(double b) {
	return x + b;
}
using std::cout;
using std::endl;
int main() {
	// 模板不能根据返回值推断T
	// float a = GetValue(1);
	int a = GetValue<int>(1);
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(c_type_cast<float>(a)).name() << std::endl;

	cout << add<1>(2) << endl;
	cout << typeid(add1<1.0>(2.0)).name() << endl;

	return 0;
}