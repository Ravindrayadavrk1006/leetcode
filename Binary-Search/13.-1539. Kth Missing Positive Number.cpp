class Solution {
private:
    int brute_force(vector<int>& arr, int k){
        /*
            let's suppose we have to find the 5th missing number
            we will start with ans = k = 5 -> here we are assuming that if there was no number given in the array that need to be skipped in the missing list , this 5 would be answer
            and the array is [2,3,4,7,11]
            we will start traversing the array and when we see a number which is less than k it means it is not part of missing and hence our answer will shift one position forward hence k++,
            we will do this till k is smaller than arr[i] since if arr[i] becmes greater than k it means it lies ahead not behind and hence it won't shift the answer
        */
        int n = arr.size();
        for(int i = 0 ; i<n; i++){
            if(arr[i]<=k)k++;
            else break;
        }
        return k;
    }

    //binary search approach

    int bs_approach(vector<int>& arr, int k){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        /*
            eg. given array [2,3,4,7,11] and k = 5
            if there was no missing number then all number would be [1,2,3,4,5]
            now if we compare at 1 place is 2 in the given array and 2-1 = 1 number is missing
            at 3 place it shoudl be 2 and hence 3-2 = 1 missing till now
            at 4  3 should be hence missing 4-3 = 1
            at 7 5 should be there hence missing 7-4 = 3
            at 11 we should have 5 and hence missing 11-5 = 6
            so we can figure out how many numbers are missing and we have to find the 5th missing number
            so our answer should lie bettween 7 and 11 where missing are 3 and 6 respctively.
            we can find these 7 and 11 using binary search since we have clear logic in which side to move.


            let's suppose we got 7 and 11 now we know the missing at 7 is 3 but we need missing 5 so remaining missing is 5-3 = 2 and if we add 7+2 we have our answer , so let's do it
        */
        while(low<=high){
            int mid = (low + high)/2;
            //mid+1 used since 0 based indexing 
            int current_missing =  arr[mid]- (mid+1);
            if(current_missing<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        //taking care of base cases
        if(n==1){
            if(arr[0]>k)return k;
            else return k+1;
        }
        //if the high comes to be less than it means missing number is smaller than the first number in the given array and hence return k itself since no number in between will be there which is present
        if(high < 0)return k;
        //if low comes out to be greater than n-1 it means the number is right to all the number given it means , the answer would be k+n since n number are present already
        if(low > n-1)return k+ n;
        //we will have two numbers in the given array where our answer would lie
        /*
        high would be at left side and low would be in the right side 
        */
        //start_pos is left side end of range where our number will lie
        int start_pos = arr[high];
        //let's find number of missing number till start_pos
        int difference_till_now = start_pos - (high + 1);
        //how many numbers are remaining which need to be missed ===> k- difference_till_now
        cout<<"start_pos"<<start_pos<<" difference_till_now "<<difference_till_now<<endl;
        return start_pos + (k- difference_till_now );
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        //calling sol 1
        // return brute_force(arr,k);

        //calling sol 2
        return bs_approach(arr, k);
    }
}; 
