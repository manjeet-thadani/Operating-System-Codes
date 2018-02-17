// FCFS -- Without Arrival Time
#include<iostream.h>
#include<conio.h>

void main()
{
	int bt[5],pId[5];
	int wt,tat,rt,count,i;
	wt=tat=rt=0;

	clrscr();

	cout<<"Enter Number of Processes : ";
	cin>>count;

	for(i=0 ; i<count ; i++)
	{
		cout<<"Enter Burst Time for "<<i+1<<" process : ";
		cin>>bt[i];
		pId[i]=i+1;
	}

	for(i=0 ; i<count ; i++)
	{
		tat+=bt[i];
		cout<<"P"<<pId[i]<<" -- BT:"<<bt[i]<<", WT:"<<wt<<", TAT:"<<tat<<", RT:"<<rt<<endl;
		wt+=bt[i];
		rt=wt;
	}
	getch();
}