#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define EMPTY -99

#define STATE 8
#define ALPHA 2

#define INPUT_FILE ("input_dfa.txt")

int dfa[STATE][ALPHA];
int initial;
int final[STATE];
int is_same[20][20];

int main(){
	int i,j,k;
	ifstream in(INPUT_FILE);

	for(i=0;i<STATE;i++){
		final[i]=EMPTY;
	}

	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			dfa[i][j] = EMPTY;

	string line;

	getline(in,line);
	initial = atoi(line.c_str());

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

		j=0;
		while(getline(line_stream,cell,' ')){
			dfa[i][j] = atoi(cell.c_str());
			j++;
		}
		i++;
	}

	cout<<"\ta\tb\n";
	for(i=0;i<STATE;i++){
		cout<<i<<"\t";
		for(j=0;j<ALPHA;j++)
			cout<<dfa[i][j]<<"\t";
		cout<<endl;
	}
}