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

        int a =  rand() % 100, b = rand() % 100, c = rand() % 100;
        int slope = 0;
        for(int a = 1; a < MaxRange; a++)
        {
            if(a*b & c == a*b)
            {
                    cout << a << "*" << b << "=" << c << endl;
                    break;
            }
        }
    }
    return 0;
}

