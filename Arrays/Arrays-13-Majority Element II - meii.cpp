class Solution {
private:
    //using hasmap for counting the no of occurances
    vector<int> sol_1(vector<int>& nums)
    {
        vector<int> ans;
        unordered_map<int,int> m;
        int nums_length=nums.size();
        int req_counts = nums_length/3;
        for(int i=0;i<nums_length;i++)
        {
            m[nums[i]]++;
            // if(m[nums[i]]>req_counts)ans.push_back(nums[i]);
        }
        for(auto &it:m)
        {
           if(it.second>nums_length/3)ans.push_back(it.first);
        }
        return ans;
    }
  /*
  refer to sol 2 of majority element 1
  we use the concept of voting here we have two element el_1 and el_2 and thei respective counts c_1 and c_2 
  since just took two vars since more than 33 percent at max can be two element since if two are 34% 34% other will be 32%
  we traverse the array and if the nums[i] == el_1 we increase c_1 and if nums[i] == el_2 we increase c_2
  and if the count of c1 ==0 we set it to nums[i] and make c_1 =1 and if the count of c2 ==0 we set it to nums[i] and make c_2 =1
  
  and if the nums[i] doesn't match any of the condition then we decrement both of c_1 and c_2 stating that nums[i] is not equal to any
  
  //finally we will have two elements which have possibility of being greater n/3 so to make sure if any of them is greater than n/3 we traverse the array a
  and count their occurances 

  
  and finally we a
  */
    //sol 2
    vector<int> sol_2(vector<int>& nums)
    {
        vector<int> ans;
        int n = nums.size();
        int c_1=0;
        int el_1=INT_MAX;
        int c_2= 0;
        int el_2=INT_MAX;
        for(int i = 0; i<n ; i++)
        {
            if(el_1==nums[i])
            {
                c_1++;
            }
            else if(el_2==nums[i])
            {
                c_2++;
            }
            else if(c_1==0)
            {
                c_1=1;
                el_1=nums[i];
            }
            else if(c_2==0)
            {
                c_2=1;
                el_2=nums[i];
            }
            else
            {
                c_1--;
                c_2--;
            }
        }


        //now we have the el_1 and el_2 which can be our majority elemeent
        //we are not sure because we substracted for each element which do
        //not macth either el_1 and el_2 -1 in both hence the values might not be correct
        //hence once again we will try to make a count and if the count is greater than n/3 we push them to ans array
        //using c_1 and c_2 to count the occurances of the elemnet int the array
        c_1=0;
        c_2=0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==el_1)c_1++;
            if(nums[i] == el_2)c_2++;
        }
        if(c_1>n/3)ans.push_back(el_1);
        if(c_2>n/3)ans.push_back(el_2);
        return ans;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        // return sol_1(nums);
        return sol_2(nums);
    }
};
