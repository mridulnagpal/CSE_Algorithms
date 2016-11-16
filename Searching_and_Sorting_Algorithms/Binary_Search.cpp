#include<iostream>

//
//
// Binary Search
//
//
// Binary_Search.pp
//
//
//Binary Search is a search algorithm that is more optimised than linear search.
//It significantly reduces the runtime of programs.
//The following is a basic implementation of the Binary Search algorithm with Complexity log(n).

using namespace std;

void BinarySearch(int A[], int a, int b, int n) {
	int start = a, end = b ;
        if( n == ( A[start] + A[end] ) / 2) {
              	cout << ( start + end ) / 2 ;
                return;
        }
        else if( n > ( A[start] + A[end]) / 2 )
                BinarySearch ( A, ((start+end)/2) + 1 , end, n ) ;

        else
                BinarySearch ( A , start , ( (start+end) / 2 ) - 1 , n) ;
}

int main() {
        int count,i ;
        cin >> count ;
        int A[count] ;
        for(i = 0; i < count; i++)
                cin >> A[i] ;		//Takes the input array where Binary Search is to be executed
        int n ;
        cin >> n ;
        BinarySearch(A,0,count-1,n) ;
	cout << endl ;
        return 0 ;
}

