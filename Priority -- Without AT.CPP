// Priority -- Without Arrival Time
#include<iostream.h>
#include<conio.h>

void main()
{
	int bt[5],p[5],pId[5];
	int wt,tat,rt,count,i,j;
	wt=tat=rt=0;

	clrscr();

	cout<<"Enter Number of Processes : ";
	cin>>count;

	//Take Input
	for(i=0 ; i<count ; i++)
	{
		cout<<"Enter Burst Time and Priority  for "<<i+1<<" process : ";
		cin>>bt[i]>>p[i];
		pId[i]=i+1;
	}
	//Sort wrt Priority
	for(i=0 ; i<count ; i++){
		for(j=0 ; j<count-1 ; j++){
			if(p[j]>p[j+1]){
				int temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;

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
		cout<<"P"<<pId[i]<<" -- Priority:"<<p[i]<<", BT:"<<bt[i]<<", WT:"<<wt<<", TAT:"<<tat<<", RT:"<<rt<<endl;
		wt+=bt[i];
		rt=wt;
	}
	getch();
}