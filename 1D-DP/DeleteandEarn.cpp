/* 740. Delete and Earn */


Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        map<long long, long long>mp;
        for(auto i : nums) {
            mp[i]++;
        }
        long long maxVal=0;
        for(auto j : mp) {
            maxVal=max(maxVal,j.first);
        }
        vector<long long>earns(maxVal+1, 0);
        for(auto k : mp) {
            earns[k.first]=k.first * k.second;
        }
        vector<long long>dp(maxVal+1, 0);
        dp[0]=0;
        if(maxVal>=1) {
            dp[1]=earns[1];
        }
        for(int i=2;i<=maxVal;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+earns[i]);
        }
        return dp[maxVal];
    }
};
