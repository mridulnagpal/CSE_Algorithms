#include<iostream>

//Merge Sort

//Merge_Sort.cpp
//
//In computer science, mergesort is an efficient, comparison based algorithm
//
//It is a divide and conquer algorithm that produces a stable sort(preserves
//input order of equal elements
//It has 2 steps
//Step 1: Divide the unsorted list into n sublists of 1 element each.
//Step 2: Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining which is the sorted list.
//Complexity O(n*log n)

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge (int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	//Create temp arrays
	int L[n1], R[n2];

	//Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	// Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any 
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of the
//   sub-array of arr to be sorted
void Merge_sort (int arr[], int l, int r) {
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		Merge_sort(arr, l, m);
		Merge_sort(arr, m+1, r);
		
		// Merge the 2 sorted halves
		merge(arr, l, m, r);
	}
}

void Display (int arr[], int length) {

	for (int i = 0; i < length; i++) {
		cout << "\nElement " << i+1 << " : " << arr[i];
	}
	cout << endl ;
}



int main () {

	int length;
	cout << "Enter length of array: ";
	cin >> length;
	int arr[length];

	for (int i = 0; i < length; i++) {
		cout << "\nEnter element number " << i+1 << ": " ;
		cin >> arr[i] ;
	}

	Merge_sort (arr, 0 ,length-1);
	Display (arr, length);

	return 0;
}

