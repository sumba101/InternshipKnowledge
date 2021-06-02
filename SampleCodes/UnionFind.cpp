//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;
int find(vector<pair<int,int>>&a, int i){
    return (a[i].first==i)?i:a[i].first=find(a,a[i].first);
}
int Union(int x,int y,vector<pair<int,int>>&a){ // Returns -1 if it is already connected and in same subset, else connects it and returns 1
    int px=find(a,x);
    int py=find(a,y);
    if(px==py){
        return -1;
    }
    if(a[px].second>a[py].second){
        a[py].first=px;
        a[px].second+=a[py].second;
    }else{
        a[px].first=py;
        a[py].second+=a[px].second;
    }
    return 1;
}

int main(){
    int n=10;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        a.emplace_back(make_pair(i,1));
    }
    int in1[]={0,3,5,6,6,2,9,4};
    int in2[]={4,1,9,7,8,3,4,3};
    for(int i=0;i<8;i++){
        cout<<Union(in1[i],in2[i],a)<<endl;
    }
    return 0;
}
