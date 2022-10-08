#include <iostream>

using std::cout;
using std::endl;

// 如果特化为某一个特定的类型，就再template<>里面不用加上T，其他的都需要加上
template<class T>
void copy(T* dst, const T* src, size_t size) {
	for (size_t i = 0; i < size; i++) {
		dst[i] = src[i];
	}
}
template<class T>
class ClassID
{
public:
	static const int N = 0x333;
};
template<class T>
class ClassID<T*>
{
public:
	typedef T SameAsT;
	static const int N = 0x800000;
};



template<class T>
class RemovePointer {
public:
	typedef T Result;
};

template<class T> class RemovePointer<T*> {
public:
	typedef T Result;
};
int main() {
	int arr1[]{ 1,2,3,4,5 };
	int arr2[5];
	copy(arr2, arr1, 5);
	for (auto i : arr2)cout << i << " ";
	cout << endl;
	cout << ClassID<float*>::N << endl;
	cout << ClassID<float>::N << endl;
	cout << ClassID<ClassID<float*>::SameAsT>::N << endl;

	RemovePointer<float*>::Result x = 0x3f;
	cout << typeid(x).name() << endl;

	return 0;
}