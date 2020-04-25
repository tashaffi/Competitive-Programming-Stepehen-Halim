#include <iostream>
using namespace std;


/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

void swap(int* a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j]=temp;
}

void max_heapify(int *a, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[largest]) largest= l;
    if(r<n && a[r]>a[largest]) largest = r;

    if(largest!=i){
        swap(a, i, largest);
        max_heapify(a,n,largest);
    }
}


void heapsort(int *a, int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(a,n,i);
    }

    printArray(a,n);

    for(int i=0;i<n-1;i++){
        printArray(a,n);
        swap(a, 0, n-1-i);
        max_heapify(a,n-1-i,0);
    }
}
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapsort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 