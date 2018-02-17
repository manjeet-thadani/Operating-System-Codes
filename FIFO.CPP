// FIFO
#include<iostream.h>
#include<conio.h>

void main(){
	int a[100], frame[100], count = 0, i, j, k, n, no, avail;
	clrscr();

	cout<<"Enter number of pages : ";
	cin>>n;
	cout<<"Enter Page References : ";
	for (i = 0 ; i < n ; i++)
		cin>>a[i];

	cout<<"Enter number of frames : ";
	cin>>no;

	for(i = 0 ; i < no ; i++)
		frame[i] = -1;
	j = 0;
	cout<<endl<<"Distribution : "<<endl;

	for(i = 0 ; i < n ; i++){
		avail = 0;
		for(k = 0 ; k < no ; k++){
			if (a[i] == frame[k]){
				avail = 1;
			}
		}
		if (avail == 0){
			frame[j] = a[i];
			j = (j+1)%no;
			count++;

			for(k = 0 ; k < no ; k++){
				cout<<frame[k]<<"\t";
			}
			cout<<endl;
		}
	}
	cout<<"Toatl Page Faults : "<<count;
	getch();
}