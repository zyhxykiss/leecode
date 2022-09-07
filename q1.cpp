class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 方法一：暴力法
        for (int i = 0; i < nums.size()-1; i++){
            int possible_j = target - nums[i];
            for (int j = i+1; j < nums.size(); j++){
                if (nums[j] == possible_j){
                    return {i, j};
                }
            }
        }
        return {};
        
        // 方法二：哈希表
        std::unordered_map<int, int> map;
        int length = nums.size();
        for (int i = 0; i < length; i++){
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()){
                // ans[0] = iter->second;
                // ans[1] = i;
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
};


