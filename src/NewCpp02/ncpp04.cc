#include <memory>
#include <iostream>

using std::unique_ptr;
using std::shared_ptr;
using std::cout;
using std::endl;

template <typename T, typename U> struct X{};;    // 0 原型有两个类型参数

// 下面的这些偏特化的“小尾巴”也需要两个类型参数对应
template <typename T>             struct X<T, T  > { int a = 1; };    // 1
template <typename T>             struct X<T*, T  > { int a = 2; };    // 2
template <typename T>             struct X<T, T* > { int a = 3; };    // 3
template <typename U>             struct X<U, int> { int a = 4; };    // 4
template <typename U>             struct X<U*, int> { int a = 5; };    // 5
template <typename U, typename T> struct X<U*, T* > { int a = 6; };    // 6
template <typename U, typename T> struct X<U, T* > { int a = 7; };    // 7

template <typename T>             struct X<unique_ptr<T>, shared_ptr<T>> {
	int a = 8;
}; // 8

// 以下特化，分别对应哪个偏特化的实例？


int main() {
	X<float*, int>      v0;
	X<double*, int>      v1;
	X<double, double>   v2;
	X<double, double>   v2;
	X<float*, double*>  v3;
	// X<float*,  float*>   v4;                          
	X<double, float*>   v5;
	X<int, double*>  v6;
	// X<int*,    int>      v7;                       
	X<double*, double>   v8;
	cout << v0.a << endl;
	cout << v1.a << endl;
	cout << v2.a << endl;
	cout << v3.a << endl;
	//cout << v4.a << endl;
	cout << v5.a << endl;
	cout << v6.a << endl;
	//cout << v7.a << endl;
	cout << v8.a << endl;

	return 0;
}