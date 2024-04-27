/*
Name: Adwita Deshpande
Roll no.: 2203303
Branch: Mathematics and Computing 

Name: Lakshay Khurana
Roll No.: 2203312
Branch: Mathematics and Computing 
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int binarySearch(int *arr, int hi, int lo, int n) //recursive binary search
{
    if(lo<=hi)
    {
        int mid = (hi+lo)/2;
        if(arr[mid] == n)
            return mid;
        else if(arr[mid]<n)
            return binarySearch(arr,hi,mid+1,n);
        else if(arr[mid]>n)
            return binarySearch(arr,mid-1,lo,n);
    }
    else
        return -1;
}

//Sort the array using quicksort
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low -1;
    for(int j=low; j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[high],&arr[i+1]);
    return i+1;
}

void quicksort(int *arr,int low, int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main() {
    int k=25; 
    double sum_ci=0,sum_ci2 = 0;
    cout<<"Binary Search"<<endl;
    cout<<"(i,2^i,T(2^i),i*2^i,ci)" << endl;
    for (int i = 1; i <= k; i++) {
        int n = pow(2, i);
        int* arr = new int[n];
        arr[0] = 1;
        for (int j = 1; j < n-1; j++) {
            arr[j] = rand();
        }
        quicksort(arr, 0, n-1); //sort the array
        clock_t start_time = clock();
        binarySearch(arr,n-1,0,-1); //search for -1
        clock_t end_time = clock();
        long double executionTime = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
        long double ci = executionTime / (log2(n));
        
        cout <<"("<< i << "," << n << "," << executionTime << "," << i * n << "," << ci <<")"<< endl;
        sum_ci += ci;
        sum_ci2 += ci*ci;

        delete[] arr;
    }
    double expectation = sum_ci/k;
    double variance = (sum_ci2/k) - expectation*expectation;
    cout<< "\n";
    cout << "Expectation of ci : "<< expectation <<endl;
    cout << "Variance of ci : "<<variance<<endl;
    return 0;
}