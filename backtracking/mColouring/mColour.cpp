#include<iostream>
#include<fstream>
using namespace std;
int G[100][100],x[100],n,m,c=0;
void MColour(int);
void NextValue(int);
void Write(int);

int main(int argc, char const *argv[])
{
	fstream inf;
	inf.open("graph.txt",ios::in);
	inf>>n;
	for(int i=1;i<=n;i++,x[i]=0)
		for(int j=1;j<=n;j++)
			inf>>G[i][j];
	inf>>m;
	MColour(1);
	if(c)
		cout<<"NUMBER OF SOLUTIONS : "<<c;
	else
		cout<<"NO SOLUTIONS POSSIBLE";
	inf.close();
	return 0;
}

void MColour(int k)
{
	do
	{
		NextValue(k);
		if(!x[k])
			return;
		else if(k==n && ++c)
			Write(n);
		else
			MColour(k+1);
	}while(true);
}

void NextValue(int k)
{
	do
	{
		x[k] = (x[k]+1) % (m+1);
		if(!x[k]) 
			return;
		int i;
		for(i=1;i<k;i++)
			if(G[i][k] && x[i]==x[k])
				break;
		if(i==k) 
			return;
	}while(true);
}

void Write(int n)
{
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<"\n";
}
