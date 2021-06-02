//
// Created by spawnfire on 21/05/21.
//
#include<bits/stdc++.h>
using namespace  std;

int find(vector<vector<int>> arr, int n){
    int i=0;
    int j=0;
    while(i<n&&j<n){
        if(arr[i][j]==0){
            j++;
        }else{
            i++;
        }
    }
    if(i==n){
        return -1;
    }else{
        for(int x=0;x<n;x++){
            if(arr[i][x]==1){
                return -1;
            }
            if(arr[x][i]==0 && i!=x){
                return -1;
            }
        }
        return i;
    }
}
int main(){
    return 0;
}

