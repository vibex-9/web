class Solution {
//foxed
    vector<vector<vector<long long>>> dp;

     long long solve(int l, int r, int flag, vector<int> &req, int n)
     {
        if(l==0 && r==n-1)return 0;
        if(dp[l][r][flag]!=-1)
          return dp[l][r][flag];
        
        long long mini = 1e18;
        
        if(flag){
           if(l-1>=0)
            mini = min(mini, solve(l-1, r, 1, req, n) + 1ll*(n-r+l-1)*(req[l]-req[l-1]));
           if(r+1<n)
            mini = min(mini, solve(l,r+1,0, req, n) + 1ll*(n-r+l-1)*(req[r+1]-req[l]));
        }
        else{
           if(l-1>=0)
            mini = min(mini, solve(l-1, r, 1, req, n) + 1ll*(n-r+l-1)*(req[r]-req[l-1]));
           if(r+1<n)
            mini = min(mini, solve(l, r+1, 0, req, n) + 1ll*(n-r+l-1)*(req[r+1]-req[r]));
        }

        return dp[l][r][flag] = mini;
        
     }
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        
        bool flag = false;
        for(auto x: requests)
         if(x==start)flag=true;

        if(!flag)requests.push_back(start);

        sort(requests.begin(), requests.end());
      
        int len = requests.size();

        dp.assign(len, vector<vector<long long>>(len,vector<long long>(2,-1)));

        int index = lower_bound(requests.begin(), requests.end(), start) - requests.begin();
        
        return solve(index, index, 1, requests, len);
    }
};
