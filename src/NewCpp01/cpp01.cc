#include <iostream>
#include "MyVector.cc"
using namespace std;
int main() {
	MyVector<int> vec(4);
	for (int i = 0; i < vec.size(); i++) {
		vec[i] = i;
	}
	for (auto& i : vec) {
		cout << i << endl;
	}
	return 0;
}