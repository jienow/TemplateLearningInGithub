#include <iostream>

using std::cout;
using std::endl;

template<class T>
struct is_float {
	bool value = false;
};
template<> struct is_float<float> {
	bool value = true;
};

template<class T,bool IsFloat = is_float<T>::value>
struct SaftDiv {};

template<class T> struct SaftDiv<T,true> {

};


int main() {
	
	return 0;
}