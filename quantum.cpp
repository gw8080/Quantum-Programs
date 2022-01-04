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
#include <sstream>
#include <bits/stdc++.h>
int stages = 10;
using namespace std;
int LVA = 0;
int LVB = 0;
//using logic gate instructions distributed throughout qubits to process information within other qubits
long long int stats = 0; // todo, implement extremely large numbers
vector<int> data  =
{
    0,1,1,0,
    1,0,1,1,
};//instead place in portA. cycle program, done instantly(qubits/combinations)
vector<int> dataB =
{
    1,0,0,1,
    0,1,0,0,
};//instead place in portB. cycle data, done instantly(qubits/combinations)
int portA(int T, int Partition, int n,vector<int> data)//Sync X & Y to time
{
    vector<string> memory;
    //do calculation
    int qubit = data[n];//entangled bit/Turing strip
    vector<int> ratios = { 1,2};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 = 3,6,9 works //iterate this
    int A = 1;
    int C = 3; // result, shared by both ports
    if(qubit == 0)
    {
        if(Partition == 0)
        {

            A = 1;
            C = 3;
            LVA = 1;//light valve activate according to data
        }
        if(Partition == 1)
        {

            A = 3;
            C = 9;
            LVA = 0;//light valve deactivate according to data
        }
    }
    if(qubit == 1)
    {
        if(Partition == 1)
        {

            A = 1;
            C = 3;
            LVA = 1;//light valve activate according to data
        }
        if(Partition == 0)
        {

            A = 3;
            C = 9;
            LVA = 0;//light valve deactivate according to data
        }
    }
    if(rand() % 2 == Partition)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
    {
        //check entanglement property and check time & partition information of the entanglement event instead
        int Alpha = A;
        int Beta =  A*ratios[T];

        //cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
        if(Alpha == 0 || Beta == 0)
        {
            //cout << " In superposition" << endl;
        }
        //TODO, calculate logic gates using qubits
        if(Alpha == 1 && Beta == 2 && Partition == 1)
        {
            //cout << " Teleported [on] to port A!" << endl;//done
            memory.push_back("1");
        }
        if(Alpha == 1 && Beta == 6 && Partition == 1)
        {
            //cout << " Teleported [on] to port A!" << endl;//done
            memory.push_back("1");
        }
        if(Alpha == 3 && Beta == 2 && Partition == 1)
        {
            //cout << " Teleported [off] to port A!" << endl;//done
            memory.push_back("0");
        }
        if(Alpha == 3 && Beta == 6 && Partition == 1)
        {
            //cout << " Teleported [off] to port A!" << endl;//done
            memory.push_back("0");
        }

        return (A*ratios[T]);//math simulates quantum entanglement
        //return state 1 or state 2
    }
    return 0;
}
int portB(int T, int Partition,int n,vector<int> data)//Sync X & Y to time
{
    vector<string> memory;
    //do calculation
    int qubit = data[n];//entangled bit/Turing strip
    vector<int> ratios = { 1,2};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 = 3,6,9 works //iterate this
    int B = 2;
    int C = 3; // result, shared by both ports
    if(qubit == 0)
    {
        if(Partition == 0)
        {
            B = 2;
            C = 3; // result, shared by both ports
            LVB = 0;//light valve deactivate according to data
        }
        if(Partition == 1)
        {
            B = 6;
            C = 9; // result, shared by both ports
            LVB = 1;//light valve activate according to data
        }
    }
    if(qubit == 1)
    {
        if(Partition == 1)
        {
            B = 2;
            C = 3; // result, shared by both ports
            LVB = 0;//light valve deactivate according to data
        }
        if(Partition == 0)
        {
            B = 6;
            C = 9; // result, shared by both ports
            LVB = 1;//light valve activate according to data
        }
    }
    if(rand() % 2 == Partition)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
    {
        //check entanglement property and check time & partition information of the entanglement event instead
        int Alpha = B/ratios[T];
        int Beta =  B;

        //cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
        if(Alpha == 0 || Beta == 0)
        {
            //cout << " In superposition" << endl;
        }
        //TODO, calculate logic gates using qubits
        if(Alpha == 1 && Beta == 2 && Partition == 0)
        {
            //cout << " Teleported [off] to port B!" << endl;
            memory.push_back("0");
        }
        if(Alpha == 1 && Beta == 6 && Partition == 0)
        {
            //cout << " Teleported [on] to port B!" << endl;
            memory.push_back("1");
        }
        if(Alpha == 3 && Beta == 2 && Partition == 0)
        {
            //cout << " Teleported [off] to port B!" << endl;
            memory.push_back("0");
        }
        if(Alpha == 3 && Beta == 6 && Partition == 0)
        {
            //cout << " Teleported [on] to port B!" << endl;
            memory.push_back("1");
        }
        return (B/ratios[T]);//math simulates quantum entanglement
        //return state 1 or state 2
    }
    return 0;
}
int main()//server
{
    //cout << "QBOX terminal: " << data.size() << " Qubits " << endl;
    vector<int> output;

    srand (time(NULL));
    vector<int> ratios = {1,2};//use float for more precision
    //cout << "logical errors should be solved when ports are piecewise rather than using unfitting arrays when simulating..." << endl;
    for(int j = 1; j < stages+1; j++)
    {
        //cout << "Input A: ";
        for(int n = 0; n < data.size(); n++)
        {
            //cout << data[n];
        }
        //cout << endl;
        //cout << "Input B: ";
        for(int n = 0; n < dataB.size(); n++)
        {
            //cout << dataB[n];
        }
        //cout << endl;
        for(int n = 0; n < data.size(); n++)
        {
            //cout << "New qubit, n = " << n << "(effects are simultaneous on quantum hardware)" << endl;
            for(int Partition = 0; Partition < 2; Partition++)
            {
                for(int T = 0; T < ratios.size(); T++)
                {
                    stats+=pow (data.size(), data.size())/data.size()/data.size();
                    portA(T,Partition,n,data);//transfer entire function to physical unit with own time evolution, operate in parallel
                    //cout <<  "_________________________________________" << endl;
                    portB(T,Partition,n,dataB);//transfer entire function to physical unit with own time evolution, operate in parallel

                }
            }
            //instead do memories & computations nonlocal to server(portA & portB) to maximise effect of quantum logic gate
            //done straight after teleportation

            //once divided use data[n] & dataB[n] to check both doors at once and combine information instantly...
            //load data
            //shift memory into data after doing multiple boolean operations
            //if desired logic gate has the boolean value, use within a math problem...
            //check boolean values to see if program + data sucessfully ran.
            //cout << endl;
            //communication is naturally 10,000 times faster due to speed of quantum entanglement(once memory and logic is in portA and portB)
            //by allowing both light valves to operate using a previous qubit independent of its own sequence, the activity can effectively link qubits together into a series causing non-linear exponentiality, each qubit is sequential, exponential and non-linear at the same time.
            //capable of sequential Turing machine operations on memory, all at once given enough linked qubits...
        }
        //cout << "Stage: " << j << ", Total cycles, classical equivalent: " << ((stats)*(data.size()/2))/2 << endl << "_________________________________________" << endl;
    }
    //manually code program for linked qubits, process logical data according to program(all at once)...
    //A logic gate circuit should be constructed using multiple qubits
    return 0;
}
