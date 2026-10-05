class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                nums1.push_back(nums[i]);
            }
            else{
                nums2.push_back(nums[i]);
            }
        }
        int k=0;
        for(int i=0;i<nums.size();i+=2){
            nums[i]=nums1[k];
            k++;
        }
        k=0;
        for(int i=1;i<nums.size();i+=2){
            nums[i]=nums2[k];
            k++;
        }
        nums1.clear();
        nums2.clear();
        return nums;
    }
};