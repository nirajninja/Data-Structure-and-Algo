/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
*/

//solution (bottom up soln)
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
     
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));  
               //={0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        
        return dp[n][m];
    }
};


//top down soln(recursion + memorization)

class Solution {
public:
    int dp[1005][1005];
    
    int solve(string &s1, string &s2, int n, int m)
    {
        if(n==0 || m==0)
        {
            return dp[n][m]=0;
        }
        else if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        else if(s1[n-1]==s2[m-1])
        {
           return dp[n][m]=1 + solve(s1,s2,n-1,m-1);
        }
        else{
          return dp[n][m] = max( solve(s1,s2,n-1,m) , solve(s1,s2,n,m-1));
            
        }
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string s1, string s2) {
     
        memset(dp,-1,sizeof(dp));
        int n=s1.size();
        int m=s2.size();
        
        return solve(s1,s2,n,m);
        
    }
};

//happy coding.
