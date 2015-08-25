#include "iostream"
#include "fstream"

using namespace std;

#define S 4;
#define V 2;

int main(){
	int fs;
	int regex[10][10];
	int i,j, initial, final[10], k,m, flag=0;
	char input[10];

	ifstream in("input.txt");
	
	in>>initial;
	cout<<initial;

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

	for(i=0;i<S;i++){
		for(j=0;j<V;j++){
			in>>regex[i][j];
		}
	}

	cout<<"Input String : \n";
	cin<<input;

	k = strlen(input);
	state = 0;
	for(i=0;input[i]!='\0';i++){
		stin = input[i] - 97;
		state = regex[state][stin];
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