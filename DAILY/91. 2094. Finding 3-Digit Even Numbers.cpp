class Solution {
private:
    void findAllPermutations(int pos, string& s, set<int>& ans){
        if(pos == 3){
            //if first element is not zero and it is even
            if(s[0] != '0' && ((s[2]-'0') % 2) == 0)ans.insert(stoi(s));
            return;
        }
        for(int i= pos; i<3; i++){
            swap(s[i], s[pos]);
            findAllPermutations(pos+1, s, ans);
            swap(s[i], s[pos]);
        }
    }

    //SOL 1 
    //brute force
    // generate all the subsequence of size 3
    void solFindEvenNumbers(int pos, string curr_num ,vector<int>& digits, int n, set<int>& ans ){
        if(curr_num.size() == 3){

            //for subsequence of size 3 generate all it's permutations
            findAllPermutations(0, curr_num, ans);
            return ;
        }
        if(curr_num.size()> 3 || pos == n)return;
        //take
        // curr_num+(digits[pos]+ '0');
        char c = digits[pos] + '0';
        solFindEvenNumbers(pos+1,curr_num+c, digits, n, ans);
        //not take 
        solFindEvenNumbers(pos+1, curr_num, digits, n, ans);
    }

    //SOL 2 [BEST SOLUTION]
    vector<int> checkAllAnswers(vector<int>& digits){
        vector<int> ans;
        int n = digits.size();
        //count each digit occurances
        vector<int> count(10, 0);
        for(int i =0; i<n; i++)count[digits[i]]++;
        //since the answer is of 3 digit the answer will be in range 100-999 and only even hence running with jump of i+=2 
        for(int i =100; i<1000; i+=2){
            map<int,int> mp;
            int curr_num = i;
            bool valid = true;
            //for each of three digits finding it's count
            for(int j=0; j<3; j++){
                int curr_digit = curr_num%10;
                mp[curr_digit]++;
                curr_num/=10;
                if(mp[curr_digit]> count[curr_digit]){
                    valid = false;
                    break;
                }
            }

            // we can check separtely if all the three digit of i their counts are present in the digit arr or not
            // in our case we are checking in above case only 

            /*
            for(auto el: mp){
                //if curr_digit count in our digit array is less than the current i which could be a answer, then it's not a valid answer
                if(count[el.first] < el.second){
                    valid = false;
                    break;
                }
            }
            */
            if(valid)ans.push_back(i);
        }
        return ans; 
    }

    //SOL 3 T.C -> O(N^3)
    /*
    //its time complexity will be O(n3)
        from the given array digits  form all the 3 digit number by running 3 for loop
    
    */
    vector<int> sol3_n3(vector<int>& digits){
        int n = digits.size();
        //forming 3 all three digit number from the array
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k =0; k<n; k++){
                    //if all three are same index then not possible
                    if(i == j || j== k || i==k)continue;
                    int num = (digits[i]*100) + (digits[j]*10) + (digits[k]);
                    // cout<<num<<endl;
                    //if it's even then insert the element in set, set because duplicate number could be formed since duplicate digit will be there in digits array
                    if(num >= 100 && ((num&1) == 0))st.insert(num);
                }
            }
        }
        //inserting all the elemnts from set to vector
        cout<<st.size()<<endl; 
        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans; 
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        //SOL 1  Brute Force
        /*
        string curr_num;
        set<int> ans;
        solFindEvenNumbers(0, curr_num, digits, digits.size(), ans);
        vector<int> ans_vec;
        for(auto el:ans)ans_vec.push_back(el);
        return ans_vec;

        */
        //SOL 3 
        return sol3_n3(digits);


        //SOL 2
        //NEW
        //trying all the possible answer if it is valid as per given inputs
        /*
            since the answer if of 3 digits and hence will lie in range of [100, 999]
            also since only even hence in for loop we can make jump of 100,102,104 and so on by i =100; i<1000; i+=2
        */
        // return checkAllAnswers(digits);
    }
};
