

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
