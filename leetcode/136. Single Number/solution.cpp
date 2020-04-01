class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(vector<int>::iterator iter = nums.begin() ; iter != nums.end() ;iter++){
            ret ^=*iter;
        }
        return ret;
    }
};
