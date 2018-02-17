// FCFS -- With Arrival Time
#include<iostream.h>
#include<conio.h>

void main()
{
	int bt[5],at[5],pId[5];
	int wt,tat,rt,count,i,j;
	wt=tat=rt=0;

	clrscr();

	cout<<"Enter Number of Processes : ";
	cin>>count;

	//Take Input
	for(i=0 ; i<count ; i++)
	{
		cout<<"Enter Burst Time and Arrival Time  for "<<i+1<<" process : ";
		cin>>bt[i]>>at[i];
		pId[i]=i+1;
	}
	//Sort wrt AT
	for(i=0 ; i<count ; i++){
		for(j=0 ; j<count-1 ; j++){
			if(at[j]>at[j+1]){
				int temp = at[j+1];
				at[j+1] = at[j];
				at[j] = temp;

				temp = bt[j+1];
				bt[j+1] = bt[j];
				bt[j] = temp;

				temp = pId[j+1];
				pId[j+1] = pId[j];
				pId[j] = temp;
			}
		}
	}


	for(i=0 ; i<count ; i++)
	{
		tat+=bt[i];
		cout<<"P"<<pId[i]<<" -- AT:"<<at[i]<<", BT:"<<bt[i]<<", WT:"<<wt<<", TAT:"<<tat<<", RT:"<<rt<<endl;
		wt+=bt[i];
		rt=wt;
	}
	getch();
}