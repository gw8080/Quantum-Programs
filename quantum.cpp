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
int iterations = 10;
using namespace std;
int LVA = 0;
int LVB = 0;
int delay = 40;//simulate bottleneck
long long int telestats = 0;
//using logic gate instructions distributed throughout data to process information with other data
// the basic concept of this quantum computer is an entangled state of the other port is known by detection of entanglement and therefore the time division multiplexing allows telportation of information and the activation of a logic gate via it's truth table implementation assuming correctly configured hardware
long long int stats = 0; // todo, implement extremely large numbers
vector<string> portA(int n,vector<int> dataA, int W,vector<string> instructions)//Sync n & Partition to time
{
    //decide what to do

    string binA = instructions[rand() % instructions.size()];
    vector<string> memory;
    for(int Partition = 0; Partition != 2; Partition++)
    {
        if(dataA[n] == binA.at(0)-48)
        {
            if(Partition == binA.at(1)-48)
            {
                LVA = binA.at(2)-48;//light valve activate according to configuration
                usleep(delay);
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead
                    ////cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
                    //TODO, implement logic gates using qubits to truth table and calibrate bits according to specific setup requirements
                    //n = qubit purpose

                    //example qubit-partition-LV-truth table configuration // qubits are required to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
                    //A = 0011 0100 1111 1000
                    //B = 0000 0111 1100 1011
                    //AND gate
                    //qubit + partition = alpha & beta
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(3)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
            if(Partition == binA.at(4)-48)
            {
                LVA = binA.at(5)-48;//light valve activate according to data
                usleep(delay);
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead
                    ////cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
                    //TODO, implement logic gates using qubits to truth table and calibrate bits according to specific setup requirements
                    //n = qubit purpose

                    //example qubit-partition-LV-truth table configuration // qubits are required to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
                    //A = 0011 0100 1111 1000
                    //B = 0000 0111 1100 1011
                    //AND gate
                    //qubit + partition = alpha & beta
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(6)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
        }
        if(dataA[n] == binA.at(7)-48)
        {
            if(Partition == binA.at(8)-48)
            {
                LVA = binA.at(9)-48;//light valve activate according to data
                usleep(delay);
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead
                    ////cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
                    //TODO, implement logic gates using qubits to truth table and calibrate bits according to specific setup requirements
                    //n = qubit purpose

                    //example qubit-partition-LV-truth table configuration // qubits are required to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
                    //A = 0011 0100 1111 1000
                    //B = 0000 0111 1100 1011
                    //AND gate
                    //qubit + partition = alpha & beta

                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(10)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
            if(Partition == binA.at(11)-48)
            {
                LVA = binA.at(12)-48;//light valve activate according to data
                usleep(delay);
                if(rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
                {
                    //check entanglement property and check time & partition information of the entanglement event instead
                    ////cout << "Cycle: " << T << ": " << Alpha << " " << Beta << endl;//if the cycle is linked to each qubit's light valves therefore data & dataB can have all combinations processed via T & partition almost instantly
                    //TODO, implement logic gates using qubits to truth table and calibrate bits according to specific setup requirements
                    //n = qubit purpose

                    //example qubit-partition-LV-truth table configuration // qubits are required to build logic gate therefore partition and LV configuration needs to construct it, with a matching truth table
                    //A = 0011 0100 1111 1000
                    //B = 0000 0111 1100 1011
                    //AND gate
                    //qubit + partition = alpha & beta
                    //cout << "Teleported [off/on] to port A!" << endl;
                    memory.push_back(to_string(binA.at(13)-48));//truth table
                    telestats++;
                    //example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
                }
            }
        }
    }
    return memory;//or modify data using fresh memory to do recursive operations
}
vector<string> portB( int n,vector<int> dataB, int W,vector<string> instructions)
{
    string binB = instructions[rand() % instructions.size()];
    vector<string> memory;
    for(int Partition = 0; Partition != 2; Partition++)
    {
        if(dataB[n] == binB.at(0)-48)
        {
            if(Partition == binB.at(1)-48)
            {
                LVB = binB.at(2)-48;
                usleep(delay);
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
                usleep(delay);
                if(rand() % 2 == 0)
                {
                    //cout << "Teleported [off/on] to port B!" << endl;
                    memory.push_back(to_string(binB.at(6)-48));
                    telestats++;
                }
            }
        }
        if(dataB[n] == binB.at(7)-48)
        {
            if(Partition == binB.at(8)-48)
            {
                LVB = binB.at(9)-48;
                usleep(delay);
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
                usleep(delay);
                if(rand() % 2 == 0)
                {
                    //cout << "Teleported [off/on] to port B!" << endl;
                    memory.push_back(to_string(binB.at(13)-48));
                    telestats++;
                }
            }
        }
    }
    return memory;
}
int main()//server
{
    int W = 4095;

    srand (time(NULL));

    vector<int> dataA  =//set data to be processed
    {
        1,0,1,1,
    };
    vector<int> dataB =
    {
        1,1,0,1,
    };
    cout << "QBOX terminal: " << dataA.size() << " Qubits " << endl;


    vector<string> instructionsA, instructionsB;//set instructions
    //------------------Experimental AND gate ------------------
    string binA = "0100001010101101"; // configuration code, should be of all binary combinations for the logic gate, each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port
    //48 is ascii for 0, 49 is 1
    string binB = "";//must be opposite of binA and each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port

    binB += "0";//data
    (binA.at(1) == 48) ? binB += "1" : binB += "0";//partition
    (binA.at(2) == 48) ? binB += "1" : binB += "0";//light valve
    binB += "0";//truth table

    binB += "1";//data
    (binA.at(5) == 48) ? binB += "1" : binB += "0";
    (binA.at(6) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table

    binB += "0";//data
    (binA.at(9) == 48) ? binB += "1" : binB += "0";
    (binA.at(10) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table

    binB += "1";//data
    (binA.at(13) == 48) ? binB += "1" : binB += "0";
    (binA.at(14) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table
    instructionsA.push_back(binA);
    instructionsB.push_back(binB);
//------------------Experimental AND gate ------------------

    //------------------Experimental memory transfer gate, essentially a controlled NOT quantum gate ------------------
    binA = "0100001100111101"; // configuration code, should be of all binary combinations for the logic gate, each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port
    //48 is ascii for 0, 49 is 1
    binB = "";//must be opposite of binA and each should be opposite when mirrored (from the center), except for [logic gate output] locations, which are distributed to each port

    binB += "0";//data
    (binA.at(1) == 48) ? binB += "1" : binB += "0";//partition
    (binA.at(2) == 48) ? binB += "1" : binB += "0";//light valve
    binB += "0";//truth table

    binB += "0";//data
    (binA.at(5) == 48) ? binB += "1" : binB += "0";
    (binA.at(6) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table

    binB += "1";//data
    (binA.at(9) == 48) ? binB += "1" : binB += "0";
    (binA.at(10) == 48) ? binB += "1" : binB += "0";
    binB += "0";//truth table

    binB += "1";//data
    (binA.at(13) == 48) ? binB += "1" : binB += "0";
    (binA.at(14) == 48) ? binB += "1" : binB += "0";
    binB += "1";//truth table
    instructionsA.push_back(binA);
    instructionsB.push_back(binB);
//------------------Experimental memory transfer gate ------------------

//set program
    vector<int> program = {1,6,21,6,1,7,32,7,2,6,2,8};//example program refers to each instruction performed on data linearly according to configuration
    for(int j = 1; j < iterations+1; j++)//select different logic gates per iteration
    {
        //cout << "port A configuration: " << binA;
        vector<string> outputA;
        vector<string> outputB;
        for(int n = 0; n < dataA.size(); n++)
        {
            //cout << endl  << "______________________" << endl << "New qubit, n = " << n << endl << "______________________" << endl;

            vector<int> output;
            stats+=pow (dataA.size(), dataA.size())/dataA.size()/dataA.size();

            vector<string> proc = portA(n,dataA,W,instructionsA);//upload configuration
            outputA.insert(outputA.end(), proc.begin(), proc.end());//transfer entire function to physical unit with own time evolution, operate in parallel
            proc = portB(n,dataB,W,instructionsB);
            outputB.insert(outputB.end(), proc.begin(), proc.end());//transfer entire function to physical unit with own time evolution, operate in parallel
            cout << endl << "Qubit: " << n << endl;
            cout << "Configuration A: " << binA << endl;
            cout << "Configuration B: " << binB << endl;

            cout <<  "dataA: ";
            for(int f = 0; f < dataA.size(); f++)
            {
                cout << dataA[f];
            }
            cout << endl;

            cout << "dataB: ";
            for(int f = 0; f < dataB.size(); f++)
            {
                cout << dataB[f];
            }
            cout << endl;



            //instead do memories & computations nonlocal to server(portA & portB) to maximise effect of quantum logic gate
            //done straight after teleportation

            //once divided use data[n] & dataB[n] to check both doors at once and combine information instantly...
            //load data
            //shift memory into data after doing multiple boolean operations
            //if desired logic gate has the boolean value, use within a math problem...
            //check boolean values to see if program + data successfully ran.
            //communication is naturally 10,000 times faster due to speed of quantum entanglement(once memory and logic is in portA and portB)
            //by allowing both light valves to operate using a previous qubit independent of its own sequence, the activity can effectively link qubits together into a series causing non-linear exponentiality, each qubit is sequential, exponential and non-linear at the same time.
            //capable of sequential Turing machine operations on memory, all at once given enough linked qubits...
        }

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
    }
    //manually code program for linked qubits, process logical data according to program(all at once)...
    //A logic gate circuit should be constructed using multiple qubits
    cout << "total qubit activations: " << dataA.size()*iterations << " in " << iterations << " iterations, " << " Total teleportations/Logic gate activations " << telestats << endl;
    return 0;
}
