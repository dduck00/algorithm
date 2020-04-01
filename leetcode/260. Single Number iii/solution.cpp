class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            auto temp = mp.find(nums[i]);
            if(temp == mp.end()){
                mp.insert({nums[i], 1});
            }
            else
                temp->second = temp->second + 1;
        }
        
        vector<int> ret;
        
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(nums[i])->second == 1)
                ret.push_back(nums[i]);
        }
        return ret;
    }
};
