class Solution {
public:             // Completely coded by me during weekly contest :) 
    int maxIncreasingSubarrays(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> dp(n, 1); 
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i-1]){
                dp[i] += dp[i-1]; 
            }
        }
        int i = n-1; 
        vector<int> hash(n, 0); 
        while(i >= 0){
            hash[i] = 1; 
            int temp = dp[i]; 
            int t = temp; 
            while(temp){
                dp[i] = t; 
                i -= 1; 
                temp -= 1; 
            }
        }
        int maxi = 1; 
        // for(int i = 0; i < n; i++){
        //     maxi = min(maxi, dp[i]); 
        // }
        // maxi = 1; 
        int found = 1;      // this found is used for to denote that the given arr is fully strictly increasing (no break points) :) 
        for(int a = 0; a < n-1; a++){
            if(hash[a]){
                found = 0; 
                int m = max(dp[a], dp[a+1]); 
                m = m/2; 
                int mi = min(dp[a], dp[a+1]); 
                maxi = max(maxi, max(m, mi)); 
            }
        }
        if(found){ 
            return dp[0]/2; 
            // return (dp[0] == n) ? dp[0]/2 : dp[0]; 
        }
        // I used the couple of lines below to view the dp table as well as possible :) 
        // for(int i = 0; i < n; i++) cout<<dp[i]<<"  "; 
        // cout<<endl; 
        return maxi; 
    }
};
