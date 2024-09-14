
/*

    main function calls helper helper calls travesal_row_order

    idea :
        since have to store in vertical order i.e according to colunmn hence we need to have info about the current node(x,y) 
        and then for each y or column we store the elements in a vector . since we will need n vector for n colums so will hash-map
        ordered hash map where key will be columnno and value will be vector.

        other problem is to sort all the elements which are coming from same row in the same column.
        for this problem will have another map with column as key and whose value will store which row element was the last one to be inserted in that colmn vector
        **important thing we will do row-order travesal in this way . similar row element will be inserted together in the column vector and hence easy for us to solve.


    approach:
        mp : is a map which will will have column as keys and vector for storing all the elemnts that come in that column
        row_and_pos_info_map: will have column as keys and will  value  will be a pair which have following two info: last row whose value was inserted and at what position
        we will update row_and_pos_info_map[column] value when the current row is different then the last row whose value was inserted in this particular column

        our mp map will contain all the column with values then finally we iterate over and save all the values in answer array.
*/
class Solution {
private:
    /*
        //it is simple level order travesal with additional code written to suit our case it
        instead of saving in a temporary vector directly and then pushing in ans once current row is traversed. we are doing our required stuff 
    */
    void travesal_row_order(TreeNode* root, map<int,vector<int>>& mp, map<int,pair<int,int>> &row_and_pos_info_map){
        //q is used for doing level order travesal
        queue<TreeNode*> q;
        //this pos_queue store elements position in exactly same way as q
        //i.e same way we store element in q , at the same time we store it's x,y position in pos_queue and pop frmo pos_queue when the respective element is popped from q
        queue<pair<int,int>> pos_queue;
        if(root == NULL)return;
        //x,y
        //first is row , second is column in our cases
        pair<int,int> pos(0,0);
        q.push(root);
        pos_queue.push(pos);
        //doing same what we do in BFS 
        while(!q.empty()){
            int q_curr_size = q.size();
            //create vector for each row
            for(int i = 0 ; i<q_curr_size; i++ ){
                TreeNode* front = q.front();
                pos = pos_queue.front();
                //here we used to push front el in the row vector instead we are doing the below things of if else
                //PERFORMing our action HERE
                //here checking if that column already exist in mp if not we are creating a temp array inserting the front element val
                //and at the same time saving what is the row and , and since it is first time so index of that element will be 0 in mp[column]
                if(mp.find(pos.second) == mp.end()){
                    vector<int> temp;
                    mp[pos.second] = temp;
                    mp[pos.second].push_back(front->val);
                    //create a entry in the second map as well
                    row_and_pos_info_map[pos.second] = pair(pos.first,0);

                }
                //if the map[column] already exist then we do this
                else{
                    /*
                        here we are checking if the current element row is differernt from the row of last element inserted in that mp[column]
                        if it is different, sorting mp[column] from the position where current row elements are present in the mp[column]
                    */
                    if(pos.first != row_and_pos_info_map[pos.second].first){
                        sort(mp[pos.second].begin()+row_and_pos_info_map[pos.second].second, mp[pos.second].end());
                        //since now we have a different row for the column we update the row and since the coming element will be stored at mp[column].size() hence that will be position
                        row_and_pos_info_map[pos.second] = pair(pos.first, mp[pos.second].size());
                    }
                    //push in the ith column
                    mp[pos.second].push_back(front->val);
                }
                //remove the current element from queue
                q.pop();
                //remove current element position as well from pos_queue
                pos_queue.pop();
                //simple thing of row order traversal of storing the current elemnt left and right in the queue
                //at the same time we are storing the current elemnt left right position as well in the pos_queue
                if(front->left != NULL){
                    q.push(front->left);
                    pos_queue.push(pair(pos.first+1,pos.second-1));
                }
                if(front->right != NULL){
                    q.push(front->right);
                    pos_queue.push(pair(pos.first+1,pos.second+1));
                }
                
            }
        }


        /*
            this part is added because of how storing is happening in above case at following code
                
                    // if(pos.first != row_and_pos_info_map[pos.second].first){
                    //     sort(mp[pos.second].begin()+row_and_pos_info_map[pos.second].second, mp[pos.second].end());
                    //     row_and_pos_info_map[pos.second] = pair(pos.first, mp[pos.second].size());
                    // }
                    // //push in the ith column
                    // mp[pos.second].push_back(front->val);

            what is happening in above case is that it keep on storing the element for similar row and when the row changes for the column it tries to sort
            issue comes when the last inserted elements belong to the same row and hence those last elements won't be sorted
            so in below code we are checking till what point the elemtns are sorted if sorted till last leave it if not then sort the remaining elements
            till what point the elements are sorted will be stored in the map row_and_pos_info_map in second value of the pair
            
        */
        for(auto &pair:row_and_pos_info_map){
            cout<<"for index "<<pair.first<<"value of pair.second.second "<<pair.second.second<<"size of mp[pair.first]"<<mp[pair.first].size()<<endl;
            if(pair.second.second  != mp[pair.first].size()){
                sort(mp[pair.first].begin()+pair.second.second,mp[pair.first].end());
            }
        }


    }


    vector<vector<int>> helper(TreeNode* root){
        //ans vector
        vector<vector<int>> ans;
        /*
            mp store the values for each column
            eg mp[0] = (1,2,3) .ie column 0 has values 1,2,3 in that column 
            mp[1] = (10,45,24)
        */
        map<int,vector<int>> mp;
        //row_and_pos_info_map store the info about which was last row whose value was inserted in that column from what position that element is present in mp[column]
        //from what position that value is since we only update the second pair value when a element from different row comes in that column done in order to sort all the elemnts of that row in one go and without error
        map<int, pair<int,int>> row_and_pos_info_map; 
        //traving row order or BFS 

        //main solution function
        travesal_row_order(root, mp,row_and_pos_info_map);

        //copying all the rows in the ans 
        //since the map was sorted so the ans will get it in same order
        for(auto &pair:mp){
            if(pair.second.size())ans.push_back(pair.second);
        }
        return ans;
    }




public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //calling the helper function
        return helper(root);
    }
};
