class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        set<vector<int>> s;
        if(nums.size()<=2){
           return ans;
        }
        for(int i =0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
      
                if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }
                else if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }
                else{
                    vector<int> v={nums[i],nums[left],nums[right]};
                    s.insert(v);
                    left++;
                    right--;
                }
        }}
        for(auto j:s){
            ans.push_back(j);
        }
        return ans;
        
    }
};
