// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int ar[], int size, int n){
    //code
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        m[ar[i]] = i;
    }
    //ar[i] - ar[j] = target
    // ar[i] = target + ar[j];
    for(int i=0;i<size;i++){
        int x = n+ar[i];
        if(m.find(x)!=m.end() and m[x]!=i){
            return true;
        }
    }
    return false;
}