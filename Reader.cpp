#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int printElements(int array[])
{
    int total = 0;
    int i = 0;
    cout << "\n\n";
    for (i=0; i<100; i++)
    {
        cout << array[i] << ",";
        total = total + array[i];
    }
    cout << "\n\n";
    return total;
}

int main()
{
    int array[100];
    int i=0;

    ifstream in("hw3.txt");
    while (in)
    {
        in >> array[i++];
    }

    int total = printElements(array);
    int average = total / 100;
    cout << "Total: " << total << "\n";
}
