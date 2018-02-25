#include<iostream>
#include<windows.h>
using namespace std;
int pivot = 0;
int storeindex = 1;
void my_swap(int *a,int *b);
void Quicksort(int s[],int* start,int* end);
int main()
{
	int arr[18] = {26,13,41,3,50,2,36,25,10,1,42,19,27,5,33,9,29,11};
	Quicksort(arr,arr,arr+17);
	for(int i = 0;i<=17;i++)
	{
		cout<<arr[i];
	}
	return 0;
}
void Quicksort(int s[],int* start,int* end)
{
	pivot = start-s;
	storeindex = pivot+1;
	for(int i = pivot+1;i<=end-start;i++)
	{
		if(s[i]<s[pivot])
		{
			my_swap(s+i,s+storeindex);
			storeindex += 1;
		}
		for(int i = 0;i<=end-start;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}

	//Sleep(1500);
	my_swap(&s[pivot],&s[storeindex-1]);

		cout<<endl;
	int x = storeindex;
	if(start != end)
	{
		Quicksort(s,s,s+storeindex-1);
	}
		cout<<"enter next\n";
	if(start != end)
	{
		Quicksort(s,s+storeindex+1,end);		
	}

}
void my_swap(int *a,int *b)//传入的是地址 int*型 
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	 
}
