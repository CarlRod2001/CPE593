#include <iostream>
using namespace std;

class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
		if (size == capacity){
		    int* old = p;
	        p = new int [size+1];
	        for (int i = 0; i<size; i++){
	            p[i] = old[i];
	        }
		    capacity = capacity*2;
		}
	}
public:
	void addEnd(int v) {
		checkGrow();
	}

	void addStart(int v) {
	    checkGrow();

	}
	void removeStart() {
	    checkGrow();
	}
	
	void removeEnd() {
	    checkGrow();
	}
	
	void removeEvens() {
	    int j = 0;
	    for (int i = 0; i< size; i++){
	        if (a[i]%2 == 0){
	            a[j++] = a[i];
	        }
	    }
	}
};

int main() {
	GrowArray a(500); // empty list, with 500 elements

	for (int i = 0; i < 500; i++)
		a.addEnd(i); // really fast!

	for (int i = 0; i < 100000; i++)
		a.addEnd(i); // every time you need to grow, double

	a.addStart(5);

	for (int i = 0; i < 90500; i++)
		a.removeEnd();

	for (int i = 0; i < 9000; i++)
		a.removeStart();

	a.removeEvens();

	 cout << a << '\n';
}
