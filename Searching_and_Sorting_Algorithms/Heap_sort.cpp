#include <iostream>
#define int unsigned long long int 
/**
*	 Heap Sort
*
*	Heap_sort.cpp
*
*	In computer science, heapsort is a comparison-based sorting algorithm. Heapsort can be thought
*	of as an improved selection sort: like that algorithm, it divides its input into a sorted and an
*	unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element
*	and moving that to the sorted region. The improvement consists of the use of a heap data structure
*	rather than a linear-time search to find the maximum.
*	Complexity O(n*logn)
**/
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[].
void heapify(int arr[], int length, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < length && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < length && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, length, largest);
    }
}

void Heap_sort(int arr[], int length) {
    // Build heap (rearrange array)
    for (int i = length / 2 - 1; i >= 0; i--)
        heapify(arr, length, i);

    // One by one extract an element from heap
    for (int i=length-1; i>=0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void Display (int arr[], int length) {

    for (int i = 0; i < length; i++) {
      cout << "\nElement " << i+1 << " : " << arr[i];
    }
    cout << endl ;
}
main () {

  int length;
  cout << "Enter length of array ";
  cin >> length;
  int arr[length];
  for (int i = 0; i < length; i++) {
    cout << "\nEnter element number " << i+1 << " " ;
    cin >> arr[i] ;
  }
  Heap_sort (arr, length);
  Display (arr, length);
}
