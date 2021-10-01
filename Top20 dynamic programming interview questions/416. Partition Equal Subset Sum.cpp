/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

//solution

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        
        
        int s=sum/2;
        int n=nums.size();     
        bool dp[n+1][s+1];//={false};
        memset(dp,false,sizeof(dp));
        
        for(int i=0;i<=n;i++)
        
        {
            for(int j=0;j<=s;j++)
            {
             if(i==0)
                {
                dp[i][j]=false;
                }
                if(j==0)
                {
                    dp[i][j]=true;
                }
            }
            
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {   
                if(nums[i-1] <= j)
                {
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][s];
        
    }
};
