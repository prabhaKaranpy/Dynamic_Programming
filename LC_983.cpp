class Solution {      // MEMOIZATION - DP 
public:
    int f(int i, vector<int> &days, vector<int> &costs, unordered_set<int> &sett, int &n, vector<int> &dp){
        // base case 
        if(i > days[n-1]) return 0; 
        // if the current day is not in days[], just skip and continue as well as possible! 
        if(sett.find(i) == sett.end()) return f(i+1, days, costs, sett, n, dp); 
        if(dp[i] != -1) return dp[i]; 
        // calculate 3-forms of costs
        int oneDay = costs[0] + f(i+1, days, costs, sett, n, dp); 
        int oneWeek = costs[1] + f(i+7, days, costs, sett, n, dp); 
        int oneMonth = costs[2] + f(i+30, days, costs, sett, n, dp); 
        return dp[i] = min(oneDay, min(oneWeek, oneMonth)); 
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(); 
        unordered_set<int> sett(days.begin(), days.end()); 
        vector<int> dp(days[n-1]+1, -1); 
        int dollars = f(1, days, costs, sett, n, dp);
        return dollars;  
    }
};
