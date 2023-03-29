we put a traversor on the stream and on the stack
when stream travesor == current stack traversor element we insert "Push" in the output array
when stream traversor != current stack traversor element we insert "Push" and "Pop" in the array
the logic is that since we don't require the current stream travesor element hence we Push it and Pop whereas we require when stream == stack element hence we only "Push"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stack;
        int s = 1;
        int i=0;
        int tar_length = target.size();
        int stack_pos = 0;
        while(i<tar_length && s<=n)
        {
            if(s != target[i])
            {
                stack.push_back("Push");
                stack.push_back("Pop");
                s++;
            }
            if(s == target[i])
            {
                stack.push_back("Push");
                s++;
                i++;
            }
        }
        return stack;
    }
};
