//
// Created by spawnfire on 18/05/21.
//


int editDistance(string s, string t) {
    // Code here
    int n=s.size();
    int m=t.size();
    int dp[n+1][m+1]={0};

    for(int i=0;i<n+1;i++){
        cout<<endl;
        for(int j=0;j<m+1;j++){
            if(i==0){
                dp[i][j]=j;
                cout<<dp[i][j]<<"   ";
                continue;
            }
            if(j==0){
                dp[i][j]=i;
                cout<<dp[i][j]<<"   ";
                continue;
            }
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
                cout<<dp[i][j]<<"   ";
            }else{
                dp[i][j]=1+ min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                cout<<dp[i][j]<<"   ";
            }
        }
    }
    cout<<endl;
    return dp[n][m];

}
