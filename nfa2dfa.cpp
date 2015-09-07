#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define N 2
int M = 4;

int** intersection(int regex[10][10][10], int m, int n, int val[10]){
    int i, j,k,l;
    for (i=0;val[i]!=-2;i++){
        cout<<val[i];
    }
}

int main(){
	int fs, kali;
	int regex[10][10][10], newreg[10][10], v[10];
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
            for (k=0;regex[i][j][k]!=-2;k++){
                if (k>0){
                    cout<<k;
                    M = M+1;
                    l=0;
                    while(regex[i][j][l]!=-2){
                        v[l] = regex[i][j][l];
                        l++;
                    }
                    regex[i][j][0] = M;
                    intersection(regex, i, j, v);
                }
                else{
                    newreg[i][j] = regex[i][j][k];
                }
            }
            cout<<" ";
        }
        cout<<endl;
    }
}
