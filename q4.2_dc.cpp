class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        *    二分法
        */
        int size1 = nums1.size(), size2 = nums2.size();
        int total_len = size1 + size2;
        int k = (int)(total_len + 1) / 2;
        if (total_len % 2 == 0) return (double)(mink(nums1, nums2, k) + mink(nums1, nums2, k+1)) / 2;
        else return (double)mink(nums1, nums2, k);
    }

private:
    int mink(vector<int> & nums1, vector<int> & nums2, int k)
    {
        int i = 0, j = 0;
        int p1 = 0, p2 = 0;
        int mid = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        while(true){
            if (i == size1) return nums2[j + k - 1];
            if (j == size2) return nums1[i + k - 1];
            if (k == 1) return min(nums1[i], nums2[j]);
            mid = k / 2;
            int new_i = min(size1, i + mid) - 1;
            int new_j = min(size2, j + mid) - 1;
            p1 = nums1[new_i];
            p2 = nums2[new_j];
            if (p1 > p2){
                k -= (new_j - j + 1);
                j = new_j + 1;
            }
            else{
                k -= (new_i - i + 1);
                i = new_i + 1;
            }
        }
    }
};
