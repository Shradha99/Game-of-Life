#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <ctime>
using namespace std;

//function to print the 2-D array and ask user if he wants the next generation
void print(int **arr, int row,int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j];
			cout<<" ";}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Enter y if you want to see the next generation, else enter n"<<endl;
}

//function to determine the next generation
void next_state(int**arr, int row, int col){
	//buff1 and buff2 hold the future states for the lines 1 and 2. Then, buff1 is copied into the original array(since it has no further use) and freed, after which it holds line 3 and the process continues.
	int* buff1=new int [col];
	int* buff2= new int [col];
	int state_buff1=1;
	int state_buff2=0;

	//calculating the sum of values of the 8 neighbours around the cell
	for(int a=1;a<row-1;a++){
		int* fill=new int[col];
		fill[0]=arr[a][0];
		fill[col-1]=arr[a][col-1];
		for(int b=1;b<col-1;b++){
			int all_field_sum=0;
			for(int c=-1;c<=1;c++){
				for(int d=-1;d<=1;d++)
					all_field_sum+=arr[a+c][b+d];
			}
			all_field_sum-=arr[a][b];

			//conditions for evaluating the future state of a cell
			if((arr[a][b]==1)&&((all_field_sum<2)||(all_field_sum>3)))
				fill[b]= 0;
			else if((arr[a][b]==0)&&(all_field_sum==3))
				fill[b]=1;
			else fill[b]=arr[a][b];
		}

		//copying buff1 or buff2 into the original array, as per the row
		if((a%2==1)&&(a!=1)){
				for(int i=1;i<col-1;i++)
					arr[a-2][i]=buff1[i];
			}
			else if((a%2==0)&&(a!=2)){
				for(int i=1;i<col-1;i++)
					arr[a-2][i]=buff2[i];
			}

			//re-allocating buff1 or buff2 with the future state of that particular row
		if(state_buff1==1){
			for(int i=0;i<col;i++)
				buff1[i]=fill[i];}
		else {
			for(int i=0;i<col;i++)
				buff2[i]=fill[i];
		}
		//alternating the states of buff1 and buff2
			state_buff1=(state_buff1+1)%2;
			state_buff2=(state_buff2+1)%2;
		
			delete[] fill;
	}
	//taking care of the last iteration of buff1 and buff2
	for(int i=1;i<col-1;i++){
		arr[row-3][i]=buff1[i];
		arr[row-2][i]=buff2[i];
	}		
	print(arr,row,col);
	delete[] buff1;
	delete[] buff2;
}

int main(){
	clock_t start, end; 
	int row,col;
	cout<<"Enter the no. of rows and columns"<<endl;
	cin>>row;
	cin>>col;

	//the number of rows and columns have been increased to facilitate the padding of zeros on the four sides to avoid discrepancies on the boundary
	row+=2;
	col+=2;

	int** arr=new int*[row];
	for(int i=0;i<row;i++)
		arr[i]=new int[col];

	//populating the array with zero on boundaries
	for(int i=0;i<col;i++){
		arr[0][i]=0;
		arr[row-1][i]=0;}
	for(int i=1;i<row-1;i++){
		arr[i][0]=0;
		arr[i][col-1]=0;
	}

	// taking input for the initial state. The matrix can also be generated via the rand() function if we don't want to enter manually. Just uncommenting the two statements with srand() and rand() in the code below and commenting the cin>>arr[i][j] statement can do the same.

	//srand((unsigned) time(0));
	cout<<"Enter the initial state"<<endl;
	for(int i=1;i<row-1;i++){
		for(int j=1;j<col-1;j++)
			//arr[i][j]=(rand()%2);
			cin>>arr[i][j];
	}
	cout<<endl;
	cout<<"Original Generation"<<endl;
	print(arr,row,col);

	//works upon the user's discretion of printing the next generation(y or n)
	char command;
	int gen=0;
	while(true){
	cin>>command;
	if(command=='y'){
		cout<<endl;
		start=clock();
		gen+=1;
		cout<<"Generation ";
		cout<<gen<<endl;
		next_state(arr,row,col);
		end=clock();
		cout<<"Time taken:";
		cout<<end-start<<endl;
	}
	else {
		for(int i=0;i<row;i++)
			delete[] arr[i];
		delete[] arr;
		break;
	}
	}
	return 0;
}


