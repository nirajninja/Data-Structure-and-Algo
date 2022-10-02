//parenthesis changes 2
class Solution {
public:
    vector<string>ans;
   
    
    void solve(int open, int close,int n, string s)
    {   
        
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }
        
        // if(open<0 || close<0)
        // {
        //     return ;
        // }
        if(open<n)
        {
        solve(open+1, close,n, s+"(");
        }
        
        if(open>close && close<n)
        {
        solve(open, close+1,n, s+")" );
        }
        
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s="";
        
        int open=n,close=n;
        solve(0,0,n , s);
        return ans;
        
    }
};
