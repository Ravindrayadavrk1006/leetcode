
class Solution {

//TLE
//naive recursive solution O(2^n) giving tle, to take all the such groups possible
int solTakeCharacters(int start, int end, string& s, int k, vector<int>& count, int char_count){
    //base case
    if(count[0]>=k && count[1]>= k && count[2]>= k)return char_count;
    //if start>end and our above case didn't satisfy
    if(start>end)return INT_MAX;
    //try from left side
    count[s[start]-'a']++;
    int left = solTakeCharacters(start+1, end, s, k, count, char_count+1);
    //trying right side
    count[s[start]-'a']--;
    //creating the disturbance
    count[s[end]-'a']++;
    int right = solTakeCharacters(start, end-1, s, k, count, char_count+1);
    count[s[end]-'a']--;
    return min(left, right);
}

//giving TLE
//giving tle here we are taking a element from start , b element from end and forming all possible correct answer 
int sol2(string s, int k){
    int n = s.size();
    vector<vector<int>> from_start(n,vector<int>(3,0));
    vector<vector<int>> from_end(n,vector<int>(3,0));
    from_start[0][s[0]-'a'] = 1;
    from_end[n-1][s[n-1]-'a'] = 1;
    
    //at each element from left and right of string , we are caluclting the count of a, b,c till that point
    for(int i = 1;  i<n; i++){
        //copy previous values
        from_start[i][0] = from_start[i-1][0];
        from_start[i][1] = from_start[i-1][1];
        from_start[i][2] = from_start[i-1][2];
        //increment the current char value by 1
        from_start[i][s[i]-'a'] = from_start[i][s[i]-'a']+1 ;
        //copy previous values
        from_end[n-i-1][0] = from_end[n-i][0];
        from_end[n-i-1][1] = from_end[n-i][1];
        from_end[n-i-1][2] = from_end[n-i][2];
        from_end[n-i-1][s[n-i-1]-'a'] = from_end[n-i-1][s[n-i-1]-'a'] +1;
    }
    // for(int i = 0; i<n; i++){
    //     cout<<from_start[i][0]<<" "<<from_start[i][1]<<" "<<from_start[i][2]<<endl;
    // }
    // for(int i = 0; i<n; i++){
    //     cout<<from_end[i][0]<<" "<<from_end[i][1]<<" "<<from_end[i][2]<<endl;
    // }

    //if either of a,b,c is less than k we can't find any solution 
    if(from_start[n-1][0]<k || from_start[n-1][1]<k || from_start[n-1][2]<k)return -1;
    if(k ==0 )return 0;
    int ans = n;
    //normal cases
    //calculating first window
    int start = 0;
    int end = n-1;
    cout<<"end "<<end<<endl;
    //calculating all the windows in O(n^2)
    for(int i = 0; i<n; i++){
        end = n-1;
        while(end > i){
            //if only left part satifies our condition
            if(from_start[i][0]>= k && from_start[i][1]>= k && from_start[i][2]>= k){
                ans = min(ans, i+1);
                break;
            }
            //if only right part satifies our condition
            else if(from_end[end][0]>= k && from_end[end][1]>= k && from_end[end][2]>= k){
                ans = min(ans,n-end );
                break;
            }
            //sum of left and right part satifies our condition
            else if((from_start[i][0] + from_end[end][0])>= k && (from_start[i][1] + from_end[end][1])>= k && (from_start[i][2] + from_end[end][2])>= k){
                ans = min(ans, n+1 - (end- i));
                break;
            }
            else end--;
        }
    }
    return ans;
}


    //since the question is in parts and it's very hard for solving in that way in T.C < O(n^2) hence we need to invert the problem i.e finding the negative or the largest part which we can be removed so that the remaining part satisfisies our condition

    //since the inverse part or the part to be removed so that it satisfies our condition is consecutive we can use slidding window protocol to find the largest window to remove, we are using variable size sliding window to solve our problem. we keep on increasing our window size till the point our condition is satisfied, once the count of either a,b,c in the remaining part after removing our window becomes small we start shrinking our window from left we shrink the window till once again our condition get's satisfied
    //see video solution in the solutions of this problem 
    //https://www.youtube.com/watch?v=QzcxeJZByNM
    int sol3(string s, int k){
        int n = s.size();
        //counting the number of each a,b,c
        vector<int> counter(3,0);
        for(int i = 0; i<n; i++){
            counter[s[i] - 'a']++;
        }
        if(min(counter[0], min(counter[1], counter[2])) <k)return -1;
        int ans = n;
        //using the sliding window technique to remove the largest consecutive part such that the remaining part is satisfying our solution
        int left = 0; 
        for(int right = 0; right < n; right++){
            counter[s[right] - 'a']--;
            while(min(counter[0], min(counter[1], counter[2]))<k){
                //we shrink our window adding element back from left side
                counter[s[left]-'a']++;
                left++;
            }
            ans = min(ans, n - (right-left +1));

        }
        return ans; 
    }
public: 
    int takeCharacters(string s, int k) {
        // vector<int> count(3,0);
        // int n = s.size();
        // int sol =  solTakeCharacters(0,n-1,s,k , count, 0); 
        // if(sol == INT_MAX)return -1;
        // return sol;


        // return sol2(s, k);

        //solution using sliding window protocol by finding the opposite of what is asked in the question
        return sol3(s, k);
    }
}; 
