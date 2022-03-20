#include <iostream>
using namespace std;
// I pledge my honor that I have abided by the Stevens Honor System
// Carlitos Rodriguez

class GrowArray
{
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
    capacity = 1;
  }
  void createArray (int v){
    if (size == capacity){
	    checkGrow ();
    }
    int *old = p;
    p = new int[size + 1];
    for (int i = 0; i < size; i++){
	    p[i] = old[i];
    }
    p[size] = v;
    delete[]old;
    size++;
  }
  void addEnd (int v){
    if (size == capacity){
	    checkGrow ();
    }
    p[size] = v;
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
    int j = 0;
    for (int i = 0; i < size; i++){
	    if (p[i] % 2 != 0){
	    p[j++] = p[i];
	  }
    }
    int xs = (size)-j;
    for (int i = 0; i < xs; i++){
        p[size - 1] = 0;
	    size--;
    }
  }
  void printArr (){
    for (int i = 0; i < size; i++){
	    cout << p[i] << " ";
    }
    cout << endl;
    cout << "size: " << size << endl;
    cout << "capacity: " << capacity <<  endl;
    cout << endl;
  }
};

int
main (){
  GrowArray a;
  for (int i = 0; i < 500; i++)
    a.createArray (i);

  for (int i = 0; i < 100; i++)
		a.addEnd(i); // every time you need to grow, double

	
  a.printArr();
}
