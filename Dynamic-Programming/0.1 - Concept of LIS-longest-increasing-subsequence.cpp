

PROBLEM-> find the length of largest increasing subsequence
    /*
        LIS is very important concept for finding the LONGEST SUBSEQUENCE
        the condition of IF inside the nested O(n^2) for loop will say what  we are finding, hence whenver we are asked about longest subsequence always try to go for LIS

        eg . if we want to find the longest increasing subsequence then we need to put in the IF condition if(arr[j]< arr[i]) , if decreasing then arr[j]> arr[i] and son.



  
        also 
    */
    vector<string> sol_using_LIS(vector<string>& words, vector<int>& groups){
        int n = words.size();
        //since we need to parent the longest subsequence hence using the parent vector for storing the parent of each elemnet
        vector<int> lis(n, 1);
        int longest_increasing_subsequence_length = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<i; j++){

                //THIS IS THE MAIN CONDITION 
                //THIS WILL DECIDE WHAT KIND OF SUBSEQUENCE WE WANT
                //IF WE NEEDED longest strictly increasing then  if(arr[i] > arr[i])
                //if we needed decreasing then (arr[i]<arr[j] ) and so on
                // this condition changes for longest subsequence
                if(groups[j] != groups[i] && words[i].size() == words[j].size() && valid_hamming_distance(i, j, words)){            

                    //basic condition of LIS 
                    if(lis[j] + 1 > lis[i]){
                        //update the lis[i] value
                        lis[i] = lis[j] + 1;
                        //this is normal part of LIS, we are storing the answer in the a variable
                        if(lis[i]> longest_increasing_subsequence_length){
                            longest_increasing_subsequence_length = lis[i];
                        }
                    }
                }
            }
        }

       
        return longest_increasing_subsequence_length;
    }

//VERY SIMPLE LIS
//core longest increasing subsequence

int lis(vector<int>& arr) {
        int n = arr.size();
        //create a lis vector which will store the longest subsequence for that element till now
        //initially all element will be 1 subsequence hence 1
        vector<int> lis_vec(n,1);
        
        //since a element is a subsequence
        int longest_subsequence = 1;
        for(int i =0 ; i<n; i++){
            for(int j=0; j<i; j++){
                //[**IMP] condition which decide what type of LONGEST SUBSEQUENCE 
                if(arr[i]> arr[j]){
                    if(lis_vec[j] +1 > lis_vec[i]){
                        lis_vec[i] = lis_vec[j] + 1;
                        longest_subsequence = max(longest_subsequence, lis_vec[i]);
                    }
                }
            }
        }
        return longest_subsequence;
    }
