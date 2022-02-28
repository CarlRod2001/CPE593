#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

// I pledge my honor that I have abided by the Stevens Honor System
// Carlitos Rodriguez
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArr(int arr[], int length){
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Lomuto's partition Scheme
int partition(int A[], int L, int H){
   int pivot = A[H];
   int i = L-1;
   for(int j=L; j<=H-1; j++){
       if (A[j] < pivot){
            i++;
            swap(A[i],A[j]);
       }
   }
   i=i+1;
   swap(A[i],A[H]);
   return i;
}

void Quicksort(int arr[], int low, int high){
    if (high <= low){
        return;
    }
    int p = partition(arr, low, high);
    Quicksort(arr, low, p-1);
    Quicksort(arr, p+1, high);
}
    
int main(){
    int* arraytxt[] = new int[5];
    int w = 0;
    ifstream in("hw3.txt");
    while (in){
        in >> arraytxt[w++];
    }
    printArr(arraytxt, 5);

    srand(time(0));
    // The foolowing are test cases
    
    //int arr[] = {6, 7, 4, 8, 20, 19};
    //int arr[] = {29, 31, 45, 211, 12, 1};
    int arr[] = {1, 32, 3, 43, 93, 6};
    //int arr[] ={10, 9, 9, 8, 7, 6, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    
    int low = 0;
    int high = n-1;
    
    Quicksort(arr, low, high);
    printArr(arr, n);
    
    int length=10000000;
    // sets every element in the array to a number from 1 to n
    int* array = new int[length];
    for(int i = 0; i < length; i++){
        array[i] = i+1;
    }
    printArr(array, 20);
    
    // scrambles the array using Fischer-Yates method
    for(int i = 0; i < length; i++){
        int pick = (rand() % length-1)+1;
        swap(array[i],array[pick]);
    }
    printArr(array, 20);
    
    Quicksort(array, 0, (length-1));
    printArr(array, 20);
    // cout<<array[0]<<" to "<<array[length-1]<<endl;
    delete[] array;
    
    return 0;
}
