//Copyright George Wagenknecht - 2022 - All rights reserved.
//FTL information transfer for quantum computer, prototype code.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int portA(int X, int Y)//Sync X & Y to time
{
    int data = 0;//bit to send
    vector<int> ratios = { 1,2,3,4,5};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 3 =  3,6,9 works //iterate this
    int A = 1;
    int C = 3; // result, shared by both ports
    if(data == 0)
    {
        if(Y == 0)
        {
            A = 1;
            C = 3; // result, shared by both ports
        }
        if(Y == 1)
        {
            A = 3;
            C = 9; // result, shared by both ports
        }
    }
    if(data == 1)
    {
        if(Y == 1)
        {
            A = 1;
            C = 3; // result, shared by both ports
        }
        if(Y == 0)
        {
            A = 3;
            C = 9; // result, shared by both ports
        }
    }
    if(A*ratios[X] == C - A)
    {
        //check entanglement property instead
        return (A*ratios[X]);//math simulates quantum entanglement
        //return state 1, state 2 or state 3
    }
    return 0;
}
int portB(int X, int Y)//Sync X & Y to time
{
    int data = 1;//bit to send
    vector<int> ratios = { 1,2,3,4,5};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 3 =  3,6,9 works //iterate this
    int B = 2;
    int C = 3; // result, shared by both ports
    if(data == 0)
    {
        if(Y == 0)
        {
            B = 2;
            C = 3; // result, shared by both ports
        }
        if(Y == 1)
        {
            B = 6;
            C = 9; // result, shared by both ports
        }
    }
    if(data == 1)
    {
        if(Y == 1)
        {
            B = 2;
            C = 3; // result, shared by both ports
        }
        if(Y == 0)
        {
            B = 6;
            C = 9; // result, shared by both ports
        }
    }
    if(B/ratios[X] == C - B)
    {
         //check entanglement property instead
        return (B/ratios[X]);//math simulates quantum entanglement
        //return state 1, state 2 or state 3
    }
    return 0;
}
int main()
{
    vector<int> ratios = { 1,2,3,4,5};//use float for more precision
    bool entanglementBlocked = false;
    bool exit = false;
    for(int Partition = 0; Partition < 2 && exit == false; Partition++)
    {
        for(int T = 0; T < ratios.size() && exit == false; T++)
        {
            int A = 1;
            int B = 2;
            int C = 3;
            if(Partition == 0)
            {
                A = 1;
                B = 2;
                C = 3;
            }
            if(Partition == 1)
            {
                A = 3;
                B = 6;
                C = 9;
            }
            int teleportedToAlpha = portB(T,Partition);//physical process
            int teleportedToBeta = portA(T,Partition);//physical process
            cout << "Cycle: " << T << ": " << teleportedToAlpha << " " << teleportedToBeta;
            if(teleportedToAlpha == 1 && teleportedToBeta == 2 && Partition == 0)
            {
                cout << " Sent off!" << endl;//done
            }
            if(teleportedToAlpha == 1 && teleportedToBeta == 6 && Partition == 0)
            {
                cout << " Sent on!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 2 && Partition == 0)
            {
                cout << " Sent off!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 6 && Partition == 0)
            {
                cout << " Sent on!" << endl;//done
            }
            if(teleportedToAlpha == 1 && teleportedToBeta == 2 && Partition == 1)
            {
                cout << " Sent on!" << endl;//done
            }
            if(teleportedToAlpha == 1 && teleportedToBeta == 6 && Partition == 1)
            {
                cout << " Sent on!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 2 && Partition == 1)
            {
                cout << " Sent off!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 6 && Partition == 1)
            {
                cout << " Sent off!" << endl;//done
            }
            if(teleportedToAlpha == 0 || teleportedToBeta == 0)
            {
                cout << endl;
            }
        }
    }
    return 0;
}
