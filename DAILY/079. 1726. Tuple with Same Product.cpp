class Solution {
private:

    //BELOW TWO SOLUTION T.C O(n^2)
    /*
        in this we are storing all the possible multiplication of two numbers in map as key and the numbers pairs as value in vector

        so we will have all the possible multiply of two numbers and in value we will have all the pairs index which multiply to form that sum.


        now. if there is just one pair, which form that multiplication then we are not doing anything because according to question we need two pairs.

        for other we are checking if each number of one pair is not present in other pair and and if not present that times 8 will be added in the ans
    
    */
    int sol1(vector<int>& nums){
        int n = nums.size();

        //storing multiplication of two nubmers as key and their indices as value, vector
        unordered_map<int, vector<pair<int,int>>> mp;
        for(int i =0; i<n; i++){
            for(int j= i+1; j<n; j++){
                mp[nums[i]* nums[j]].push_back({i,j});
            }
        }

        //below commmented code, print the combinations


        // for(const auto& el: mp){
        //     cout<<el.first<<endl;
        //     for(const auto& val: mp[el.first]){
        //         cout<<val.first<<" "<<val.second<<"---";
        //     }
        //     cout<<endl;
        // }
        // return 1;

                                                                                                      
        int ans = 0;
        for(const auto& el: mp){
            if(el.second.size() == 1)continue;
            // vector<pair<int,int>>& el.second = el.second;
            int val_n = el.second.size();
            for(int i = 0; i<val_n; i++){
                for(int j =i+1; j < val_n; j++){
                    //checking if one pair of number is not present in second pair, because we need 4 unique numbers
                    if(el.second[j].first != el.second[i].first && el.second[j].first != el.second[i].second && el.second[j].second != el.second[i].first && el.second[j].second != el.second[i].first)ans+=8;
                }
            }
        }
        return ans;
    }

    /*
        in above solution we were doing useless calculation of checking one pair element are present in other pair or not it is not required because all the numbers are distinct now let's sa a*b = c*d    , let's say b =c i.e is same number i.e not equal but same numbers,  for the multiplication to be equal a should be equal to d , which is not possible , 
        similarly if a was same as c, then for multiplication to be equal b should be equal to d and so on which is not possible according to question since all the nubmers are unique
    
    */
    int sol2(vector<int>& nums){
        int n = nums.size();
        unordered_map<int, vector<pair<int,int>>> mp;
        for(int i =0; i<n; i++){
            for(int j= i+1; j<n; j++){
                mp[nums[i]* nums[j]].push_back({i,j});
            }
        }
        int ans = 0;
        for(auto el: mp){
            if(el.second.size() == 1)continue;
            int n = el.second.size()-1;
            int temp = (n*(n+1));
            //divide by 2
            temp = temp>>1;
            ans+=temp;
        }
        return ans*8;
    }

    
public:
    int tupleSameProduct(vector<int>& nums) {
        // return sol1(nums);

        return sol2(nums);
    }
};
