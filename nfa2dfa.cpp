#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define M 4
#define N 2

int main(){
	int fs, kali;
	int regex[10][10][10];
	int i,j, initial, final[10], k,m, flag=0, state, stin,l;
	char inval[10];
	char val[100];
	const char *temp;

	ifstream in("innfa.txt");

	in>>initial;

    for (i=0;i<10;i++)
        for (j=0;j<10;j++)
            for (k=0;k<10;k++)
                regex[i][j][k]=-2;

	i=0;
	while(1){
		in>>fs;
		if(fs==-1){
			break;
		}
		final[i] = fs;
		i++;
	}

	m=i;
    k=0;
	for (i=0;i<M;i++)
		for (j=0;j<N;j++){
            in>>val;
            k=0;
            l=0;
            std::string input = val;
            std::istringstream ss(input);
            std::string token;

            while(std::getline(ss, token, ',')) {
                temp = token.c_str();
                regex[i][j][k] = atoi(temp);
                //std::cout << token << '\n';
                k++;
            }
        }

    for (i=0;i<M;i++){
        for (j=0;j<N;j++){
            for (k=0;regex[i][j][k]!=-2;k++)
                cout<<regex[i][j][k]<<",";
            cout<<" ";
        }
        cout<<endl;
    }
}
