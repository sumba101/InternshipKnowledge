//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;
void permutation(string s,int i, int r){
    if(i<r){
        for(int j=i;j<=r;j++){
            swap(s[i],s[j]);
            permutation(s,i+1,r);
            swap(s[i],s[j]);
        }
    }else{
        cout<<s<<endl;
    }
}
int main(){
    string temp="ABC";
    permutation(temp,0,temp.size()-1);
    return 0;
}
