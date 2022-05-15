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
using namespace std;
int delay = 2;//simulate bottleneck in microseconds
long long int telestats = 0;
long long int stats = 0;
long long int n = 0;
//light valve consists of a optical switch and an inline polariser
//using logic gate instructions distributed throughout data to process information with other data
// the basic concept of this quantum computer is an entangled state of the other port is known by detection of entanglement and therefore the time division multiplexing allows telportation of information and the activation of a logic gate via it's truth table implementation assuming correctly configured hardware
vector<int> portA(long long int X, long long int Y, vector<string> configuration, vector<int> program, vector<int> data)//Sync n & Partition to time
{
	vector<int> memory;
	int LVA = 0, LVB = 0;
	string binA = configuration[program[X]];
	for (int Partition = 0; Partition != 2; Partition++)
	{
		if (data[Y] == binA.at(0) - 48)
		{
			if (Partition == binA.at(1) - 48)
			{
				LVA = binA.at(2) - 48;//light valve activate according to configuration
				if (rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
				{
					//check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
					//cout << "Teleported [off/on] to port A!" << endl;
					memory.push_back(binA.at(3) - 48);//truth table
					telestats++;
					break;
					//example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
				}
			}
			if (Partition == binA.at(4) - 48)
			{
				LVA = binA.at(5) - 48;//light valve activate according to data
				if (rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
				{
					//check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
										//cout << "Teleported [off/on] to port A!" << endl;
					memory.push_back(binA.at(6) - 48);//truth table
					telestats++;
					break;
					//example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
				}
			}
		}
		if (data[Y] == binA.at(7) - 48)
		{
			if (Partition == binA.at(8) - 48)
			{
				LVA = binA.at(9) - 48;//light valve activate according to data
				if (rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
				{
					//check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
					//cout << "Teleported [off/on] to port A!" << endl;
					memory.push_back(binA.at(10) - 48);//truth table
					telestats++;
					break;
				}
			}
			if (Partition == binA.at(11) - 48)
			{
				LVA = binA.at(12) - 48;//light valve activate according to data
				if (rand() % 2 == 0)// detect photon source(other port should detect too, when they correlate, interesting things start to happen, requires parallel processes, but for now it is simulating using randomness)
				{
					//check entanglement property and check time & partition information of the entanglement event instead, assign to truth table equivalent to a logic gate operation
					//cout << "Teleported [off/on] to port A!" << endl;
					memory.push_back(binA.at(13) - 48);//truth table
					telestats++;
					break;
					//example memory copy, use B/ratios[T] to determine qubit then use a NOT gate to fashion new bit, save to portA/portB
				}
			}
		}
		delay; //partition space on quantum hardware
	}
	return memory;
}
vector<int> portB(long long int X, long long int Y, vector<string> configuration, vector<int> program, vector<int> data)
{
	vector<int> memory;

	int LVA = 0, LVB = 0;
	string binB = configuration[program[X]];
	for (int Partition = 0; Partition != 2; Partition++)
	{
		if (data[Y] == binB.at(0) - 48)
		{
			if (Partition == binB.at(1) - 48)
			{
				LVB = binB.at(2) - 48;
				if (rand() % 2 == 0)
				{
					//cout << "Teleported [off/on] to port B!" << endl;
					memory.push_back(binB.at(3) - 48);
					telestats++;
					break;
				}
			}
			if (Partition == binB.at(4) - 48)
			{
				LVB = binB.at(5) - 48;
				if (rand() % 2 == 0)
				{
					//cout << "Teleported [off/on] to port B!" << endl;
					memory.push_back(binB.at(6) - 48);
					telestats++;
					break;
				}
			}
		}
		if (data[Y] == binB.at(7) - 48)
		{
			if (Partition == binB.at(8) - 48)
			{
				LVB = binB.at(9) - 48;
				if (rand() % 2 == 0)
				{
					//cout << "Teleported [off/on] to port B!" << endl;
					memory.push_back(binB.at(10) - 48);
					telestats++;
					break;
				}
			}
			if (Partition == binB.at(11) - 48)
			{
				LVB = binB.at(12) - 48;
				if (rand() % 2 == 0)
				{
					//cout << "Teleported [off/on] to port B!" << endl;
					memory.push_back(binB.at(13) - 48);
					telestats++;
					break;
				}
			}
		}
		delay;//partition space on quantum hardware
	}
	return memory;
}
int main()//server
{
	srand(time(NULL));
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
	//0 = AND, 1 = XOR, 2 = CNOT , 3 = iterate whole program once with new data, 4 = if statement using next instruction if true, 5 = else if statement, 6 = end if statement
	vector<int> programA = { 1,1,1,2 };//example program refers to each instruction performed on data linearly according to configuration
	vector<int> programB = { 0,0,0,2 };//example program refers to each instruction performed on data linearly according to configuration
	vector<int> dataA =//set data to be processed, store numbers, etc
	{
		1,1,1,1
	};
	vector<int> dataB =
	{
		1,1,1,1
	};
	//stored values as binary data can be checked using QPU's using an equivalence gate, matched against a binary data packet for assurance
	//upload configuration, work on not requiring reflashing per program step
	//add arithmetic iterator, subtraction and addition can be achieved by quantum gates and data, multiplication and division can be achieved doing the same, repeatedly.
	//port(program step, data step, configuration,program,data)
	//greater than is,[XOR],[result,data, AND] to determine first discrepancy in right sweep of binary data
	//portA, dataA 00000111 = 1
	//portB, dataB 00010111 = 0
	//may produce errors in simulator
	//requires factoring in the teleport, discreteness limitation cannot satisfy parallel coherence
	for (int m = 0; m < dataA.size(); m++) {
		vector<int> resultA = portA(1, m, configurationA, programA, dataA);//time-crystal-like causal ordering, repeats pattern among TDM(time domain multiplexing)
		vector<int> resultB = portB(0, m, configurationB, programA, resultA);
		if (resultB[0] == 1) {
			cout << "dataB is higher";
			break;
		}
		if (resultB[0] == 0) {
			cout << "dataA is higher";
			break;
		}
	}
	//cout << "Stage: " << j << ", Total cycles, classical equivalent: " << ((stats)*(data.size()/2))/2 << endl << "_________________________________________" << endl;
	//manually code program for linked qubits, process logical data according to program(all at once)...
	//A logic gate circuit should be constructed using multiple qubits
	cout << endl << "Total teleportations/Logic gate activations " << telestats << endl;
	return 0;
}
