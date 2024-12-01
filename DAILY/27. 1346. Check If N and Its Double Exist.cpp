class Solution {
private:

    //T.C O(n^2)
    bool bruteForce(vector<int>& arr){
        int n = arr.size();
        for(int i = 0; i<n; i++){
            //the starting for finding each element twice is being done in the entire array because the elemnt could lie in left of i also 
            for(int j=0; j<n; j++){
                if(i != j && arr[i]*2 == arr[j])return true;
            }
        }
        return false;
    }
    //using binary search
    //T.C (nlogn)
    /*
         here we have sorted all the elements 
         and for each element in arr we are doing binary search and trying to find if there exist a  number which is double of the current number,
         one important thing we are keeping the search space from index = 0 to index = n-1 because here negative nubmers are also given and twice of negative number is smaller than current number eg . -10   it's twice is 2*-10 = -20 and therefore instead of start being from i+1 we are keeping it from start = 0 for each element binary search
    
    */
    bool binarySearchApproach(vector<int>& arr){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i =0; i<n; i++){
            //the start will be 0 since in case 2*negative value e.g 2* -10 = -20 which is less than current value so might have to go to the left of current i to search it
            int start = 0; 
            int end = n-1;
            int toFind = 2*arr[i];
            while(start<= end){
                int mid = (start + end)/2;
                if(arr[mid] == toFind)return true;
                else if(arr[mid]<toFind)start = mid+1;
                else end = mid-1;
            }
        }
        return false;
    }

    //sol3 using hashmap
    //for each element trying to find if it's double exist or it's half exist , if either exist return true , if not exist then we are storing the number and checking for other number
    bool usingHashMap(vector<int>& arr){
        int n = arr.size();
        unordered_map<int, bool> mp;
        for(int i = 0; i<n; i++){
            if(mp.find(2*arr[i]) != mp.end())return true;

            //here seeing if the half of the current number already exist or not
            //here we are checking if the arr[i] is even before checking if it's half exist or not because if we do it directly half of odd will be one less than half which is not right
            if(arr[i]%2 == 0 && mp.find(arr[i]/2) != mp.end())return  true;
            //storing the element in the hashmap
            mp[arr[i]] = true;
        }
        return false;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        // return bruteForce(arr);

        // return binarySearchApproach(arr);


        return usingHashMap(arr);
    }
};
