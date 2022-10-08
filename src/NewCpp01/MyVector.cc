
template<class T>
class MyVector {
private:
	T* arr;
	size_t N;
public:
	MyVector(size_t sz) {
		if (!arr)delete[] arr;
		arr = new T[sz];
		N = sz;
	}
	T* begin() { return arr; }
	T* end() { return arr + N; }
	size_t size() { return N; };
	T& operator[] (size_t index) 
	{ 
		return arr[index]; 
	};
};