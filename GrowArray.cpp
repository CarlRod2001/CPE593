#include <iostream>
using namespace std;

class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
		if (size == capacity){
		    capacity = capacity*2;
		}
		// if the memory needs to grow, double in size
		//TODO: YOU IMPLEMENT THIS
	}
public:
	void addEnd(int v) {
		if (size == capacity){
		    checkGrow();
		}
		int* old = p;
	    p = new int [size+1];
	    for (int i = 0; i<size; i++){
	        p[i] = old[i];
	    }
	    p[size] = v;
	    delete[] old;
	    size++;
		//array[size] = v;
        //size++;
		
	}

	void addStart(int v) {
	    int* old = p;
	    p = new int [size+1];
	    p[0] = v;
	    for (int i = 0; i<size; i++){
	        p[i+1] = old[i];
	    }
	    delete[] old;
	    size++;
	}
	void removeEnd() {
	    int* old = p;
	    p = new int [size-1];
	    for (int i = 0; i<size; i++){
	        p[i] = old[i];
	    }
	    delete[] old;
	    size--;
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

  cout << a << '\n';
}
