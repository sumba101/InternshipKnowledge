//
// Created by spawnfire on 17/05/21.
//
#include <bits/stdc++.h>
using namespace std;

long long frac[27];
void setFrac(){
    frac[0]=1;
    for(int i=1;i<27;++i){
        frac[i]=frac[i-1]*i;
    }
}
void permutation(const string& s,int n){
    string ans;
    unordered_map<char,int> freq;
    for(char x:s){
        freq[x]++;
    }
    int start=0;
    long long sum;

    while( start<s.size()){
        sum=0;
        for(char c='a';c<='z';c++){
            if(freq[c]==0)
                continue;
            freq[c]--;
            long long temp=frac[s.size()-start-1];
            for(char i='a';i<='z';i++){
                temp/=frac[freq[i]];
            }
            sum+=temp;
            if(sum>=n){
                ans+=c;
                start++;
                n-=sum-temp; // NOTE THIS IS THE MOST IMPORTANT STEP, THIS REDUCES n WHEN IT GETS TO LAST 2-3 LETTERS, ELSE INFINITE LOOP
                break;
            }
            else{
                freq[c]++;
            }
        }
    }
    cout<<ans;
}
int main(){
    string temp="geeksquiz";
    setFrac();
    permutation(temp,2);
    return 0;
}
