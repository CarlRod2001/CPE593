#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
    string array[2]; 
    short loop=0; 
    string line; 
    ifstream myfile ("hw3.txt"); 
    if (myfile.is_open()) 
    {
        while (! myfile.eof() ) 
        {
            getline (myfile,line); 
            array[loop] = line;
            cout << array[loop] << endl; 
            loop++;
        }
        myfile.close(); 
    }
    else cout << "can't open the file"; 
    system("PAUSE");
    return 0;
}
