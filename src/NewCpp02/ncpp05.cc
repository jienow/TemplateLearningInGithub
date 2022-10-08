#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::list;
using std::endl;
using std::vector;

template<class T>
class List {
public:
	T val;
	List* next;
private:
public:
	List(T val):val(val),next(nullptr),_list_begin(this),_list_end(this){}
	void push_back(T val) {
		_list_end = new List(val);
		_list_end->_list_begin = _list_begin;
	}
	List* operator++() {
		return next;
	}
	List* begin() {
		return _list_begin;
	}
	List* end() {
		return nullptr;
	}
};

int main() {

	List L(1);
	L.push_back(2);
	L.push_back(3);

	for (auto i : L) {
		cout << i.val << " ";
	}
	return 0;
}