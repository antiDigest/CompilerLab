#include "iostream"
#include "cstring"
#include "sstream"
#include "fstream"
#include "string"

#define EMPTY -99

#define STATE 4
#define ALPHA 3

#define INPUT_FILE ("lex_input.txt")
#define AUTOMATA ("automata_input.txt")

int automata[STATE][ALPHA];
int initial;
int final[STATE];

int main(){
	ifstream in(AUTOMATA);

	in >> initial;

	for(int i=0;i<STATE;i++)
		final[i]=EMPTY;

	string line;

	getline(in,line);
	istringstream line_stream(line);
	string cell;
	i=0;
	while(getline(line_stream,cell,' ')){
		final[i] = atoi(cell.c_str());
		i++;
	}

	i=0;
	while(getline(in,line)){

		istringstream line_stream(line);
		string cell;

		int j=0;
		while(getline(line_stream,cell,' ')){
			automata[i][j] = atoi(cell.c_str());
			j++;
		}
		i++;
	}

}
