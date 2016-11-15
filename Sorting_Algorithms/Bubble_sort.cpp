#include<iostream>

//
// Bubble Sort
//
// Bubble_sort.cpp
//
//Bubble sort is (provably) the fastest sort available under a very specific circumstance. It
//originally became well known primarily because it was one of the first algorithms (of any kind)
//that was rigorously analyzed, and the proof was found that it was optimal under its limited
//circumstance.
//Complexity O(n^2)

using namespace std;

void Bubble_sort (int arr[], int length) {
  int maximum_element ;
  int pointer;
  for (int i = 0; i < length; i++) {
    maximum_element = arr[0];
    pointer = 0;
    for (int j = 0; j < length - i; j++) {
      if (arr[j] > maximum_element) {
        maximum_element = arr[j];
        pointer = j;
      }
    }
    int temp;
    temp = arr[pointer];
    arr[pointer] = arr[length - i-1];
    arr[length - i-1] = temp;
  }
}

void Display (int arr[], int length) {
  for (int i = 0; i < length; i++) {
    cout << "\nElement " << i+1 << " : " << arr[i] ;
  }
  cout << endl ;
}

int main () {
  int length;
  cout << "Enter length of the array " ;
  cin >> length;
  int arr[length];
  for (int i = 0; i < length; i++) {
    cout << "\nEnter element number " << i+1 << " " ;
    cin >> arr[i];
  }

  Bubble_sort(arr, length);
  Display(arr, length);

  return 0;
}
