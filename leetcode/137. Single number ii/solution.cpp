class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> map;
        for(int i = 0; i<nums.size(); i++){
            auto temp = map.find(nums[i]);
            if(temp == map.end()){
                map.insert({nums[i], 1});
            }else
                temp->second = temp->second+1;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(map.find(nums[i])->second == 1)
                return nums[i];
        }
        return -1;
    }
};
