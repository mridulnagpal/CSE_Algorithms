#include<iostream>
#define int unsigned long long int 
/**
*	Bubble Sort
*
*	Bubble_sort.cpp
*
*	Bubble sort is (provably) the fastest sort available under a very specific circumstance. It
*	originally became well known primarily because it was one of the first algorithms (of any kind)
*	that was rigorously analyzed, and the proof was found that it was optimal under its limited
*	circumstance.
*	Complexity O(n^2)
**/
using namespace std;

void Bubble_sort (int arr[],int  length) {
  for (int i=0; i<length;i++) 
    for (int j=0;j<length-i-1;j++) 
      if (arr[j] > arr[j+1]) {
	      int temp=arr[j];
	      arr[j]=arr[j+1];
	      arr[j+1]=temp;
      }
}
void Display (int arr[], int length) {
  for (int i=0;i<length;i++)
    cout<<"\nElement "<<i+1<<"\t : "<<arr[i];
  cout<<endl;
}

main () {
  int length;
  cout<<"Enter length of the array " ;
  cin>>length;
  int arr[length];
  for (int i=0;i<length;i++) {
    cout<<"\nEnter element "<<i+1<<" : ";
    cin>>arr[i];
  }
  Bubble_sort(arr, length);
  Display(arr,length);
}
