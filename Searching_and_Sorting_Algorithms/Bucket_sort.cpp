#include<iostream>
#define int unsigned long long int

/**
*	Bucket Sort
*
*	Bucket_sort.cpp
*
*	In computer science, bucket sort is a sorting algorithm, which uses memory rather than time,
*	it uses an array for sorting. Its biggest shortcoming is that it cannot sort large elements, and used
*	for distinct elements only
*	Complexity O(n)
**/

using namespace std;

void Bucket_Sort (int arr[], int length, int max_element) {
  int temp[max_element + 1], pointer = 0 ;
  for(int i = 0 ; i < length-1 ; i++) 
        temp[arr[i]] = 1;

 for(int i = 0 ; i <= max_element ; i++) {
    cout << temp[i];
    if(temp[i] == 1) {
     	arr[pointer] = i;
     	pointer++;
   }
 }
}

void Display (int arr[], int length) {
	
	for (int i = 0; i < length; i++)
		cout << "\nElement " << i+1 << " : " << arr[i];
	cout << endl ;
}

main () {

  int length, max_element = 0;
  cout << "Enter length of array ";
  cin >> length;
  int arr[length];

  for (int i = 0; i < length; i++) {
    cout << "\nEnter element number " << i+1 << " " ;
    cin >> arr[i] ;
    max_element = max(max_element, arr[i]);
  }

  Bucket_Sort (arr, length, max_element);
  Display (arr, length);

}
