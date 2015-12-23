// WAP to read a regular grammar. Check whether a string given is acceptable or not.

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdio>

#define INPUT "input_grammar.txt"

int n=0;

struct prod
{
    char lhs[10],rhs[10][10];
    int n;
}pro[10];

int main(){

	FILE *f;

    for(int i=0;i<10;i++)
        pro[i].n=0;

    f=fopen(INPUT,"r");
    while(!feof(f))
    {
        fscanf(f,"%s",pro[n].lhs);
        if(n>0)
        {
            if( strcmp(pro[n].lhs,pro[n-1].lhs) == 0 )
            {
                pro[n].lhs[0]='\0';
                fscanf(f,"%s",pro[n-1].rhs[pro[n-1].n]);
                pro[n-1].n++;
                continue;
            }
        }
        fscanf(f,"%s",pro[n].rhs[pro[n].n]);
        pro[n].n++;
        n++;
    }

    printf("\n\nTHE GRAMMAR IS AS FOLLOWS\n\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<pro[i].n;j++)
            printf("%s -> %s\n",pro[i].lhs,pro[i].rhs[j]);
}