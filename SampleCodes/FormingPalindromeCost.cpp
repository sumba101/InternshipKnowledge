//
// Created by spawnfire on 18/05/21.
// Question: https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
int recurse(string str,int i,int j){
    // cout<<i<<" "<<j<<endl;
    if(i>=j){return 0;}
    // if(i==j){return 0;}
    if(str[i]==str[j]){return recurse(str,i+1,j-1);}
    if(str[i]!=str[j]){
        return 1 + min(recurse(str,i+1,j),recurse(str,i,j-1));
    }
}
int countMin(string str){
    // return recurse(str,0,str.size()-1);
    int dp[str.size()][str.size()];
    int n=str.size();
    for(int i=0;i<n;++i){
        dp[i][i]=0;
    }
    for(int i=1;i<n;++i){
        dp[i][i-1]=0;
    }
    int itr=1;
    while(itr<n){
        for(int i=0;i+itr<n;i++){
            int j=i+itr;
            if(str[i]==str[j]){
                dp[i][j]= dp[i+1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
        itr++;

    }
    // for(int i=0;i<n;i++){
    //     cout<<endl;
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    // }
    // cout<<endl;
    return dp[0][n-1];
}

