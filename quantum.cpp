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
//separate port A and port B, include server at each end
//to access the full potential of multiple qubits, true instantaneous function rather than sequential instantaneous function across all qubits, requires implementation parametric down conversion.
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
    0,0,1,1,
};//instead place in portA. cycle program, done instantly(qubits/combinations)
vector<int> dataB =
{
    0,1,0,1,
};//instead place in portB. cycle data, done instantly(qubits/combinations)
vector<string> portA(int T, int Partition, int n,vector<int> data, int W,string binA)//Sync X & Y to time
{
    vector<string> memory;
    //do calculation
    int qubit = data[n];//entangled bit/Turing strip
    vector<int> ratios = { 1,2};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 = 3,6,9 works //iterate this
    int A = 1;
    int C = 3; // result, shared by both ports
    if(qubit == binA.at(0)-48)
    {
        if(Partition == binA.at(1)-48)
        {

            A = 1;
            C = 3;
            LVA = binA.at(2)-48;//light valve activate according to data
        }
        if(Partition == binA.at(3)-48)
        {

            A = 3;
            C = 9;
            LVA = binA.at(4)-48;//light valve deactivate according to data
        }
    }
    if(qubit == binA.at(5)-48)
    {
        if(Partition == binA.at(6)-48)
        {

            A = 1;
            C = 3;
            LVA = binA.at(7)-48;//light valve activate according to data
        }
        if(Partition == binA.at(8)-48)
        {

            A = 3;
            C = 9;
            LVA = binA.at(9)-48;//light valve deactivate according to data
        }
    }
    if(rand() % 2 == Partition)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
    {
        //check entanglement property and check time & partition information of the entanglement event instead
        int Alpha = A;
        int Beta =  A*ratios[T];

        cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
        if(Alpha == 0 || Beta == 0)
        {
            cout << " In superposition" << endl;
        }
        //TODO, implement logic gates using qubits to truth table and calibrate bits according to specific setup requirements
        //n = qubit purpose

        //example qubit-partition-LV-truth table configuration // qubits are required to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
        //A = 0011 0100 1111 1000
        //B = 0000 0111 1100 1011
        //AND gate
        //qubit + partition = alpha & beta
        if(Alpha == 1 && Beta == 2)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port A!" << endl;
            memory.push_back(to_string(binA.at(10)-48));//truth table
        }
        if(Alpha == 1 && Beta == 6)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port A!" << endl;
            memory.push_back(to_string(binA.at(11)-48));//truth table
        }
        if(Alpha == 3 && Beta == 2)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port A!" << endl;
            memory.push_back(to_string(binA.at(12)-48));//truth table
        }
        if(Alpha == 3 && Beta == 6)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port A!" << endl;
            memory.push_back(to_string(binA.at(13)-48));//truth table
        }
    }
    return memory;
}
vector<string> portB(int T, int Partition,int n,vector<int> data, int W,string binB)//Sync X & Y to time
{
    vector<string> memory;
    //do calculation
    int qubit = data[n];//entangled bit/Turing strip
    vector<int> ratios = { 1,2};
    //state:  A + B = C
    //state 1 = 1,2,3 & state 2 = 3,6,9 works //iterate this
    int B = 2;
    int C = 3; // result, shared by both ports
    if(qubit == binB.at(0)-48)
    {
        if(Partition == binB.at(1)-48)
        {
            B = 2;
            C = 3; // result, shared by both ports
            LVB = binB.at(2)-48;//light valve deactivate according to data
        }
        if(Partition == binB.at(3)-48)
        {
            B = 6;
            C = 9; // result, shared by both ports
            LVB = binB.at(4)-48;//light valve activate according to data
        }
    }
    if(qubit == binB.at(5)-48)
    {
        if(Partition == binB.at(6)-48)
        {
            B = 2;
            C = 3; // result, shared by both ports
            LVB = binB.at(7)-48;//light valve deactivate according to data
        }
        if(Partition == binB.at(8)-48)
        {
            B = 6;
            C = 9; // result, shared by both ports
            LVB = binB.at(9)-48;//light valve activate according to data
        }
    }
    if(rand() % 2 == Partition)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
    {
        //check entanglement property and check time & partition information of the entanglement event instead
        int Alpha = B/ratios[T];
        int Beta =  B;

        cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
        if(Alpha == 0 || Beta == 0)
        {
            cout << "In superposition" << endl;
        }
        //TODO, implement logic gates using qubits to truth table and calibrate bits according to specific setup requirements
        //n = qubit purpose

        //example qubit-partition-LV-truth table configuration // qubits are required to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
        //A = 0011 0100 1111 1000
        //B = 0000 0111 1100 1011
        //AND gate
        //qubit + partition = alpha & beta
        if(Alpha == 1 && Beta == 2)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port B!" << endl;
            memory.push_back(to_string(binB.at(10)-48));//truth table
        }
        if(Alpha == 1 && Beta == 6)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port B!" << endl;
            memory.push_back(to_string(binB.at(11)-48));//truth table
        }
        if(Alpha == 3 && Beta == 2)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port B!" << endl;
            memory.push_back(to_string(binB.at(12)-48));//truth table
        }
        if(Alpha == 3 && Beta == 6)//do not change unless absolutely necessary
        {
            cout << "Teleported [off/on] to port B!" << endl;
            memory.push_back(to_string(binB.at(13)-48));//truth table
        }
    }
    return memory;
}
int main()//server
{
    int W = 0;
    cout << "QBOX terminal: " << data.size() << " Qubits " << endl;
    vector<int> output;

    srand (time(NULL));
    vector<int> ratios = {1,2};//use float for more precision
    for(int j = 1; j < stages+1; j++)
    {
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
        string binA = bitset<14>(W).to_string();
        string binB = bitset<14>(W).to_string();
        //binA = 00000000000000 // calibration code
        //binB = 00000000000000 // calibration code
        W++;
        cout << "port A configuration: " << binA;

        vector<string> outputA;
        vector<string> outputB;
        for(int n = 0; n < data.size(); n++)
        {
            cout << endl << "New qubit, n = " << n << "(effects are simultaneous on quantum hardware)" << endl;
            for(int Partition = 0; Partition < 2; Partition++)// use timing in port instead
            {
                for(int T = 0; T < ratios.size(); T++)//use timing in port instead
                {
                    stats+=pow (data.size(), data.size())/data.size()/data.size();
                    vector<string> proc = portA(T,Partition,n,data,W,binA);
                    outputA.insert(outputA.end(), proc.begin(), proc.end());//transfer entire function to physical unit with own time evolution, operate in parallel
                    proc = portB(T,Partition,n,data,W,binB);
                    outputB.insert(outputB.end(), proc.begin(), proc.end());//transfer entire function to physical unit with own time evolution, operate in parallel
                    cout << "data: ";
                    for(int f = 0; f < data.size(); f++)
                    {
                        cout << data[f];
                    }
                    cout << " dataB: ";
                    for(int f = 0; f < dataB.size(); f++)
                    {
                        cout << dataB[f];
                    }
                    cout << endl;
                    if(outputA.size() > 0 && outputB.size() > 0)
                    {
                        cout << endl << "portA: " << outputA[0] << " portB: " << outputB[0] << endl; // check configuration
                    }
                }
            }
            //instead do memories & computations nonlocal to server(portA & portB) to maximise effect of quantum logic gate
            //done straight after teleportation

            //once divided use data[n] & dataB[n] to check both doors at once and combine information instantly...
            //load data
            //shift memory into data after doing multiple boolean operations
            //if desired logic gate has the boolean value, use within a math problem...
            //check boolean values to see if program + data sucessfully ran.
            //communication is naturally 10,000 times faster due to speed of quantum entanglement(once memory and logic is in portA and portB)
            //by allowing both light valves to operate using a previous qubit independent of its own sequence, the activity can effectively link qubits together into a series causing non-linear exponentiality, each qubit is sequential, exponential and non-linear at the same time.
            //capable of sequential Turing machine operations on memory, all at once given enough linked qubits...
        }

        cout << "Stage: " << j << ", Total cycles, classical equivalent: " << ((stats)*(data.size()/2))/2 << endl << "_________________________________________" << endl;
    }
    //manually code program for linked qubits, process logical data according to program(all at once)...
    //A logic gate circuit should be constructed using multiple qubits
    return 0;
}
