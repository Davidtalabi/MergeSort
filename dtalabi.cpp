//Mergesort algorithm created by David Talabi on February 10, 2019

#include<iostream> 
using namespace std;

void Merge(int L[],int R[],int A[], int numberofelementsleft, int numberofelementsright) //L is left subarray, R is right subarray, A is main subarray
{
 int i,j,k;
 i=0; //index of smallest unpicked element in left array
 j=0; //index of smallest unpicked element in right array
 k=0; //index of position that must be filled in A
 
 while((i < numberofelementsleft) && (j < numberofelementsright)) //While the index of smallest unpicked element is smaller than array size of left and right subarray
 {
     if (L[i] <= R[j]) //if smallest unpicked element in left subarray is less than or equal to smallest unpicked element in right subarray
     {
     A[k] = L[i]; //Place element from left subarray in unfilled position in main array
     k+=1; //Move to next index
     i+=1; //Move to next index
}
     else
     {
        A[k] = R[j]; // Place element from right subarray in unfilled position in main array
        k+=1; //move to next index
        j+=1; // move to next index
     }
 }
 
 while(i < numberofelementsleft)  // if index of smallest unpicked element is only less than the array size of left subarray
 {
     A[k] = L[i];
     k+=1; //move to next index
     i+=1; //move to next index
 }
 
 while(j < numberofelementsright) // if index of smallest unpicked element is only less than the array size of right subarray
 {
     A[k] = R[j];
     k+=1; //move to next index
     j+=1; //move to next index
 }
 
}

void mergesort(int A[], int n) //Mergesort function
{
    cin >> n; //user input array size
    if(n<2) //If array size is smaller than 2 then the array is already sorted
    return;
    int mid; //Variable for middle of array
    mid = n/2; //middle of array size
    
    
    int L[mid];
    int R[n-mid];
    int i;
    
    for(i=0; i<mid; i++)
    {
        L[i] = A[i]; 
    }
    
    for(i=mid; i<n; i++)
    {
        R[i-mid] = A[i];
    } 
    mergesort(L,mid);
    mergesort(R,n-mid);
    Merge(L,R,A,mid,n-mid);
}

void displayarray(int A[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout << A[i] << "";
        cout << ";";
    }
}

int main()
{
    int n,i;
    cin >> n;
    int A[n];
    
    for(i=0; i<n; i++)
    
        cin >> A[i];
        
        mergesort(A,n);
        displayarray(A,n);
        return 0;
}