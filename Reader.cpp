#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
