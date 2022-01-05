#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand (time(NULL));
    //qubit-partition-LV--truth table configuration // qubits require to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
    //example
    //A = 0011 0100 1111 1001
    //B = 0001 0110 1100 1011
    long long int combinations = 0;
    string data = "";
    long long int n = 1048576;
    for(int x = 0; x < n; x++)
    {
            string binA = bitset<16>(x).to_string();
            string binB = bitset<16>(rand() % n).to_string();
            //workspace, (binB should be partially asymmetric)
            if(binA.at(0) == 48 && binB.at(0) == 48 && binA.at(3) == 48 && binB.at(3) == 49 && binA.at(6) == 49 && binB.at(6) == 48 && binA.at(9) == 49 && binB.at(9) == 49 )//qubit
            {
                        combinations++;
            }
    }
    cout << "combinations: " << combinations << endl;
    return 0;
}
