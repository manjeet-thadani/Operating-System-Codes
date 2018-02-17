// Round Robin -- With AT
#include<iostream.h>
#include<conio.h>

void main(){
	int count,i,j;
	int currTime, prevTime, procExec, remain, qTime, tat = 0, wt = 0;
	int at[5], bt[5], rbt[5], pId[5];
	currTime = prevTime = procExec = 0;
	clrscr();
	cout<<"Enter Quantum Time : ";
	cin>>qTime;
	cout<<"Enter Number of Processes : ";
	cin>>count;
	remain = count;
	
	//Take Input
	for(i=0 ; i<count ; i++){
		cout<<"Enter Burst Time and Arrival Time for "<<i+1<<" process : ";
		cin>>bt[i]>>at[i];
		pId[i]=i+1;
		rbt[i] = bt[i];
	}
	//Sort wrt AT
	for(i=0 ; i<count ; i++){
		for(j=0 ; j<count-1 ; j++){
			if(at[j]>at[j+1]){
				int temp = bt[j+1];
				bt[j+1] = bt[j];
				bt[j] = temp;

				temp = at[j+1];
				at[j+1]= at[j];
				at[j] = temp;

				temp = pId[j+1];
				pId[j+1] = pId[j];
				pId[j] = temp;

				temp = rbt[j+1];
				rbt[j+1] = rbt[j];
				rbt[j] = temp;
			}
		}
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
			cout<<"P"<<pId[procExec]<<" -- AT:"<<at[procExec]<<", BT:"<<bt[procExec]<<", TAT:"<<currTime-at[procExec]<<", WT:"<<currTime-at[procExec]-bt[procExec]<<endl;
			wt += currTime - at[procExec] - bt[procExec];
			tat += currTime - at[procExec];
			flag = 0;
		}
		if (procExec == count-1)
			procExec = 0;
		else if (at[procExec+1] <= currTime)
			procExec++;
		else
			procExec = 0;
	}
	cout<<"All Processes End after "<<currTime<<" units";
	getch();
}
