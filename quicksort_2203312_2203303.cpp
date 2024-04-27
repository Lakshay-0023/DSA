/*
Name: Adwita Deshpande
Roll no.: 2203303
Branch: Mathematics and Computing 

Name: Lakshay Khurana
Roll No.: 2203312
Branch: Mathematics and Computing 
*/

#include <iostream>
#include<ctime>
#include<cmath>
using namespace std;

void swap(int* a, int* b) //to swap two numbers
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high) //to find partition
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

void quicksort(int *arr,int low, int high) //sort recursively by divide and conquer technique
{
    if(low<high)
    {
        int pi = partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
    
}
int main() {
    int k = 20; 
    double sum_ci=0,sum_ci2 = 0;
    cout<<"Quick Sort"<<endl;
    cout<<"(i,2^i,T(2^i),i*2^i,ci)" << endl;
    for (int i = 1; i <= k; i++) {
        int n = pow(2, i);
        int* arr = new int[n];
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }
        clock_t start_time = clock();
        quicksort(arr, 0, n-1);
        clock_t end_time = clock();
        double executionTime = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
        double ci = executionTime / (n * log2(n));
        cout <<"("<< i << "," << n << "," << executionTime << "," << i * n << "," << ci <<")"<< endl;
        sum_ci += ci;
        sum_ci2 += ci*ci;
        delete[] arr;
    }
    double expectation = sum_ci/(k-5);
    double variance = (sum_ci2/(k-5)) - expectation*expectation;
    cout<< "\n";
    cout << "Expectation of ci : "<< expectation <<endl;
    cout << "Variance of ci : "<<variance<<endl;
    return 0;
}