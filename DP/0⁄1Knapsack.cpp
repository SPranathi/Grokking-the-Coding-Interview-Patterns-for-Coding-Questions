/*
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. The goal is to get the maximum profit out of the items in the knapsack. Each item can only be selected once, as we don’t have multiple quantities of any item.

Let’s take the example of Merry, who wants to carry some fruits in the knapsack to get maximum profit. Here are the weights and profits of the fruits:

Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5
*/
#include<iostream>
using namespace std;

//DP
int knapsack_DP(int *weights,int *values,int n,int maxweight){
    int arr[maxweight+1]={0};
    for(int i=0;i<n;i++){
        for(int j=maxweight;j>=weights[i];j--){
            arr[j]=max(arr[j],values[i]+arr[j-weights[i]]);
        }
    }
    return arr[maxweight];
}

//Brute Force
int knapsack(int *weights,int *values,int n,int maxweight){
    //Base case
    if(n==0 || maxweight==0)
        return 0;
    //Recursive calls

    if(weights[0]>maxweight){
        return  knapsack(weights+1,values+1,n-1,maxweight);
    }
    int x=knapsack(weights+1,values+1,n-1,maxweight-weights[0])+values[0];
    int y=knapsack(weights+1,values+1,n-1,maxweight);

    return max(x,y);
}
int main(){
    int n,maxw;
    cin>>n;
    int *w=new int[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    int *v=new int[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    cin>>maxw;
    cout<<knapsack(w,v,n,maxw)<<endl;
    cout<<knapsack_DP(w,v,n,maxw)<<endl;
} 

