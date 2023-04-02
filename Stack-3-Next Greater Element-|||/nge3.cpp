class Solution {
private:

    /*
    
        stack approach of finding next greater element won't work here since next greater element will give the first next greater element present in right side of the current element which is not good since eg in 13685 we need 5 to replace at 6 element position but stack appraoch of finding next greater element will return 6 which is not required hence this approach give wrong result
    */
    // int stack_approach(int n)
    // {
    //     string s = to_string(n);
    //     int s_size = s.size();
    //     stack<vector<int>> st;
    //     //temporarily initializing i 
    //     int i = s_size;
    //     for(i=s_size-1;i>=0; i--)
    //     {

    //         while(!st.empty() && st.top()[0]<=s[i]-'0')st.pop();
    //         if(!st.empty())
    //         {
    //             swap(s[i],s[st.top()[1]]);
    //             int j = st.top()[1];
    //             while(j+1<n)
    //             {
    //                 swap(s[j],s[j+1]);
    //                 j++;
    //             }
    //             stringstream ss;
    //             ss<<s;
    //             int ans;
    //             ss>>ans;
    //             return ans;
    //         }
    //         st.push({s[i]-'0',i});
    //     }
    //     return -1;
    // }


    /*
    
        this string comparison is costly as well as getting some weird wrong solution but the approach is correct 
    */
    // int sol_2(int n){
    //     string s = to_string(n);
    //     int s_size = s.size();
    //     int pos= n;
    //     int i = s_size-1;
    //     for(i = s_size-1; i>0; i-- )
    //     {
    //         if(s[i]-'0'>s[i-1]-'0')
    //         {
    //             pos = i-1;
    //             break;
    //         }
    //     }
    //     cout<<"s"<<s<<endl;
    //     if(i==0)return -1;
    //     //element just greater than the  pos element
    //     int pos_el = s[pos]-'0';
    //     int just_greater = INT_MAX;
    //     int just_greater_pos = n;
    //     for(int j = pos+1;j<n;j++)
    //     {
    //         if(s[j]-'0'>pos_el && just_greater>s[j]-'0')
    //         {
    //             just_greater=s[j]-'0';
    //             just_greater_pos = j;
    //         }
    //     }
    //     swap(s[pos],s[just_greater_pos]);
    //     int mid = (n-pos)/2;
    //     for(int i=1; i<=mid; i++)
    //     {
    //         swap(s[pos+i],s[n-i]);
    //     }
    //     int ans = 0;
    //     // cout<<"s"<<s<<endl;
    //     for(int i= 0; i<s_size; i++)
    //     {
    //         ans= ans*10+(s[i]-'0');
    //     }
    //     return ans;

    // }

    /*
        here and in sol_2 taken the same approach
        we store all the elements in a vector int the same order eg 12 stored as [1,2]
        then we run a for loop and find the first number from right side which is smaller than the right element --->
            then we replace this first smaller found number with a element which is just greater then this first smaller number .
        

    */
    int sol_3(int n)
    {
        int temp = n;
        vector<int> vec;
        while(temp !=0)
        {
            vec.push_back(temp%10);
            temp = temp/10;
            
        }
        //the above while loop would have reversed the number
        //since we want the above number just each char stored in vector
        reverse(vec.begin(),vec.end());
        int vec_size = vec.size();
        
        // int pos = n;
        for(int i = vec_size-1; i>0; i-- )
        {
            if(vec[i]>vec[i-1])
            {
                int pos = i-1;
                //check and form the answer here itself and return from here 
                
                //finding a element which is JUST greater then the pos position element 
                int just_greater = INT_MAX;
                int just_greater_pos = n;
                for(int j= pos+1; j<vec_size ; j++)
                {
                    if(vec[j]>vec[pos] && vec[j]<=just_greater)
                    {
                        just_greater=vec[j];
                        just_greater_pos=j;
                    }
                }
                //swapping the first smaller element from right and the elemnt which is JUST greater than that element
                swap(vec[pos],vec[just_greater_pos]);
                //we are reversing the element right of pos position element 
                reverse(vec.begin()+pos+1,vec.end());

                //converting the vec array to int back preparing the solution
                long long  ans = 0;
                for(int k = 0; k<vec_size; k++)
                {
                    ans = ans*10+(long long )vec[k];
                }
                return (int)ans;
                
            }
        }
        return -1;
    }
public:
    int nextGreaterElement(int n) {
        int ans = sol_3(n);
        //this is done since some element which are also given above does not fit in 32 bit integer hence checking if doing the above work on them they would be 2 complemented or something hence return -1 for them
        if(ans <n)return -1;
        else return  ans ;
    }
};
