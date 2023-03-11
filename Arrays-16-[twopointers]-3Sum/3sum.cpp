class Solution {
private:
    //APPROACH 1
    /*
    use three for loop 
    one run i -> 0 to n-3
                j -> i+1 to n-2
                    k-> j+1 to n-1
                    calculate the sum to of nums[i]+nums[j]+nums[k]
        push them inside a set and then return the ans. pushing them inside the set to confirm we get only unique sets
    

    */
    //APPROACH 2
    /*
         WE USE A HASHMAP FOR COUNTING THE OCCURANCES OF EACH ELEMENT
         what do do now 
         is run two for loops
         a+b+c 
         one for a ->0 to n-3
                hashmap[nums[a]--]
                    b->a+1 to n-2
                    hashmap[nums[b]--]
                        for other i.e c we use find in the hashmap[-(a+b)] if it value is greater than 1 we take and push in the answer nums[a],nums[b],this found from hashmap we take and reduce the count of hashmap[nums[-(a+b)]
                    hashmap[nums[b]++]
                hashmap[nums[a]++]


        //important thing after visitng nums[a] we reduce the value from the counter  hashmap[nums[i]--] so that we don't use this already used element
        similarly for b also we do 
    */
    //APPROACH 3
    //using two pointers approach
    /*
        here [-1,0,1,2,-1,-4]
        we have sorted the array -4,-1,-1,1,0,1,2
        concept used
        given a+b+c = 0 
        so we do a = -(b+c)
        for so each a we try to find -(b+c) using two pointers appraoch

        //also since there are repitative elements to take care of it
        if we have used same element as 'a' once we won't used the logic 
        if(p==0 || (p>0 && nums[p]!=nums[p-1])) also same way if we have used for 'a'  a element nums[i] then we won't use again hence used logic 
        int temp = nums[i];
        i++;
        while(i<j && nums[i] ==temp)i++;
        this second state arises when we are pushing the element we don't want another same element for i since we have already handled case of a
        also we are not caring for nums[j]  since if i is changed then sum won't be same using the same j hence it will be automatically handled
    */
    vector<vector<int>> two_pointers(vector<int>& nums)
    {
        //since we want the ans in form of vector
        vector<vector<int>> ans;
        // unordered_set<vector<int>> s;
        int n = nums.size();
        for(int p=0; p<n-2;p++)
        {
            if(p==0 || (p>0 && nums[p]!=nums[p-1]))
            {
                int req = -(nums[p]);
                int i = p+1;
                int j =n-1;
                while(i<j)
                {
                    if(nums[i]+nums[j] == req)
                    {
                        ans.push_back({nums[p],nums[i],nums[j]});
                        int temp = nums[i];
                        //here suppose we have taken into account ith element to be -1 and suppose next element is also -1 
                        //then we will get duplicates hence to avoid that we keep the i at such position where nums[i] != ith element which has been already used               
                        i++;
                        while(i<j && nums[i] ==temp)i++;
                    }
                    else if(nums[i]+nums[j] < req)
                    {
                        i++;
                    }
                    else
                    {
                        j--;
                    }
                }
            }
        }
        
        return ans;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());  
        return two_pointers(nums);  
    }
};
