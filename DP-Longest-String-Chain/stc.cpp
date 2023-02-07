class Solution {
public:

    /*
    Longest String Chain is similar to longest increasing subsequence(lis) if we see , acc. to given conditions if we sort the given array then it si very similar to lis

    since longest same as longest , chain is same as subsequence we have to care about string
    here it is asking that the next string must have one more character and it must be present such that order of it not affected for it we will design a function str_compare which will return if it is the correct string we are looking or not
    
    */

    bool str_compare(string& s1 , string& s2)
    {
        //first we compare the length since we require the string length difference of just 1 
        if(s1.size() != s2.size()+1)return false;
        //now comparing the required string pattern to be same i.e
        /*
            s1 = bcda  s2 = bcd
            we will take two pointer starting from index 0 and if both the char are same we icnrment both pointer and if not we increment just pointer of s1 if both the pointer reaches to end when p1 reaches then correct else not
            eg. s1 = bcda  s2 = bcd
            p1 0 , p2 = 0
            index(0,0) element equal increment both p1,p2 = (1,1)
            1,1 indexes value same incerment at 2,2 index values same increment pointer 3,3  at 3 in s1 we have a element so we increment just p1 p1 reaches 4 and also s1 ends and we found both reaches at end 
            similar for s1 =abcd s2 =bcd , (bacd ,bcd) 
            but when checking for dcba,bcd  the second pointer will never reach end when first reaches hence return false  
        */
        //pointer 
        int p1 = 0;
        int p2 = 0;
        while(p1<s1.size())
        {
            if(p2<s2.size() && s1[p1] == s2[p2])
            {
                p1++;
                p2++;
            }
            else p1++;
        }
        if(p1 == s1.size() && p2 == s2.size())return true;
        return false;

    }
    //comparator for string sorting
    static bool comp (string& s1, string& s2)
    {
        return s1.size()<s2.size();
    }
    //using the lis most_optimized approach 
    int most_optimized(vector<string>& nums)
    {
        sort(nums.begin(), nums.end(),comp);
        int n = nums.size();
        vector<int> lis(n,1);
        int max_final_lis = 1;
        for(int i = 0 ; i<n; i++)
        {
            for(int j= 0; j<i; j++)
            {
                
                //here a subtle change for comparison since we now have a slight more comparison to be done
                if(str_compare(nums[i],nums[j])  && lis[j]+1 > lis[i])
                {
                    lis[i] = 1+lis[j];
                    max_final_lis = max(max_final_lis,lis[i]);
                }
            }
        }
        return max_final_lis;
    }
    int longestStrChain(vector<string>& words) {
        return most_optimized(words);
    }
};
