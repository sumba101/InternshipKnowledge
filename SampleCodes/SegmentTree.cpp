//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;

int build(vector<int>&seg,int a[], int s, int e, int i){
    if(s==e){
        seg[i]=a[s];
        return a[s];
    }
    int mid=s+(e-s)/2;
    return seg[i]= build(seg,a,s,mid,2*i +1 )+ build(seg,a,mid+1,e,2*i + 2 );
}

int getForQuery(vector<int>&seg,int s, int e, int i,int sq,int eq){
    if(sq> e || s> eq){
        return 0;
    }
    if(sq <= s && eq>=e){
        return seg[i];
    }
    int mid=(s+e)/2;
    return getForQuery(seg,s,mid,2*i+1,sq,eq) + getForQuery(seg,mid+1,e,2*i+2,sq,eq);
}

void updateVal(vector<int>&seg,int s, int e, int i,int diff){
    if(s> i || i> e){
        return ;
    }
    seg[i]+=diff;
    if(s!=e){
        int mid = (s+e)/2;
        updateVal(seg,s,mid,2*i+1,diff);
        updateVal(seg,mid+1,e,2*i+2,diff);
    }
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> segmenttree(4*n);
    build(segmenttree,arr,0,n-1,0);
    for(int x: segmenttree){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<getForQuery(segmenttree,0,n-1,0,1,3)<<endl;

    int nw = 6;
    int diff= nw - arr[1];
    arr[1]=nw;
    updateVal(segmenttree,0,n-1,0,diff);
    for(int x: segmenttree){
        cout<<x<<" ";
    }

    return 0;
}
