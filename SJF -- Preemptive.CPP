// SJF -- Preemptive
#include<iostream.h>
#include<conio.h>

int at[5],bt[5],pId[5],wt[5],tat[5],rbt[5];

int allDone(int count){
	for(int i=0 ; i<count ; i++){
		if(rbt[i] != 0)
			return 0;
	}
	return 1;
}

void main()
{
	int count,i,j;
	int currTime, prevTime, procExec;
	currTime = prevTime = procExec = 0;

	clrscr();

	cout<<"Enter Number of Processes : ";
	cin>>count;

	//init array
	for(i=0 ; i<count; i++)
		wt[i] = tat[i] = 0;

	//Take Input
	for(i=0 ; i<count ; i++)
	{
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
	int maxAt = at[count-1];

	if (rbt[0] > at[1]){
		rbt[0] -= at[1];
		prevTime = currTime;
		currTime += at[1];

	}else{
		prevTime = currTime;
		currTime += rbt[0];
		tat[0] = wt[0] + rbt[0];
		rbt[0] = 0;
		procExec++;
	}


	while(!allDone(count))
	{
		int temp = 0;
		//Check if There is any process In Ready Queue
		for (i=0 ; i<count; i++){
			if (at[i] <= currTime)
				temp++;
		}

		//If There is any Process than temp > executedProcesses
		if(temp > procExec){
			//Sort acc to RBT
			for(i=0 ; i<temp; i++){
				for(j=0 ; j<temp-1; j++){
					if (rbt[j] > rbt[j+1]){
						int temp1 = bt[j];
						bt[j] = bt[j+1];
						bt[j+1] = temp1;

						temp1 = at[j];
						at[j] = at[j+1];
						at[j+1] = temp1;

						temp1 = pId[j];
						pId[j] = pId[j+1];
						pId[j+1] = temp1;

						temp1 = rbt[j];
						rbt[j] = rbt[j+1];
						rbt[j+1] = temp1;

						temp1 = wt[j];
						wt[j] = wt[j+1];
						wt[j+1] = temp1;

						temp1 = tat[j];
						tat[j] =tat[j+1];
						tat[j+1] = temp1;
					}
				}
			}

			i = 0;
			while(rbt[i]==0)
				i++;

			prevTime = currTime;
			currTime += 1;
			rbt[i] -= 1;

			if(rbt[i]==0){
				procExec++;
				wt[i] = currTime - at[i] - bt[i];
				tat[i] =wt[i] + bt[i];
			}
		}
		else{
			currTime++;
		}
	}

	for(i=0; i<count; i++){
		cout<<"P"<<pId[i]<<" -- AT:"<<at[i]<<", BT:"<<bt[i]<<", WT:"<<wt[i]<<", TAT:"<<tat[i]<<endl;
	}
	cout<<"All Processes End after "<<currTime<<" units";
	getch();
}