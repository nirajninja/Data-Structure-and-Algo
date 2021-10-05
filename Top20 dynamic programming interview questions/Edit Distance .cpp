/*



Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.

*/



int editDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        int dp[n+1][m+1]={0};
        
    for(int i=0;i<=n;i++)
       dp[i][0]=i;
       
       for(int j=0;j<=m;j++)
       dp[0][j]=j;
       
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else {
                    dp[i][j]=1+min (dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]) );
                }
            }
        }
        return dp[n][m];
    
    }
};
