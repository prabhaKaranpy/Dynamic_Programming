class Solution {
public:
    bool f(int i, string &s, map<string, int> &mp, int &m, vector<int> &dp){
        // base case
        if(i == m) return true; 
        if(dp[i] != -1) return dp[i]; 
        for(int j = i+1; j <= m; j++){
            if(mp[s.substr(i, j-i)] > 0 && f(j, s, mp, m, dp)){
                return dp[i] = 1; 
            }
        }
        // if not found in map, then return false and store it on dp.
        return dp[i] = 0; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> mp; 
        int m = s.size(); 
        vector<int> dp(m, -1); 
        int n = wordDict.size(); 
        for(int i = 0; i < n; i++){
            mp[wordDict[i]] ++; 
        }
        bool ans =  f(0, s, mp, m, dp); 
        // for(int &it : dp) cout<<it<<"  ";
        return ans; 
    }
};
