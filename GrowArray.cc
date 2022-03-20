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
    int *old = p;
    p = new int[2 * capacity];
    for (int i = 0; i < size; i++){
	    p[i] = old[i];
    }
    delete[] old;
    capacity = 2 * capacity;
}
public:
  GrowArray (){
    p = nullptr;
    size = 0;
    capacity=1;
  }
  void createArray (int v){
    if (size == capacity){
	    checkGrow ();
    }
    int *temp = p;
    p = new int[size+1];
    for (int i = 0; i < size; i++){
	    p[i] = temp[i];
    }
    p[size] = v;
    delete[] temp;
    size++;
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
  void printArr (){
    for (int i = 0; i < size; i++){
	    cout << p[i] << " ";
    }
    // cout << endl; cout << "size: " << size << endl; cout << "capacity: " << capacity <<  endl;
  }
};

int main (){
    // start of creation of the array
    GrowArray a;
    int NoE = 500; // set Number Of Elements equal to 500
    for (int i = 0; i < 1; i++)
        a.createArray (i);
    for (int i = 0; i < NoE; i++)
        a.addEnd (i);
    a.removeStart();
    // end of creation of the array
    
    for (int i = 0; i < 100000; i++)
		a.addEnd(i); 

	a.addStart(5);

	for (int i = 0; i < 90500; i++)
		a.removeEnd();

	for (int i = 0; i < 9000; i++)
		a.removeStart();
		
	a.removeEvens();
	a.printArr();
}
