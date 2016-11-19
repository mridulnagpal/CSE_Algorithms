#include<iostream>

/* Tower of Hanoi
 *
 *
 *
 * Tower of Hanoi is a classic recursive algorithm in which the
 * primary aim is to move n discs of ascending sizes from top to bottom,
 * from pole A to pole C using pole B.
 *
 *
 * The Complexity is (  ) */

using namespace std ;

void hanoi ( int n , char A , char C , char B ) {
	if(n==1) {
		cout << "Move disc from " << A << " to " << C << endl ;
		return;
	}

	hanoi ( n-1 , A , B , C ) ;
	cout << "Move disc from " << A << " to " << C << endl ;
	hanoi(n-1, B , C , A ) ;
}


int main() {
	int n ;
	cin >> n ;
	hanoi(n, 'A', 'C', 'B') ;
	return 0 ;
}
