```
/*
1.non-recursive binary search yeah it is better and simpler approach
2.just a logn while loop
*/
int n = nums.size();
int left = 0, right = n-1, mid;
while(left<=right){
mid = left + (right-left)/2;
if(nums[mid] == target) return mid;
else if (nums[mid] < target) left = mid+1;
else right = mid-1;
}
return left;
}
```
​