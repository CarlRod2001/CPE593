#include <iostream>
using namespace std;
// I pledge my honor that I have abided by the Stevens Honor System
// Carlitos Rodriguez

class GrowArray{
private:
  int *p;
  uint32_t size;		// the number of elements used
  uint32_t capacity;		// the amount of memory
  void checkGrow (){
    int *old;
    old = new int[2 * capacity];
    for (int i = 0; i < capacity; i++){
	    old[i] = p[i];
    }
    delete[] p;
    p = old;
    capacity = 2 * capacity;
}
public:
  GrowArray (uint32_t val){
    p = nullptr;
    size = 0;
    capacity=val;
  }
  void createArray (){
    p = new int[capacity];
  }
  void addEnd (int v){
    if (size == capacity){
	    checkGrow ();
    }
    p[size]=v;
    size++;
  }
  void addStart (int v){
    if (size == capacity){
	checkGrow ();
    }
    int *old = p;
    p = new int[size + 1];
    for (int i = 0; i < 0; i++)
      p[i] = old[i];
    p[0] = v;
    for (int i = 0; i < size; i++)
      p[i + 1] = old[i];
    delete[]old;
    size++;
  }
  void removeStart (){
    if (size > 0) {
        for (int i = 0; i < size - 1; i++) {
        p[i] = p[i + 1];
        }
        p[size - 1] = 0;
        size--;
    }
  }
  void removeEnd (){
    if (size > 0){
	    p[size - 1] = 0;
	    size--;
    }
  }
  void removeEvens (){
    uint32_t j = 0;
    for (int i = 0; i < size; i++){
	    if (p[i] % 2 != 0){
	    p[j++] = p[i];
	  }
    }
    j = (size)-j;
    for (int i = 0; i < j; i++){
        p[size - 1] = 0;
	    size--;
    }
  }
  void printArr(){
    for (int i = 0; i < size; i++){
	    cout << p[i] << " ";
    }
    //cout << endl; cout << "size: " << size << endl; cout << "capacity: " << capacity <<  endl;
  }
};

int main (){
    
    GrowArray a(500);
    a.createArray();

    for (int i = 0; i < 500; i++)
		a.addEnd(i);

	for (int i = 0; i < 100000; i++)
		a.addEnd(i);

	a.addStart(5);

	for (int i = 0; i < 90500; i++)
		a.removeEnd();

	for (int i = 0; i < 9000; i++)
		a.removeStart();

    a.removeEvens();
    a.printArr();
    
    //Simple Test:
    /*
    GrowArray a(10);
    a.createArray();

    for (int i = 0; i < 15; i++)
		a.addEnd(i);
	a.printArr();
	for (int i = 0; i < 5; i++)
		a.removeEnd();
	a.printArr();
	for (int i = 0; i < 5; i++)
		a.removeStart();
	a.printArr();
	a.addStart(987);
	a.printArr();

    a.removeEvens();
    a.printArr();*/
}
