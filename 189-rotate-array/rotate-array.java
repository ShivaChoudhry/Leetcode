class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length-1;
        k=k%(n+1);
        reverse(nums, 0,n-k);
        reverse(nums, n-k+1, n);
        reverse(nums, 0, n );
    }

    static void reverse (int [] nums, int left, int right){
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }

    }
}