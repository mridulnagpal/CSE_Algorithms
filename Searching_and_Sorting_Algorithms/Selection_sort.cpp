#include<iostream>

//
// Selection Sort
//
// Selection_sort.cpp
//
//In computer science, selection sort is a sorting algorithm, specifically an in-place comparison
//sort. It is inefficient on large lists, and generally performs worse than the similar insertion sort.
//Selection sort is noted for its simplicity, and it has performance advantages over more
//complicated algorithms in certain situations, particularly where auxiliary memory is limited.
//Complexity O(n^2)

using namespace std;

void Selection_Sort (int arr[], int length) {
  int max = 0;
  for(int i = length - 1 ; i >= 0 ; i--) {
         for(int j = 0; j <= i; j++) {
            if(arr[j] > arr[max]) {
                max = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
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
  Selection_Sort (arr, length);
  Display (arr, length);

  return 0;
}
