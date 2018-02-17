// Round Robin -- Without AT
#include<iostream.h>
#include<conio.h>

void main(){
	int count,i,j;
	int currTime, prevTime, procExec, remain, qTime, tat = 0, wt = 0;
	int bt[5], rbt[5], pId[5];
	currTime = prevTime = procExec = 0;
	clrscr();

	cout<<"Enter Quantum Time : ";
	cin>>qTime;
	cout<<"Enter Number of Processes : ";
	cin>>count;
	remain = count;
	
	//Take Input
	for(i=0 ; i<count ; i++){
		cout<<"Enter Burst Time for "<<i+1<<" process : ";
		cin>>bt[i];
		pId[i]=i+1;
		rbt[i] = bt[i];
	}

	int flag =0;

	for(currTime=0,procExec=0 ; remain!=0; ){
		if (rbt[procExec] <= qTime && rbt[procExec] > 0){
			currTime += rbt[procExec];
			rbt[procExec] = 0;
			flag = 1;
		}
		else if (rbt[procExec] > 0){
			rbt[procExec] -= qTime;
			currTime += qTime;
		}
		if (rbt[procExec] == 0 && flag == 1){
			remain--;
			cout<<"P"<<pId[procExec]<<" -- BT:"<<bt[procExec]<<", TAT:"<<currTime<<", WT:"<<currTime-bt[procExec]<<endl;
			wt += currTime - bt[procExec];
			tat += currTime;
			flag = 0;
		}
		if (procExec == count-1)
			procExec = 0;
		else
			procExec++;
	}
	cout<<"All Processes End after "<<currTime<<" units";
	getch();
} 
