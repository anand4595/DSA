

class solveFirstOcc {
//	using binary search - iterative and recursive

    public int binarySearchIterative(int[] nums, int target) {
        int ans = -1;
        int s = 0;
        int e = nums.length - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                ans = m;
                e = m - 1;
            } else if (nums[m] < target) s = m + 1;
            else e = m - 1;
        }
        return ans;
    }
}

class solveLastOcc {
    //	using binary search - iterative and recursive
    public int binarySearchIterative(int[] nums, int target) {
        int ans = -1;
        int s = 0;
        int e = nums.length - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                ans = m;
                s = m + 1;
            } else if (nums[m] < target) s = m + 1;
            else e = m - 1;
        }
        return ans;
    }

}

class Solve {
    public int[] LinearSearch(int[] nums, int target) {
        int fp = -1;
        int lp = -1;
        for (int i = 0; i < nums.length; i++) {
            boolean isEqual = nums[i] == target;
            if (isEqual) {
                fp = fp == -1 ? i : fp;
                lp = i;
            }
        }
        return new int[]{fp, lp};
    }

    public int[] binarySearchIterative(int[] nums, int target) {
        int fOcc = new solveFirstOcc().binarySearchIterative(nums, target);
        int lOcc = new solveLastOcc().binarySearchIterative(nums, target);
        return new int[]{fOcc, lOcc};
    }

}

class Solution {
    public int[] searchRange(int[] nums, int target) {
//		return  new int[] {-1,-1};
        return new Solve().binarySearchIterative(nums, target);
    }
}