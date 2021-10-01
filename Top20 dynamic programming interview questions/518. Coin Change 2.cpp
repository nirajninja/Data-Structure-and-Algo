/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
 */
  //solution
  

class Solution {
public:
    
    int dp[301][5000+1];
    int solve(vector<int>&coins, int amount, int n)
    {
        if(amount==0)
        {
            return dp[n][amount]=1;
        }
        if(n==0)
        {
            return dp[n][amount] =0;
        }
        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }
        
        
        if(coins[n-1]<=amount)
        {
            dp[n][amount]= solve(coins, amount-coins[n-1], n)+ solve(coins, amount,n-1); 
        }
        else{
             dp[n][amount]= solve(coins, amount, n-1);
            }
        
        return dp[n][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n =coins.size();

       
        memset(dp,-1,sizeof(dp));
        return solve( coins,amount, n);
    }
};
