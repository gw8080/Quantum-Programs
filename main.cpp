/* FTL information transfer for quantum computer, prototype code.
    Copyright (C) 2022 George Wagenknecht
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
//seperate port A and port B, include server at each end
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int portA(int X, int Y)//Sync X & Y to time
{
    //do calculation
    int qubit = 0;//bit to send
    vector<int> ratios = { 1,2,3,4,5};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 = 3,6,9 works //iterate this
    int A = 1;
    int C = 3; // result, shared by both ports
    if(qubit == 0)
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
    if(qubit == 1)
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
        //check entanglement property and check time & partition information of the entanglement event instead
        return (A*ratios[X]);//math simulates quantum entanglement
        //return state 1 or state 2
    }
    return 0;
}
int portB(int X, int Y)//Sync X & Y to time
{
    //do calculation
    int qubit = 0;//bit to send
    vector<int> ratios = { 1,2,3,4,5};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 = 3,6,9 works //iterate this
    int B = 2;
    int C = 3; // result, shared by both ports
    if(qubit == 0)
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
    if(qubit == 1)
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
        //check entanglement property and check time & partition information of the entanglement event instead
        return (B/ratios[X]);//math simulates quantum entanglement
        //return state 1 or state 2
    }
    return 0;
}
int main()//server
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
                cout << " Teleported [off] to port A!" << endl;//done
            }
            if(teleportedToAlpha == 1 && teleportedToBeta == 6 && Partition == 0)
            {
                cout << " Teleported [on] to port A!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 2 && Partition == 0)
            {
                cout << " Teleported [off] to port A!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 6 && Partition == 0)
            {
                cout << " Teleported [on] to port A!" << endl;//done
            }
            if(teleportedToAlpha == 1 && teleportedToBeta == 2 && Partition == 1)
            {
                cout << " Teleported [on] to port B!" << endl;//done
            }
            if(teleportedToAlpha == 1 && teleportedToBeta == 6 && Partition == 1)
            {
                cout << " Teleported [on] to port B!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 2 && Partition == 1)
            {
                cout << " Teleported [off] to port B!" << endl;//done
            }
            if(teleportedToAlpha == 3 && teleportedToBeta == 6 && Partition == 1)
            {
                cout << " Teleported [off] to port B!" << endl;//done
            }
            if(teleportedToAlpha == 0 || teleportedToBeta == 0)
            {
                cout << " In superposition" << endl;
            }
        }
    }
    return 0;
}
