//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;

void search(string txt,string pat){
    unordered_map<char,int>bad;
    for(int i=0;i<pat.size();i++){
        bad[pat[i]]=i;
    }
    int i=0;
    int n=txt.size(),m=pat.size();
    while(i<=n-m){
        int j=m-1;
        while(j>=0 && txt[i+j] == pat[j]){
            j--;
        }
        if(j>=0){
            i += max(1, j-bad[txt[i+j]]);
        }else{
            cout<<"Match at: "<<i<<endl;
            i += (i + m< n)?m-bad[txt[i+m]]: 1;
        }
    }
}

int main(){
    string txt="ABAAABCD";
    string pat="ABC";
    search(txt,pat);
    return 0;
}
