/*
    store all the elements in the priority q and once stored , starting reading and popping the k elements from the priority queue and as we pop element by element we push it's squareroot

*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        int n = gifts.size();
        //push all the elements in priority queue
        for(int el: gifts){
            pq.push(el);
        }
        //now pop k elements and push their squareroot
        for(int i = 0; i<k; i++){
            int top  = pq.top();
            pq.pop();
            pq.push(int(sqrt(top)));
        }
        long long ans = 0;
        //now we will read all the elements and add them to ans variable
        while(!pq.empty()){
            //type cast the element when storing
            ans+=(long long)pq.top();
            pq.pop();
        }
        return ans;
    }
};
