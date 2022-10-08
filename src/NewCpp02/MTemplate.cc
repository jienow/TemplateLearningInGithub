
#include <iostream>
using std::cout;
using std::endl;

struct Type {
	int a, b;
	Type(Type& o) :a(o.a), b(o.b) {
		cout << "拷贝构造" << endl;
	}
	Type(int a,int b):a(a),b(b){
		cout << "普通构造" << endl;
	}
	~Type() {
		cout << "解引用" << endl;
	}
	auto operator+(Type& o) {
		return Type(a + o.a, b + o.b);
	}
	friend std::ostream& operator<<(std::ostream& out, Type&& a) {
		out << a.a << " " << a.b;
		return out;
	}
};



template<class T> class MyClass {
public:
	static T func(T& a, T& b) {
		return a + b;// 这个只会调用一次从运算符重载中调用一次默认构造
		//就是这里的operator被inline，所以只用被调用一次
	}
};
//template<> class MyClass<int> {
//public:
//	static int func(int a, int b) {
//		return a * b;
//	}
//};
//template<> class MyClass<float> {
//public:
//	static float func(float a, float b) {
//		return a - b;
//	}
//};

using std::cout;
using std::endl;

int main() {
	//cout << MyClass<int>::func(1, 2) << endl;
	//cout << MyClass<float>::func(1.0, 2.0) << endl;
	//cout << MyClass<size_t>::func(1, 2) << endl;
	//cout << MyClass<double>::func(1, 2) << endl;
	Type a{ 1,2 };
	Type b{ 3,4 };
	cout << "--------------------" << endl;
	// 在哪里显性构造，在哪里就调用构造函数.
	cout << MyClass<Type>::func(a, b) << endl;
}