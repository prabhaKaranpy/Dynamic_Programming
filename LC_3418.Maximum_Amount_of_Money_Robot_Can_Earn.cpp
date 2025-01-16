class Solution {
public:
    int f(int i, int j, int rob, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp) {
    if (i == 0 && j == 0){
        if(rob > 0 && coins[i][j] < 0) return 0;
        return coins[i][j]; 
    }
    if (i < 0 || j < 0) return -1e9; 
    if (dp[rob][i][j] != -1e9) return dp[rob][i][j];
    int up = 0; 
    if(coins[i][j] >= 0) up = coins[i][j] + f(i - 1, j, rob, coins, dp);
    else{
        if(rob > 0){
            // up = abs(coins[i][j]) + f(i-1, j, rob-1, coins, dp); 
            // up = abs(coins[i][j]) + f(i-1, j, rob, coins, dp); 
            up = max((0 + f(i-1, j, rob-1, coins, dp)), (coins[i][j] + f(i-1, j, rob, coins, dp))); 
        }
        else{
            up = coins[i][j] + f(i-1, j, rob, coins, dp); 
        }
    }
    int left = 0; 
    if(coins[i][j] >= 0) left = coins[i][j] + f(i, j - 1, rob, coins, dp); 
    else{
        if(rob > 0){
            left = max((0 + f(i, j-1, rob-1, coins, dp)), (coins[i][j] + f(i, j-1, rob, coins, dp))); 
        }
        else{
            left = coins[i][j] + f(i, j-1, rob, coins, dp); 
        }
    }
    return dp[rob][i][j] = max(up, left);
}

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(); 
        int m = coins[0].size(); 
        vector<vector<vector<int>>> dp(3, vector<vector<int>> (n, vector<int>(m, -1e9)));
        int rob = 2; 
        
        int ans = f(n-1, m-1, rob, coins, dp); 
        // cout<<n<<"  "<<m<<endl; 
        // for(auto &it : dp){
        //     for(auto &e : it){
        //         for(auto &i : e){
        //             cout<<i<<"  "; 
        //         }
        //         cout<<endl; 
        //     }
        //     cout<<"\n\n"; 
        // } 
        // cout<<"--------------------------------------------\n"; 
        return ans; 
    }
};
