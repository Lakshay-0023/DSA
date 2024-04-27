#include<iostream>
#include<vector>
using namespace std;

// Function which returns the index that will be placed in the mem array 
int binarysearch(int list[],vector<int> mem ,  int start , int end ,  int index){
    
    //end case or we can call base case too
    if(start==end){
        if(list[index]<list[mem[start]]){
            return start;                   
        }
        else{
            return start+1;      // if the element is greater than all of the memebers of the indexes of mem array then it will be placed after all prev elements
        }
    }
    else
    {
        int mid = (start + end)/2;   // binary search 
        if(list[index]<=list[mem[mid]]){
            return binarysearch(list,mem,start,mid,index);   // recursive call
        }
        else{
            return binarysearch(list,mem,mid+1,end,index);    // recursive call
        }
    }
}

int LIS_ending_in_i(int list[] , int pred[] , int i){    // finding LIS ending at list[i]
    vector<int> ans;
    int k = pred[i];
    ans.push_back(list[i]);    
    for(int k = pred[i];k!=-1;k=pred[k]){
        ans.insert(ans.begin(),list[k]);       //backtracking to find the LIS
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ans.size();    //lenght of LIS ending at A[i]
}

int LIS(int list[],int n , int tail[],int pred[],vector<int> mem ){
    // Loop to iterate the whole array
    for(int i=1;i<n;i++){
        int index = binarysearch(list,mem,0,mem.size()-1,i);
        if(index>mem.size()-1){
            mem.push_back(i);   //inserting at last 
        }
        else{
            mem[index]=i;    // replacing a index as we have found a better solution for the same length of the subsequence 
        }
        tail[i]=mem.back();    // populating the tail array
        pred[i]=mem[index-1];   // populating the pred array 
    }
    cout<<"Tail Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<tail[i]<<" ";         // printing the tail array 
    }
    cout<<endl;
    cout<<"Pred Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<pred[i]<<" ";          // printing the pred array
    }
    cout<<endl;
    cout<<"Mem Array : "<<endl;
    for(int i=0;i<mem.size();i++){
        cout<<mem[i]<<" ";            // printing the mem array
    }
    cout<<endl;
    cout<<"Longest Increasing Subsequence is : "<<endl;
    int ans[mem.size()];                
    int value = mem[mem.size()-1];
    for(int i=mem.size()-1;i>=0;i--){
        ans[i]=list[value];
        value=pred[value];           // backtracking the pred array to find the final ans 
    }
    for(int i=0;i<mem.size();i++){
        cout<<ans[i]<<" ";      // printing the final array 
    }
    cout<<endl;
    
    return mem.size();    // size of the longest increasing subsequence 
}

int main(){
    int i;
    cout<<"Enter the value of i "<<endl;
    cin>>i;
    cout<<endl;
    int list[] = {-2,7,4,0,1,5,3,8,6,5,6,4};
    int n=12;
    cout<<"Original Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
    int tail[n] ;
    int pred[n] ;
    vector<int> mem;

    tail[0]=0;
    pred[0] = -1;
    mem.push_back(0);
    int x = LIS(list,i+1, tail,pred,mem);    // passsing i+1 ans i is the last index and we have to pass the size of whole array
    cout<<"Length of the longest non-decreasing subsequence is : "<<x<<endl;
    cout<<endl;
    cout<<"Length of longest non-decreasing subsequence ending in A[i] is :"<<endl;
    int newans = LIS_ending_in_i(list , pred , i);
    cout<<"Length of this subsequence is : "<<newans;

}