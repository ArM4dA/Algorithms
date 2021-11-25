#include<iostream>
#include<fstream>
using namespace std;
int vertices,graph[10][10],array[10];

void Hamiltonian(int);

int main(int argc, char const *argv[])
{
	fstream inf;
	inf.open("Graph.txt",ios::in);
	if(inf)
	{
		inf>>vertices;
		for(int i=1;i<=vertices;i++)
			for(int j=1;j<=vertices;j++)
				inf>>graph[i][j];

		array[1] = 1;
		for(int i=2;i<=vertices;i++)
			array[i] = 0;
		cout<<"\nHAMILTONIAN CYCLES OF THE GRAPH : \n\n";
		Hamiltonian(2);
		inf.close();
	}
	return 0;
}

void Hamiltonian(int k)
{
	do
	{
		array[k] = (array[k] + 1) % (vertices + 1);
		if(array[k] && graph[array[k]][array[k-1]])
		{
			int j;
			for(j=1;j<k;j++)
				if(array[k] == array[j]) break;
			if(j == k)
			{
				if(k < vertices)
					Hamiltonian(k + 1);
				else if(k == vertices && graph[array[k]][array[1]])
				{
					for(int i=1;i<vertices;i++)
						cout<<array[i]<<" - ";
					cout<<array[vertices]<<"\n\n";
				}
			}
		}
	}while(array[k]);
}
