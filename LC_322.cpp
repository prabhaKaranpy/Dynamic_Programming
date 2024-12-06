//  COIN CHANGE 

class Solution {
public:
    int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp){
        // Base Condition
        if(ind == 0){ 
            if(tar % coins[0] == 0){
                return (tar / coins[0]);
            }
            return 1e8;
        }
        // Explore all paths in terms of index : (take, notTake)
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = 0 + f(ind-1, tar, coins, dp);
        int take = 1e8;
        if(coins[ind] <= tar) take = 1 + f(ind, tar-coins[ind], coins, dp);
        // Return Minimum Coin Denomination
        
        return(dp[ind][tar] = min(notTake, take));
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if(ans > 1e4) ans = -1;
        return ans;
    }
};
