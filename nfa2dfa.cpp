#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define EMPTY -99

#define STATE 3
#define ALPHA 2

#define INPUT_FILE ("innfa.txt")

int automata[STATE][ALPHA][STATE];
int initial;
int final[STATE];
int state;

int main(){
	int i,j,k;
	const char *inval;
	int flag=0;
	ifstream in(INPUT_FILE);

	for(i=0;i<STATE;i++)
		final[i]=EMPTY;

	for(i=0;i<STATE;i++)
		for(j=0;j<ALPHA;j++)
			for(k=0;k<STATE;k++)
				automata[i][j][k] = EMPTY;

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

			istringstream cell_stream(cell);
			string val;

			k=0;
			while(getline(cell_stream,val,',')){
				automata[i][j][k] = atoi(val.c_str());
				k++;
			}
			j++;
		}
		i++;
	}

	cout<<"Automata : \n\n";
	cout<<"\ta\tb\n";
	for(i=0;i<STATE;i++){
		cout<<"q"<<i<<"\t";
		for(j=0;j<ALPHA;j++){
			for(k=0;k<STATE && automata[i][j][k]!=EMPTY;k++)
				cout<<automata[i][j][k]<<",";
			cout<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n\n";

	

}
