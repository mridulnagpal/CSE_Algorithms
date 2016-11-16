#include<iostream>

//
// Insertion Sort
//
//Insertion_sort.cpp
//
//Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one
//item at a time. It is much less efficient on large lists than more advanced algorithms such
//as quicksort, heapsort, or merge sort.
//Complexity O(n^2)

using namespace std;

void Insertion_Sort (int arr[], int length) {
	 	int j, temp;

	for (int i = 0; i < length; i++) {
		j = i;

		while (j > 0 && arr[j] < arr[j-1]) {
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
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
  cout << "Enter length of array ";
  cin >> length;
  int arr[length];

  for (int i = 0; i < length; i++) {
    cout << "\nEnter element number " << i+1 << " " ;
    cin >> arr[i] ;
  }

  Insertion_Sort (arr, length);
  Display (arr, length);

  return 0;
}
