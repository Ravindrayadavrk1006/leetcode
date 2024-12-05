class Solution {
private:

    //NON WORKING SOLUTION 
    //here we tried to make changes in both the start and target string by tring to push L as left as left as possible and right as right as possible 
    string helper(string& start){
        char prev = 'E';
        int spaces = 0;
        int n = start.size();
        int i = n-1;
        while(i>=0 ){
            cout<<i<<start[i]<<" spaces "<<spaces<<endl;
            if(start[i] == 'R' && prev == 'E'){
                swap(start[i],start[i+spaces]);
                prev = 'R';
                cout<<"going in start[i] == 'R' && prev == 'E' ---> "<<start<<endl;
            }
            else if(start[i] == 'L' && prev == 'E'){
                cout<<"start[i] == 'L' && prev == 'E'"<<endl;
                prev = 'L';
                spaces = 0;
            }
            else if(start[i] == 'R' && prev == 'R'){
                swap(start[i], start[i+spaces]);
                cout<<"start[i] == 'R'----->"<<start<<endl;
                prev = 'R';
            }
            else if(start[i] == 'R' && prev == 'L'){
                swap(start[i+1], start[i+1+spaces]);
                cout<<"start[i] == 'R'----->"<<start<<endl;
                prev = 'R';
            }
            else if(start[i]== 'L' && prev =='R'){
                spaces = 0;
                prev = 'L';
            }
            else if(start[i]== 'L' && prev =='L'){
                swap(start[i+1],start[i+1+spaces]);
                cout<<"start[i]== 'L'---> "<<start<<endl;
                prev = 'L';
                spaces = 0;
            }
            else{
                spaces++;
            }
            i--;
        }
        if(prev == 'L' && start[0] == '_')swap(start[spaces],start[0]);
        return start;
    }
    bool solCanChange(string& start, string& target){
        
        string a =  helper(start);
        string b = helper(target);
        cout<<a<<"  "<<b<<endl;
        return a==b;
    }

    bool sol2(string& start, string& target){
        int n = start.size();
        int i = n-1;
        int j = n-1;
        int spaces = 0;
        while(i>=0 && j>=0){
            cout<<j<<" "<<i<<" "<<spaces<<endl;
            if(start[i] == target[j]){
                swap(start[i], start[i+spaces]);
                cout<<start<<endl;
                j--;
                i = j;
                if(target[j] == 'L')spaces = 0;
                continue;
            }
            else if(target[j] == '_' && start[i] == 'R')return false; 
            else if(target[j] == 'R' && start[i] == 'L')return false;
            else if(start[i] == '_')spaces++;
            i--;
        }
        if(j<0)return true;
        return false;
    }


//---------------------- WORKING SOLUTION----------- these are from the editorial section on the problem

    /*
        from editorial solution 2 using queue
    */
    bool usingQueue(string& start, string& target){
        queue<pair<char,int>> startQueue, targetQueue;
        int n = start.size();

        //for each character in the start, target  if the current characater is 'L' or 'R' we push them in their respective queue
        for(int i = 0; i<n; i++){
            if(start[i] != '_'){
                startQueue.push({start[i], i});
            }
            if(target[i] != '_'){
                targetQueue.push({target[i], i});
            }
        }
        if(startQueue.size() != targetQueue.size())return false;

        while(!startQueue.empty()){
            auto st = startQueue.front();
            startQueue.pop();
            auto tar = targetQueue.front();
            targetQueue.pop();

            //checking if the current char of both are not same then we return false
            if(st.first != tar.first )return false;
            //if current char is L, then we check if the position of current left in first is at greater position then the L's position in the target
            if(st.first == 'L' && st.second < tar.second)return false;
            //if current position is R then the position of current R should be at equal position or to the left of the position of R in the target
            if(st.first == 'R' && st.second > tar.second)return false;
        }
        return true;
    }



    //editorial 2 working solution
    bool twoPointers(string& start, string& target){
        int n = start.size();
        int i = 0, j = 0;
        while(i< n || j <n){
            while(i< n && start[i] == '_')i++;
            while(j<n && target[j] == '_')j++;
            //we have reached the character or end

            //if one is exhausted then both should be exhausted because if not so then the answer if false
            if(i == n){
                return j==n;
            }
            if(j == n){
                return i == n;
            }

            //
            if(start[i] != target[j])return false;

            //coming here it means both the character are equal
            else if(start[i] == 'L' && i <j)return false;
            else if(start[i] == 'R' && i> j )return false;

            i++;
            j++;
        }
        return true;
    }

public:
    bool canChange(string start, string target) {
        // return solCanChange(start, target);

        //CALLING WORKING 1st SOLUTION
        // return usingQueue(start, target);

        //CALLING WORKING 2nd SOLUTION
        return twoPointers(start, target);
    }
};
