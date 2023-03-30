#include <iostream>
using namespace std;

//array of integeers to hold values
int arr[20];
int cmp_count = 0; //number of comparation 
int mov_count = 0; //number of data movement 
int n;


void input() {
	while (true)
	{
		cout << "masukan panjang elemen array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}
	cout << "\n==================" << endl;
	cout << "membuat elemen array" << endl;
	cout << "\n==================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
//swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_sort(int low, int high)
{
	int pivot, i, j;
	if (low > high)    //langkah 1
		return;

	//partition the list into two parts ;
	//one containing elements less that or equal to pivot
	//outher conntaining elements ggreather than pivot

	pivot = arr[low];   //langkah 2

	i = low + 1;     //langkah 3
	j = high;        //langkah 4


	while (i <= j)   //langkah 10
	{
		//search for an element greather than pivot
		while ((arr[i] <= pivot) && (i <= high))  //langkah 5
		{
			i++;                                  //langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an alement less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))     //langkah 7
		{
			j--;                                  //langkah 6			
			cmp_count++;
		}
		cmp_count++;

		//langkah 9
		if (i < j) //if the greather element is on the left of the element
		{
			//swap the element at index i with the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	if (low < j) //langkah 11
	{
		//swap the element at index i with the element at index j
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of the pivot using quick sort

	q_sort(low, j - 1);                 //langkah 12
	q_sort(j + 1, high);
}

