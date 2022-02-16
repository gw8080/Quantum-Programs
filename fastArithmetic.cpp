#include <iostream>
#include <bitset>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int MaxRange = 999;
    while(true)
    {
        int a = rand() % 100, b = rand() % 100, c = rand() % 100;
        for(int a = 1; a < MaxRange; a++)
        {
            int comp = a*b;
            if(comp & c == comp)//a*b represents arithmetic table
            {
                cout << a << "*" << b << "=" << c << endl;
                break;
            }
        }
    }
    return 0;
}
