//
//Question : https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// Created by spawnfire on 17/05/21.
//

#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> a;
int largestArea(int a[],int n){
    int ans=0;
    stack<int>st;
    int i=0;
    while(i<n){
        if(st.empty() || a[i]>=a[st.top()]) // If current bar height is more, then max wont change so just push
            st.push(i++);
        else{
            int tp=st.top();
            st.pop();
            int temp=a[tp]*((st.empty())?i:i-st.top()-1);// Note this math here,
                                        // Basically if st is empty then the whole of the histogram before this point i is considered
                                        // The alternative is area formed by histograms from behind the considered point
            if(temp>ans){
                ans=temp;
            }
        }
    }
    while(!st.empty()){
        int tp=st.top();
        st.pop();
        int temp=a[tp]*((st.empty())?i:i-st.top()-1);
        if(temp>ans){
            ans=temp;
        }
    }
    return ans;
}

int main(){
    int arr[]={6,2,5,4,5,1,6};
    int size=sizeof(arr)/sizeof(int);
    cout<<largestArea(arr,size)<<endl;
    return 0;
}
