class Solution {
private:
    /*FROM EDITORIAL*/
    /*
        we are sing recursion to generate all the number starting from  a numbr we are giving recusion the starting point and asking him to generate all number in lexicogreaphicla order
        ,it's like using recursion to form a tree
    */
    void recursive_lexical_generator(int num, int limit , vector<int>& result){
        //push the current nubmer in the answer
        if(num<=limit)result.push_back(num);
        //now try to form number num*10+i  where  0<=i<=9 and if number is in range then call the function recursively
        for(int i=0; i<=9; i++){
            int next_num = num*10 + i;
            if(next_num<=limit){
                recursive_lexical_generator(next_num, limit, result);
            }
            else{
                break;
            }

        }
    }
    vector<int> sol_using_bfs(int n){
        vector<int> result;
        for(int i=1;i<=9; i++){
            recursive_lexical_generator(i, n, result);
        }
        return result;
    }
public:
    vector<int> lexicalOrder(int n) {
        return sol_using_bfs(n);
    }
};
