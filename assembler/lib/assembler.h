#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "parser.h"
#include "shared.h"

using namespace std;

class Assembler
{
public:
	Assembler(string _inName, string _outName);
	~Assembler();

	void run(void);
private:
	void checkError(int code, string line);
	void checkLabel(int code, string line);
	void createLabels();
	void createDefines();
	void writeDefines();

	string writeDInstruction(Command command, string line);
	string writeRInstruction(Command command, string line);
	string writeCInstruction(Command command, string line);
	string writeJInstruction(Command command, string line);
	string writeTInstruction(Command command, string line);
	string writeWInstruction(Command command, string line);
	
	string toBinary(int value);

	// Parser
	Parser *parser;
	// Shared
	Shared *shared;

	// Input/Output files
	string inName;
	string outName;
	ifstream in;
	ofstream out;

	// Counters
	int lineCounter;
};
#endif// ASSEMBLER_H
