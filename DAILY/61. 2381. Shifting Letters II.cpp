class Solution {
private:
    // giving TLE
    /*
        direct approach 
    */
    string bruteForce(string s, vector<vector<int>>& shifts){
        int n = shifts.size();
        for(auto shift: shifts){
            int moving = 1;
            //for moving backwards
            if(shift[2] == 0)moving = -1;
            for(int i = shift[0]; i<= shift[1]; i++){
                //[**IMP]26 is addded because we are doing negative SHIFTS ALSO AND THAT MAY GO OUT OF BOUND
                s[i] = (s[i] - 'a' + moving + 26)%26 + 'a';
            }
        }
        return s;
    }

    /*
        giving TLE
        adding all the shifts for each elements and then finally doing the shift
    */
    string betterShiftingLetters(string s, vector<vector<int>>& shifts){
        int n = s.size();
        vector<int> moving(n, 0);
        for(auto shift: shifts){
            int move = 1;
            if(shift[2] == 0)move =-1;
            for(int i = shift[0]; i <= shift[1]; i++){
                moving[i]+=move;
            }
        }
        //once all the movement are done
        for(int i =0; i<n; i++){
            //if no movement to be done then move
            if(moving[i] != 0){
                s[i] = (s[i] - 'a' + moving[i] + 26)%26 + 'a';
            }
        }

        return s;
    }

    //better approach -->

    //see editorial this is editorial help
    //instead of trying to keep a track of all the element movement we will keep track of range of shifts
    /*
        eg if shift[2] == 1 then we say moving[shift[start]]+=1 and also  we say movings[shift[end] +1]-=1 this is done we are saying from  start to end we increment +1 and the other after it will be smaller than the current
    */
    string solBoundaries(string s, vector<vector<int>>& shifts){
        int n = s.size();
        vector<int> moving(n, 0);
        for(auto shift: shifts){
            if(shift[2] == 1){
                moving[shift[0]]++;
                if(shift[1]+1 < n)moving[shift[1]+1]--;
            }
            else{
                moving[shift[0]]--;
                if(shift[1]+1 < n)moving[shift[1]+1]++;
            }
        }

        int curr_movement = 0;
        for(int i =0; i<n; i++){
            curr_movement+=moving[i];
            curr_movement%=26;
            if(curr_movement < 0)curr_movement+=26;
            s[i] = 'a' + (s[i] - 'a' + curr_movement)%26;
        }
        return s;
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // return bruteForce(s, shifts);


        //but the time complexity remains similar to above;
        // return betterShiftingLetters(s, shifts);
        
        return solBoundaries(s, shifts);
    }
};
