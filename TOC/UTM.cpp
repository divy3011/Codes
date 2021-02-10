#include<iostream>

using namespace std;

int main()
{
	int p = 0,size = 200,in,rtb;
	int arr[200] = {0};
	int states = 0,qf;
	struct rule
	{
		int state,nstate,dir,one,two,zero,in;
	};
	int n;
	cout<<"Enter number of rules : ";
	cin>>n;
    rule r[n],ir;
	cout<<"Rules : "<<endl;
	for(int i = 0;i<n;i++)
	{
		cin>>r[i].state;
		cin>>r[i].nstate;
		cin>>r[i].dir;
		cin>>r[i].one;
		cin>>r[i].two;
		cin>>r[i].zero;
		cin>>r[i].in;
	}

	cout<<"Enter number of chars in input : ";
	cin>>n;
	cout<<"Input : "<<endl;
	for(int j = 0; j<n; j++)
	{
		cin>>in;
		arr[j] = in;
	}

	cout<<"Enter final state : ";
	cin>>qf;

	while (true)
	{
		if(states == qf)
		{
				cout<<"String Accepted";
				break;
		}
		
		
		in = arr[p];
		rtb = 3*states + in;
		ir = r[rtb];
		if(ir.dir == 0 && states != qf)
		{
			cout<<"String Rejected";
			break;
		}
		if(ir.zero)
			arr[p] = 0;
		else if(ir.one)
			arr[p] = 1;
		else if(ir.two)
			arr[p] = 2;
		p+=ir.dir;
		states = ir.nstate;


		

	}

	for(int k = 0; k<n; k++)
	{
		cout<<arr[k];
	}

		
}

