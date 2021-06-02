//
// Created by spawnfire on 17/05/21.
//
// lINK FOR ALTERNATE SOLUTION WITH SMALL SPACE COMPLEXITY: https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
int longestPalin (string S)
{
    // your code here
    int n=S.size();
    int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int i=1;i<n;i++){
        dp[i][i-1]=0;
    }

    int itr=1;
    while(itr<n){
        for(int i=0;i+itr<n;i++){
            int j=i+itr;
            if(S[i]==S[j]){
                dp[i][j]=dp[i+1][j-1] + 2;
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        itr++;
    }
    int maxlen = dp[0][n-1];
    cout<<maxlen<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxlen;
}

// THE OTHER METHOD IS TO MAINTAIN JUST A BOOLEAN TABLE OF PALINDROME EXISTENCE AND KEEP TRACK OF MAXLEN WITH VARIABLE
int longestPalSubstr(string str)
{
    // Length of string str
    int n = str.size();

    // Stores the dp states
    bool table[n][n];

    // Initialise table[][] as false
    memset(table, 0, sizeof(table));

    // All substrings of length 1
    // are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // Check for sub-string of length 2
    int start = 0;

    for (int i = 0; i < n - 1; ++i) {

        // If adjacent character are same
        if (str[i] == str[i + 1]) {

            // Update table[i][i + 1]
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2
    // k is length of substring
    for (int k = 3; k <= n; ++k) {

        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {

            // Ending index of substring
            // of length k
            int j = i + k - 1;

            // Check for palindromic
            // substring str[i, j]
            if (table[i + 1][j - 1]
                && str[i] == str[j]) {

                // Mark true
                table[i][j] = true;

                // Update the maximum length
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    // Return length of LPS
    return maxLength;
}

