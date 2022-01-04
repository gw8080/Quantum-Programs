/* code for quantum computer, prototype code.
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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int portA(int X, int Y, int n,vector<int> data)//Sync X & Y to time
{
    //do calculation
    int qubit = data[n];//entangled bit/Turing strip
    vector<int> ratios = { 1,2};
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
int portB(int X, int Y,int n,vector<int> data)//Sync X & Y to time
{
    //do calculation
    int qubit = data[n];//entangled bit/Turing strip
    vector<int> ratios = { 1,2};
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
    cout << "QBOX terminal" << endl;
    vector<int> data = {1,0,1,1,0,0,0};//instead place in portA. cycle program, done instantly
    vector<int> dataB = {1,1,1,1,0,0,1};//instead place in portB. cycle data, done instantly
    vector<int> output;
    vector<int> memory;
    srand (time(NULL));
    vector<int> ratios = { 1,2};//use float for more precision
    cout << "Input A: ";
    for(int n = 0; n < data.size(); n++)
    {
        cout << data[n];
    }
    cout << endl;

    cout << "Input B: ";
    for(int n = 0; n < dataB.size(); n++)
    {
        cout << dataB[n];
    }
    cout << endl;

    cout << "logical errors should be solved when ports are piecewise rather than using unfitting arrays when simulating..." << endl;
    for(int n = 0; n < data.size(); n++)
    {
        cout << "New gate, n=" << n << "(effects are simultaneous on quantum hardware)" << endl;
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
                int teleportedToAlpha = portB(T,Partition,n,dataB);//physical process
                int teleportedToBeta = portA(T,Partition,n,data);//physical process
                //-----------------move to independent port----------------
                cout << "Cycle: " << T << ": " << teleportedToAlpha << " " << teleportedToBeta;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed using the same program, instantly
                if(teleportedToAlpha == 1 && teleportedToBeta == 2 && Partition == 0)
                {
                    cout << " Teleported [off] to port A!" << endl;//done
                    memory.push_back(0);
                }
                if(teleportedToAlpha == 1 && teleportedToBeta == 6 && Partition == 0)
                {
                    cout << " Teleported [on] to port A!" << endl;//done
                    memory.push_back(1);
                }
                if(teleportedToAlpha == 3 && teleportedToBeta == 2 && Partition == 0)
                {
                    cout << " Teleported [off] to port A!" << endl;//done
                    memory.push_back(0);
                }
                if(teleportedToAlpha == 3 && teleportedToBeta == 6 && Partition == 0)
                {
                    cout << " Teleported [on] to port A!" << endl;//done
                    memory.push_back(1);
                }

                //divide teleportation to two ports so computations can be done piecewise.
                if(teleportedToAlpha == 1 && teleportedToBeta == 2 && Partition == 1)
                {
                    cout << " Teleported [on] to port B!" << endl;//done
                    memory.push_back(1);
                }
                if(teleportedToAlpha == 1 && teleportedToBeta == 6 && Partition == 1)
                {
                    cout << " Teleported [on] to port B!" << endl;//done
                    memory.push_back(1);
                }
                if(teleportedToAlpha == 3 && teleportedToBeta == 2 && Partition == 1)
                {
                    cout << " Teleported [off] to port B!" << endl;//done
                    memory.push_back(0);
                }
                if(teleportedToAlpha == 3 && teleportedToBeta == 6 && Partition == 1)
                {
                    cout << " Teleported [off] to port B!" << endl;//done
                    memory.push_back(0);
                }
                if(teleportedToAlpha == 0 || teleportedToBeta == 0)
                {
                    cout << " In superposition" << endl;
                }
            }
        }
        //instead do memories & computations nonlocal to server(portA & portB) to maximise effect of quantum logic gate
        bool AND = false, OR = false, XOR = false;
        if(memory[n] == 1 && data[n] == 1)// should be done piecewise after dividing ports
        {
            AND = true, OR = true, XOR = false;
            cout << "AND = True" << endl;
            cout << "OR = True" << endl;
            cout << "XOR = False" << endl;
        }
        if(memory[n] == 0 && data[n] == 0)
        {
            AND = false, OR = false, XOR = false;
            cout << "AND = False" << endl;
            cout << "OR = False" << endl;
            cout << "XOR = False" << endl;
        }
        if(memory[n] == 1 && data[n] == 0)
        {
            AND = false, OR = true, XOR = true;
            cout << "AND = False" << endl;
            cout << "OR = True" << endl;
            cout << "XOR = True" << endl;
        }
        if(memory[n] == 0 && data[n] == 1)
        {
            AND = false, OR = true, XOR = true;
            cout << "AND = False" << endl;
            cout << "OR = True" << endl;
            cout << "XOR = True" << endl;
        }
        //once divided use data[n] & dataB[n] to check both doors at once...
        //logical errors should cancel when ports are piecewise rather than unfitting arrays...
        //insert program
        if(AND == true && n == 0)
        {

        }
        if(OR == true && n == 3)
        {

        }
        if(XOR == true && n == 5)
        {

        }

        //shift memory into data
        //if desired logic gate has the boolean value, use within a math problem...
        //check boolean values to see if program + data sucessfully ran.
        cout << endl;
        //communication is naturally 10,000 times faster due to speed of quantum entanglement(once memory and logic is in portA and portB)
        //by allowing both light valves to operate using a previous qubit independent of its own sequence, the activity can effectively link qubits together into a series causing non-linear exponentiality, each qubit is sequential, exponential and non-linear at the same time.
        //capable of sequential Turing machine operations on memory, all at once given enough linked qubits...
    }
    cout << "Output: math phenomena = true";
    //manually code program for linked qubits, process logical data according to program(all at once)...
    //A logic gate circuit should be constructed using multiple qubits
    return 0;
}
