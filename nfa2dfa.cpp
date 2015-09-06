#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define M 4
#define N 2

int main(){
	int fs;
	int regex[10][10][10];
	int i,j, initial, final[10], k,m, flag=0, state, stin;
	char inval[10];
	char val[10];

	ifstream in("innfa.txt");

	in>>initial;
	// cout<<initial;

    for (i=0;i<10;i++)
        for (j=0;j<10;j++)
            for (k=0;k<10;k++)
                regex[i][j][k]='\0';

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

            if(val==","){
                k++;
            }
            regex[i][j][k] = atoi(val);
		}


    for (i=0;i<M;i++){
        for (j=0;j<N;j++){
            for (k=0;regex[i][j][k]!='\0';k++)
                cout<<regex[i][j][k];
            cout<<" ";
        }
        cout<<endl;
    }

	cout<<"Input String : \n";
	cin>>inval;

	k = strlen(inval);
	state = 0;
	for(i=0;inval[i]!='\0';i++){
		stin = inval[i] - 97;
		state = regex[state][stin][0];
		if (state==-1){
			cout<<"Invalid input. Breaking Code.\n";
			return 0;
		}
	}

	for(i=0;i<m;i++){
		if(state == final[i]){
			flag=1;
			break;
		}
	}

	if (flag==1)
	{
		printf("This is a match !\n");
	}
	else{
		printf("This is no match !\n");
	}
}
