class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int total_len = nums1.size() + nums2.size();
        vector<int> nums;
        while ((i < nums1.size()) && (j < nums2.size())){
            if (nums1[i] >= nums2[j]){
                nums.push_back(nums2[j]);
                j++;
            }
            else{
                nums.push_back(nums1[i]);
                i++;
            }
        }
        if(i < nums1.size()){
            for (int k = i; k < nums1.size(); k++){
                nums.push_back(nums1[k]);
            }
        }
        if(j < nums2.size()){
            for (int k = j; k < nums2.size(); k++){
                nums.push_back(nums2[k]);
            }
        }
        if (total_len % 2 == 0) return (nums[(total_len-1)/2] + nums[(total_len-1)/2 + 1]) / 2.0;
        else return nums[(total_len-1)/ 2.0];
    }
};
