class MergeSortExample {
	
	static void merge(int a[],int b,int m,int e) {
		int L[] = new int[m-b+1];
		int R[] = new int[e-m];
		for(int i=b;i<=m;i++) L[i-b] = a[i];
		for(int i=m+1;i<=e;i++) R[i-m-1] = a[i];
		int i = 0;
		int j = 0;
		int k = b;	
		while( i<(m-b+1) && j<(e-m) ) {
			if (L[i] >= R[j]) a[k++] = R[j++];
			else if(L[i] < R[j]) a[k++] = L[i++];
		}
		while(i < (m-b+1)) a[k++] = L[i++];
		while(j < (e-m)) a[k++] = R[j++];
		return;	
	}

	static void mergeSort(int a[],int b,int e) {
		if (b < e) {
			int m = (b+e)/2;
			mergeSort(a,b,m);
			mergeSort(a,m+1,e);
			merge(a,b,m,e);
		}
		return; 
	}

	public static void main(String args[]) {
		int a[]={3,60,35,2,45,320,5};
		System.out.println("ARRAY before sorting");
		for(int i=0;i<7;i++) System.out.println(a[i] + " ");
		System.out.println();
		mergeSort(a,0,6);
		System.out.println("ARRAY after sorting");
		for(int i=0;i<7;i++) System.out.println(a[i] + " ");
		System.out.println();
	}
}


