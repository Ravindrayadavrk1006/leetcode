class Solution {
private:

//brute force aproach for trying every box
    vector<int> solOperations(string boxes){
        int n = boxes.size();
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++){
            int val=0;
            for(int j =0; j<n; j++){
                if(boxes[j] == '1'){
                    val+=abs(j-i);
                }
            }
            ans[i] = val;
        }

        return ans;

    }
public:
    vector<int> minOperations(string boxes) {
        return solOperations(boxes);
    }
};
