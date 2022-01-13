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
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int delay = 9000;//simulate bottleneck in microseconds
long long int telestats = 0;
long long int stats = 0;
//using logic gate instructions distributed throughout data to process information with other data
// the basic concept of this quantum computer is an entangled state of the other port is known by detection of entanglement and therefore the time division multiplexing allows telportation of information and the activation of a logic gate via it's truth table implementation assuming correctly configured hardware
vector<string> portA(int X,vector<string> configuration,vector<int> program)//Sync n & Partition to time
{
    int LVA = 0, LVB = 0;
    //decide what to do
    vector<int> dataA  =//set data to be processed
    {
        1,0,1,1
    };

    for(int f = 0; f < dataA.size(); f++)
    {
        cout << dataA[f];
    }
    cout << endl;
    string binA = configuration[program[X]];
    vector<string> memory;
    for(int Partition = 0; Partition != 2; Partition++)
    {
        if(dataA[X] == binA.at(0)-48)
        {
            if(Partition == binA.at(1)-48)
            {
                LVA = binA.at(2)-48;//light valve activate according to configuration
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(3)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
            if(Partition == binA.at(4)-48)
            {
                LVA = binA.at(5)-48;//light valve activate according to data
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
//check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(6)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
        }
        if(dataA[X] == binA.at(7)-48)
        {
            if(Partition == binA.at(8)-48)
            {
                LVA = binA.at(9)-48;//light valve activate according to data
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(10)-48));//truth table
                    telestats++;
                }
            }
            if(Partition == binA.at(11)-48)
            {
                LVA = binA.at(12)-48;//light valve activate according to data
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(13)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
        }
        usleep(delay);//for partition space
    }
    return memory;//or modify data using fresh memory to do recursive operations
}
vector<string> portB(int X,vector<string> configuration,vector<int> program)
{
    int LVA = 0, LVB = 0;
    vector<int> dataB =
    {
        1,1,0,1
    };
    for(int f = 0; f < dataB.size(); f++)
    {
        cout << dataB[f];
    }

    string binB = configuration[program[X]];
    vector<string> memory;
    for(int Partition = 0; Partition != 2; Partition++)
    {

        if(dataB[X] == binB.at(0)-48)
        {
            if(Partition == binB.at(1)-48)
            {
                LVB = binB.at(2)-48;
                if(rand() % 2 == 0)
                {
                    //cout << "Teleported [off/on] to port B!" << endl;
                    memory.push_back(to_string(binB.at(3)-48));
                    telestats++;
                }
            }
            if(Partition == binB.at(4)-48)
            {
                LVB = binB.at(5)-48;
                if(rand() % 2 == 0)
                {
                    //cout << "Teleported [off/on] to port B!" << endl;
                    memory.push_back(to_string(binB.at(6)-48));
                    telestats++;
                }
            }
        }
        if(dataB[X] == binB.at(7)-48)
        {
            if(Partition == binB.at(8)-48)
            {
                LVB = binB.at(9)-48;
                if(rand() % 2 == 0)
                {
                    //cout << "Teleported [off/on] to port B!" << endl;
                    memory.push_back(to_string(binB.at(10)-48));
                    telestats++;
                }
            }
            if(Partition == binB.at(11)-48)
            {
                LVB = binB.at(12)-48;
                if(rand() % 2 == 0)
                {
                    //cout << "Teleported [off/on] to port B!" << endl;
                    memory.push_back(to_string(binB.at(13)-48));
                    telestats++;
                }
            }
        }
        usleep(delay);
    }
    return memory;
}
int main()//server
{
    srand (time(NULL));
    cout << "Qubox terminal";
    vector<string> configurationA, configurationB;//set config
    //------------------Experimental AND gate ------------------
    //segment according to pattern 4,3,4,3 part of the mirrored configuration is dropped, eg "0100 010 1010 101"
    string binA = "01000101010101"; // configuration code, should be of all binary combinations for the logic gate, each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port
    //48 is ascii for 0, 49 is 1
    string binB = "";//must be opposite of binA and each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port

    binB += "0";//data
    (binA.at(1) == 48) ? binB += "1" : binB += "0";//partition
    (binA.at(2) == 48) ? binB += "1" : binB += "0";//light valve
    binB += "0";//truth table

    (binA.at(4) == 48) ? binB += "1" : binB += "0";
    (binA.at(5) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table

    binB += "0";//data
    (binA.at(8) == 48) ? binB += "1" : binB += "0";
    (binA.at(9) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table

    (binA.at(11) == 48) ? binB += "1" : binB += "0";
    (binA.at(12) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table
    configurationA.push_back(binA);
    configurationB.push_back(binB);
//------------------Experimental AND gate ------------------
//------------------Experimental XOR gate ------------------
    binA = "01000111011100"; // configuration code, should be of all binary combinations for the logic gate, each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port
    //48 is ascii for 0, 49 is 1
    binB = "";//must be opposite of binA and each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port

    binB += "0";//data
    (binA.at(1) == 48) ? binB += "1" : binB += "0";//partition
    (binA.at(2) == 48) ? binB += "1" : binB += "0";//light valve
    binB += "0";//truth table

    (binA.at(4) == 48) ? binB += "1" : binB += "0";
    (binA.at(5) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table

    binB += "0";//data
    (binA.at(8) == 48) ? binB += "1" : binB += "0";
    (binA.at(9) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table

    (binA.at(11) == 48) ? binB += "1" : binB += "0";
    (binA.at(12) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table
    configurationA.push_back(binA);
    configurationB.push_back(binB);
//------------------Experimental XOR gate ------------------
    //------------------Experimental memory transfer gate, essentially a controlled NOT quantum gate ------------------
    binA = "01000110011101"; // configuration code, should be of all binary combinations for the logic gate, each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port
    //48 is ascii for 0, 49 is 1
    binB = "";//must be opposite of binA and each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port

    binB += "0";//data
    (binA.at(1) == 48) ? binB += "1" : binB += "0";//partition
    (binA.at(2) == 48) ? binB += "1" : binB += "0";//light valve
    binB += "0";//truth table

    (binA.at(4) == 48) ? binB += "1" : binB += "0";
    (binA.at(5) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table

    binB += "1";//data
    (binA.at(8) == 48) ? binB += "1" : binB += "0";
    (binA.at(9) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table

    (binA.at(11) == 48) ? binB += "1" : binB += "0";
    (binA.at(12) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table
    configurationA.push_back(binA);
    configurationB.push_back(binB);
//------------------Experimental memory transfer gate ------------------

//set program
//0 = AND, 1 = XOR, 2 = CNOT, 3 =  transfer output to data , 4 = iterate whole program once, 5 = if statement using next instruction if true, 6 = else if statement, 7 = end if statement, 8 = perform half/full adder on next 8 bits of data
    vector<int> programA = {0,0,0,0};//example program refers to each instruction performed on data linearly according to configuration
    vector<int> programB = {1,1,1,1};//example program refers to each instruction performed on data linearly according to configuration

    //cout << "port A configuration: " << binA;
    vector<string> outputA;
    vector<string> outputB;
    for(int X = 0; X != programA.size(); X++)
    {
        cout << endl << "Qubit: " << X << endl;
        //cout << endl  << "______________________" << endl << "New qubit, n = " << n << endl << "______________________" << endl;
        vector<string> proc = portA(X,configurationA,programA);//upload configuration
        outputA.insert(outputA.end(), proc.begin(), proc.end());
        proc = portB(X,configurationB,programB);
        outputB.insert(outputB.end(), proc.begin(), proc.end());

    }
    cout << endl;
    cout << "MemoryA: ";
    for(int f = 0; f != outputA.size(); f++)
    {
        cout << outputA[f];
    }
    cout << endl;
    cout << "MemoryB: ";
    for(int f = 0; f != outputB.size(); f++)
    {
        cout << outputB[f];
    }
    cout << endl;
    //cout << "Stage: " << j << ", Total cycles, classical equivalent: " << ((stats)*(data.size()/2))/2 << endl << "_________________________________________" << endl;
    //manually code program for linked qubits, process logical data according to program(all at once)...
    //A logic gate circuit should be constructed using multiple qubits
    cout << endl << " Total teleportations/Logic gate activations " << telestats << endl;
    return 0;
}
