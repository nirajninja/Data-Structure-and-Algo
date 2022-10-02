class Solution {
public:
    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digits,string& ans,vector<string>&v)
    {
        if(digits.size()==0)
        {
            v.push_back(ans);
            return;
        }
        string d=arr[digits[0]-'0'];
        digits.erase(digits.begin()+0);
        for(int i=0;i<d.size();i++)
        {
            ans.push_back(d[i]);
            solve(digits,ans,v);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string ans="";
        vector<string>v;
        if(digits.size()==0) return v;
        solve(digits,ans,v);
        return v;
    }
};
