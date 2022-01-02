//Copyright George Wagenknecht - 2022 - All rights reserved.
// FTL information  transfer prototype code(aim to use more complex math, preferably one not quickly checkable, however this code can exchange a state from each port)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 =  2,2,4 & state 3 =  3,6,9 works //iterate this
    int A = 3; // port A
    int B = 6; // port B
    int C = 9; // result, shared by both ports
    vector<int> ratios = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};//use float for more precision
    for(int X = 0; X < ratios.size(); X++) //distribute code between ports and sync X, try to guess the state each port is in by bruteforce
    {
        if(A*ratios[X] == C - A && B/ratios[X] == C - B) //ANDing represents entangled port A & port B, divide each statement and 100% blockage of wavefunction indicates successful transfer
        {
            //port A = if(A*ratios[X] == C - A && Entanglement == true)
            //port B = if(B/ratios[X] == C - B && Entanglement == true)
            //continue
            cout << "Original" << endl;
            cout << "Node A = " << A << " Node B = " << B << endl;
            cout << "Sent!" << endl;
            cout << "Node A = " << (A*ratios[X]) << " Node B = " << (B/ratios[X]) << endl;
            //return state 1, state 2 or state 3
        }
    }
    return 0;
}
