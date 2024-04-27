/*

Lakshay Khurana 
2203312
MNC

Arnav Sadhwani
2204207
CSE

*/

#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

void merge(int arr[], int start , int end){
    int mid=(start+end)/2;
    int * temp = new int[end-start+1];
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int m =0;m<k;m++){
        arr[start + m]=temp[m];
    }
    delete [] temp;
}

void mergesort(int arr[],int si,int ei){
    int midIndex=(si+ei)/2;
    if(si>=ei){
        return ;
    }
    mergesort(arr,si,midIndex);
    mergesort(arr,midIndex+1,ei);
    merge(arr,si,ei);    


}

int main(){

    srand(time(0));
    int k;
    cout<<"Enter the value of k :"<<endl;
    cin>>k;
    double sum_of_cis=0;
    double squared_sum_of_cis=0;

    for(int i = 1 ; i<=k;i++){
        int n=pow(2,i);
        int * arr = new int[n];
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }
        clock_t start_time = clock();
        mergesort(arr, 0, n - 1);
        clock_t end_time = clock();
        double duration = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        double ci = duration/(n * log2(n));
        if(i>5){
            sum_of_cis+=ci;
            squared_sum_of_cis += ci*ci;
        }
        cout<<"(i,2^i,T(n),i*(2^i),ci) is : "<< i<<" , "<< n <<" , "<< duration <<" , "<< i*n <<" , "<< ci << endl;

    }
    double Expectation = sum_of_cis / (k-5);
    double variance = ( squared_sum_of_cis / (k-5) )-Expectation*Expectation;

    cout<<"Expectation value is : "<<Expectation<<endl;
    cout<<"Variance is : "<<variance<<endl;

}