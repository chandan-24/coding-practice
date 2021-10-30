class Solution {
    public:
    int t[101][1002];

    int kpsack(vector<int>& nums, int n, int w){
        if(n==0 && w==0) return 1;
        if(n==0) {return 0;}
        if(t[n][w]!=-1) return t[n][w];
        
        if(nums[n-1]<=w)
        {
            t[n][w]= (kpsack(nums, n-1, w)+ kpsack(nums, n-1, w-nums[n-1]));
        }
        else
        {
            t[n][w]= kpsack(nums, n-1, w);
        }
        return t[n][w];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        memset(t,-1,sizeof(t));
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        if(S>sum) return 0;
        if((S+sum)%2!=0) return 0;
        else ans=(S+sum)/2;
        return kpsack(nums,n,ans);
        
    }
};