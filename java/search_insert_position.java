class Solution {
    public int searchInsert(int[] nums, int target) {
        
        if(nums.length==0)  return 1;
        if(nums[nums.length-1]<target) return nums.length;
        int i=0;
        int l=nums.length;
         while(i<=l)
         {
            int mid=i+(l-i)/2;
             if(nums[mid]==target)
                 return mid;
             else if(nums[mid]>target)
             { l=mid-1; }
             else {i=mid+1; }
         }
        return i;
    }
}
