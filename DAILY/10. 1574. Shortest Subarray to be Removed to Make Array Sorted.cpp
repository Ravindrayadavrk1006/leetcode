class Solution {
private:
    //non working solution some issue in the code learn from the next solution
    int solFindLengthOfShortestSubarray(vector<int>arr){
        int n = arr.size();
        if(arr.size() == 1 )return 0;
        vector<int> prefix, suffix_arr;
        stack<int> suffix;
        for(int i=0; i<n-1; i++){
            if(arr[i]<= arr[i+1]){
                prefix.push_back(arr[i]);
            }
            else {
                prefix.push_back(arr[i]);
                break;
            }
        }
        //if all the elements are inserted in prefix then the array is already sorted return from here
        if(prefix.size() == n-1 && prefix[prefix.size()-1]<= arr[n-1]){
            return 0;
            // prefix.push_back(arr[n]);
        }
        if(prefix.size() == 1)return n-1;
        //normal cases
        int till = prefix.size();
        int pos = n-1;
        if(prefix.size() != 1){
             while(pos>= till){
                if(arr[pos]>= arr[pos-1]){
                    suffix.push(arr[pos]);
                    pos--;
                }
                else {
                    suffix.push(arr[pos]);
                    break;
                }
            }
        }
       
        cout<<"prefix"<<endl;
        for(int el: prefix)cout<<el<<" ";
        cout<<endl;
        cout<<"suffix"<<endl;
        while(!suffix.empty()){
            int top = suffix.top();
            suffix.pop();
            suffix_arr.push_back(top);
        }
        for(int el: suffix_arr)cout<<el<<" ";
        cout<<endl;
        cout<<"sized"<<prefix.size()<<" "<<suffix_arr.size()<<endl;
        //initially all the elements which are not inserted are the answer
        int ans = arr.size() -  (prefix.size() + suffix_arr.size());
        cout<<"ans "<<ans<<endl;
        int i = 0;
        int j = 0;
        int p = prefix.size();
        int q = suffix_arr.size();
        int min_val = INT_MAX;
        while(i < p && j< q){
            if(prefix[i]<= suffix_arr[j]){
                min_val = min(min_val, (p-i) + j);
                i++;
            }
            else{ 
                min_val = min(min_val, (p-i) + j);
                j++;
            }
            // cout<<"i"<<i<<" ";
        }
        if(min_val >= p || min_val >= q)min_val = min(p,q);
        // return ans;
        return ans + min_val;
    }


    //working solution
    /*
        approach -> from the given array we are storing in prefix till the point the array is sorted from left and in suffix we are keeping those elemnt which are sorted from end,

        this we are handling in the same array using i and j pointers
        i is the position  till whhic point array is sorted from left
        j is the position till which point array is sortef from right,
        then we are trying to minimize this answer using two pointer approach  explained in the code
    
    */
    int sol2(vector<int>& arr){
        int n = arr.size();
        //in the same array arr we are moving to the mount till which pos left part from start is sorted 
        int i = 0;
        while(i+1 < n && arr[i] <= arr[i+1])i++;
        //if i is reached to n-1 then it means the entire array is sorted and we don't need to remove any element
        if(i == n-1)return 0;
        //moving from the last to the position where array is sorted from the last 
        int j = n-1;
        while(j>0 && arr[j]>= arr[j-1])j--;

        //now the the i and j will be respectively at those position where array from start is sorted and array from end is sorted


        //now we have some answer
        /*
            1.if we remove all element from i to n the array is sorted
            2.if we remove from 0th index to jth index the left array is sorted
            basically removing all element except sorted in from start can be one answer and other answer can be sorted just the sorted from end
        */
        //let's take min of 1 and 2 to be our answer because either we do the remaining will be sorted
        int ans = min(n-(i+1), j);

        //now what we will do is efficiently try to check if we can minimize our answer by using two pointer approach
        int left_till = i;
        i = 0;

        //here we are trying to minize the solution
        while(i <= left_till && j < n){
            //here we are saying if left element is smaller than jth element it means one way in which we were removing j element from it we keep these left element till i
            //very cool concept of minimization 
            if(arr[i] <= arr[j]){
                //here we are saying if the left sorted element is smaller then we can avoid removing these element in otherwise case we would have to remove till j
                ans = min(ans, j-(i+1));
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // return solFindLengthOfShortestSubarray(arr);

        return sol2(arr);
    }
};
