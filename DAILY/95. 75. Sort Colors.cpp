class Solution {
private:

    //this function place the pivot element at it's correct position and return this correct position of pivot
    int parition_algorithm(int low, int high, vector<int>& nums){
        int i = low;
        int j = high;
        //considering first element as pivot elements
        int pivot = nums[low];
        //we will swap the elements which are smaller than pivot to right, and smaller to left and finally swap pivot with j
        while(i < j){
            //first element greater than the pivot element
            //find first element which is greater than pivot and i should be in valid range
            //notice how in both of conditions of this while loop <= is being used for remembering 
            while( i<= high && nums[i]<= pivot)i++;
            //find first element smaller than pivot and j should be greater than low
            //also note how in both cases left part is greater
            while(j> low && nums[j]> pivot)j--;

            //swapping the elemnt
            if(i < j)swap(nums[i], nums[j]);
        }

        //all the swapping has been done and only pivot and swapping of j is remaining
        swap(nums[low], nums[j]);
        return j;
    }
    /*
        since asked to do inplace sorting hence QUICK SORT,
        1. how quick sort works we select a pivot element, which can be any element, here we are selecting first element
        2. we are finding elements larger than pivot , we are finding elements smaller than pivot and swapping them and finally
        3. we are swapping pivot and smaller elment last position.

        expansion point 2.
            we move from pivot towards right using a pointer called i, when we find a element GREATER than the pivot we, stop AND
           we find a element smaller than the pivot element starting from the last using a pointer called j
           when we find a smaller elemnt we swap  arr[i], arr[j]
           in this way we moved larger elment to right and smaller element to left
           

           and finallly we are swapping  arr[j] and pivot element

          we return the j index and then do the same from point 1 to 3 in left part and right part
    
    */
    //MAIN QUICK SORT
    void quick_sort(int low, int high, vector<int>& nums){
        if(low > high || low < 0 || high >= nums.size())return;
        //normal cases
        //find the correct index of pivot
        int pivot_correct_index = parition_algorithm(low, high, nums);
        //do same in left of pivot
        quick_sort(low, pivot_correct_index -1 , nums);
        //do same in right of pivot
        quick_sort(pivot_correct_index+1, high, nums);
    }

    //since we know what are the elements we can do many things 
    //let's implement basic O(N)
    /*
        Since there are very limited element i.e just 3 we are couting the elemnt and storing their count.
        once we have the count we can store the elements in the array
    
    */
    void order_of_n_implemenation(vector<int>& nums){
        int n = nums.size();
        //we know which are the elemnts hence count their occurances
        int count_0, count_1, count_2;
        count_0 = 0; 
        count_1 = 0; 
        count_2 = 0;
        for(auto el: nums){
            if(el == 0)count_0++;
            else if(el == 1)count_1++;
            else count_2++;
        }
        int j = 0;
        for(int i =0; i<count_0; i++){
            nums[j++] = 0; 
        }   
        for(int i =0; i<count_1; i++ ){
            nums[j++] = 1; 
        }
        for(int i =0; i<count_2; i++){
            nums[j++] = 2; 
        }  
    }
public:
    void sortColors(vector<int>& nums) {

        //sol1 -> working 
        // quick_sort(0, nums.size()-1, nums);


        //sol 2 -> working 
        order_of_n_implemenation(nums);
        
    }
};
