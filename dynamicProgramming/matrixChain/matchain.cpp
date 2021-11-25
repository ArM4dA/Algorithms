#include<iostream>
#include<fstream>
#include<limits.h>
using namespace std;
int n,p[100],M[100][100],S[100][100];
void MChain();
void Print(int,int);

int main(int argc, char const *argv[])
{
	fstream inf;
	inf.open("dimensions.txt",ios::in);
	inf>>n>>p[0];
	int i,col,row;
	for(i=1;i<n;i++)
	{
		inf>>col>>row;
		if(col == row)
			p[i] = col;
	}
	inf>>p[i];
	cout<<"MATRIX CHAIN : ";
	MChain();
	cout<<"\nLEAST NUMBER OF SCALAR MULTIPLICATIONS : "<<M[1][n];
	inf.close();
	return 0;
}

void MChain()						// O(n^3)
{
	for(int i=1;i<=n;i++)			// O(n)
		M[i][i] = 0;
	for(int s=2;s<=n;s++)			// Set of matrices
	{
		for(int i=1;i<=n-s+1;i++)	// Starting matrix Mi
		{
			int j = i + s - 1;		// Ending matrix Mj
			M[i][j] = INT_MAX;
			for(int k=i;k<j;k++)	// O(n^3)	Break value for MiMj
			{
				int cost = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
				if(cost < M[i][j])
				{
					M[i][j] = cost;
					S[i][j] = k;
				}
			}
		}
	}
	Print(1,n);
}

void Print(int i,int j)				// O(n)
{
	if(i == j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		Print(i,S[i][j]);
		Print(S[i][j]+1,j);
		cout<<")";
	}
}
