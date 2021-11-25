#include<iostream>
#include<math.h>
using namespace std;
int x[100],c=0;

bool Place(int row,int col)
{
	for(int i=1;i<row;i++)
		if(x[i]==col || abs(x[i]-col)==abs(i-row))
			return false;
	return true;
}

void Write(int n)
{
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<"\n";
}

void NQueen(int row,int n)
{
	for(int i=1;i<=n;i++)
		if(Place(row,i))
		{
			x[row] = i;
			if(row==n&&++c)
				Write(n);
			else
				NQueen(row+1,n);
		}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"ENTER NUMBER OF QUEENS : ";
	cin>>n;
	NQueen(1,n);
	if(c)
		cout<<"NUMBER OF SOLUTIONS : "<<c;
	else
		cout<<"NO SOLUTION POSSIBLE!";
	return 0;
}
