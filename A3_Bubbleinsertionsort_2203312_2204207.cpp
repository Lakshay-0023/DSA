/*
Lakshay Khurana
2203312
Assignment 3 --- Q2
*/

/*
Arnav Sadhwani
2204207
*/

#include<stdio.h>
#define MAX_SIZE 20  //defining maxsize

void printarray(char a[],int k){     //function to print the array
    for(int i=0;i<k;i++){
        printf("%c ",a[i]);
    }
}
void swap(char a[],int i,int j){       //function to swap
    char temp=a[i];            //making temporrary variable temp to swap values
    a[i]=a[j];
    a[j]=temp;
}
void bubblesort(char a[],int size){    //using bubble sort algorithm
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(a[j]>a[j+1])
                swap(a,j,j+1);
        }
    }
}
void insertionsort(char a[],int size){    //using insertion sort algorithm
    char current;
    int j;
    for(int i=1;i<size;i++){
        current=a[i];    //forn storing the current value
        j=i-1;
        while(j>=0 && a[j]>current){       
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;     //finally placing that element at its correct postiion

    }
}
bool isthere(char a[],int k,char x){    //bool function to check wheter and element is present in the array or not
    for(int i=0;i<k;i++){
        if(a[i]==x){
            return false;
        }
    }
    return true;
}
void unionn(char a1[],int size1,char a2[],int size2,char a3[]){   //function to merge the two sorted arrays
    int i=0;
    int j=0;
    int k=0;
    while(i<size1 && j<size2){
        if(a1[i]==a2[j]){   //applying conditions for mergign the 2 sorted arrays
            if(isthere(a3,k,a1[i])){     //using this function so that any character does not repeat
                a3[k]=a1[i];
                i++;
                j++;
                k++;
            }
            else{
                i++;
                j++;
            }
        }
        else if(a1[i]<a2[j]){     // if a1[i]<a2[j]
            if(isthere(a3,k,a1[i])){
                a3[k]=a1[i];
                i++;
                k++;
            }
            else{
                i++;
            }
        }
        else{                   //else code will run when a2[j]>a1[i]
            if(isthere(a3,k,a2[j])){
                a3[k]=a2[j];
                j++;
                k++;
            }
            else{
                j++;
            }
        }
    }
    while(i<size1){         //this loop will run if size1 > size2
        if(isthere(a3,k,a1[i])){
                a3[k]=a1[i];
                i++;
                k++;
            }
            else{
                i++;
            }
    }
    while(j<size2){        //this loop will run if size2 < size1
        if(isthere(a3,k,a2[j])){
                a3[k]=a2[j];
                j++;
                k++;
            }
            else{
                j++;
            }
    }
    printf("The union of the two arrays is :\n");
    printarray(a3,k);    //finally ptinting the array 
}
int main(){
    int n1,n2;
    
    
    printf("Enter the size of first array: \n");  //taking size1 input of 1st array
    scanf("%d",&n1);
    char arr1[n1];
    printf("Enter the elements of the first array: \n");     //taking input array1
    for(int i=0;i<n1;i++){
        scanf(" %c",&arr1[i]);
    }    
    bubblesort(arr1,n1);     //calling bubble sort function on array 1
    printarray(arr1,n1);       //printing array1
    printf("\nEnter the size of second array: \n");   //taking size2 input of array2
    scanf("%d",&n2);
    char arr2[n2];
    printf("Enter the elements of the second array: \n");   //taking input array2
    for(int i=0;i<n2;i++){
        scanf(" %c",&arr2[i]);
    }  
    insertionsort(arr2,n2);      //calling insertion sort function
    printarray(arr2,n2);     //printing array2
    printf("\n");
    char arr3[n1+n2];     //declaring array3 
    unionn(arr1,n1,arr2,n2,arr3);  //calling that union quiz
    

}