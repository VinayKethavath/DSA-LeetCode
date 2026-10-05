class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int balance=0;
        int candidate;
        for(int i=0;i<nums.size();i++){
            if(balance==0){
                candidate=nums[i];
            }
            if(nums[i]==candidate){
                balance++;
            }
            else{
                balance--;
            }
        }
        return candidate;
    }
};