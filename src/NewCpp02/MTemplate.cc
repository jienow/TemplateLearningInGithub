
#include <iostream>
using std::cout;
using std::endl;

struct Type {
	int a, b;
	Type(Type& o) :a(o.a), b(o.b) {
		cout << "��������" << endl;
	}
	Type(int a,int b):a(a),b(b){
		cout << "��ͨ����" << endl;
	}
	~Type() {
		cout << "������" << endl;
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
		return a + b;// ���ֻ�����һ�δ�����������е���һ��Ĭ�Ϲ���
		//���������operator��inline������ֻ�ñ�����һ��
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
	// ���������Թ��죬������͵��ù��캯��.
	cout << MyClass<Type>::func(a, b) << endl;
}