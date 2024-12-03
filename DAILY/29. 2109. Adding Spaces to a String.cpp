/*
    ***** IMPORTANT LEARNING
    [TOO MUCH TIME !!!]ans = ans+ ' ' + word[i]   this takes far more time 
    [LESS TIME !!] 
        ans+=' '; 
        ans+=word[i];

*/
/*
    SOL 3 ->
    working solution using trie 

    traversing the given string s using index i 
    we try to insert all the characters in a trie structure , this structure will have only have one word since our question has just one word
    inserting -> 
    we try inserting every character in the trie block ,for every index i we try to binary search this index in the spaces array if this index exist then we set that this is spacAsWell
    i.e make isSpaceAsWell = true;

    finding ->
        finally once inserted then we traverse the trie and whenever we see that the current trieNode has isSpaceAsWell set as true we add a space then the curren character
*/

//creating trieNode structure
struct TrieNode{
    TrieNode* link[26];
    bool isSpaceAsWell = false; 
    void insert(char c, TrieNode * t){
        link[c-'a'] = t;
    }
    bool containsChar(char c){
        return link[c-'a'] != NULL;
    }
    TrieNode* getCharPointer(char c){
        return link[c-'a'];
    }
    void addSpace(){
        isSpaceAsWell = true;
    }
    bool hasSpace(){
        return isSpaceAsWell;
    }
};

//trie class for doing procecssing on the word
//inserting the word 
//forming the final answer
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        //binary search helper for finding if current i exist in the spaces , being used in the insert function below
        int binarySearch(int find, vector<int>& spaces){
            int end = spaces.size()-1;
            int start = 0;
            while(start<= end){
                int mid = (start + end)/2;
                if(find == spaces[mid])return mid;
                if(find> spaces[mid])start =  mid+1;
                else end = mid -1;
            }
            return -1;
        }

        //insert the word in trie structure
        void insert(string& word, vector<int>& spaces){
            int n = word.size();
            TrieNode* node = root;
            for(int i = 0; i< n; i++){
                node->insert(tolower(word[i]), new TrieNode);
                int isSpace = binarySearch(i,spaces);
                if(isSpace != -1)node->addSpace();
                node = node->getCharPointer(tolower(word[i]));
            }
        }

        //forming the final answer it's just finding the word in trie 
        string findFinalWord(string& word){
            int n = word.size();
            string ans = "";
            TrieNode* node = root;
            for(int i =0; i<n; i++){
                if(node->hasSpace()){
                    ans+= ' ';
                    ans+=word[i];
                }
                else ans+= word[i];
                node = node->getCharPointer(tolower(word[i]));
            }
            return ans;
        }
};
class Solution {
private:

    //SOL 1
    //T.C ->  s.size()* spaces.size()
    /*
        since the space array is sorted so for element in the spaces array we are storing the s string character in the ans string and at the ith space element we insert space + that chracter
    
    */
    string solAddSpaces(string& s, vector<int>& spaces){
        string ans = "";
        int n = s.size();
        int spacesSize = spaces.size();
        int i = 0;
        int j = 0;
        //for every element in spaces array
        for(int i = 0; i<spacesSize; i++){
            //insert the characters till that space index element in the ans string
            while(j< spaces[i]){
                ans+=s[j++];
            }
            //here j will be equal to i
            //at spaces[i] insert spaces+ that characater
            ans+=' ';
            ans+= s[j++];
        }
        //when all the spaces are inserted insert the remaining part of s in the final answer
        if(j<n){
            ans+=s.substr(j,n);
        }
        return ans;
    }



    //SOL 2
    /*
        we are inserting the characers from s to ans string and at index i, if the the current index is present in the space array we insert space + that character and incremnt the space index j 
    */
    string sol2(string& s , vector<int>& spaces){
        int n = s.size();
        int j = 0;
        int spacesSize = spaces.size();
        string  ans = "";
        //for every character in the string s
        for(int i= 0; i<n; i++){
            //if current s string character index is same as current space index , we store space + that chracter and increment the space pointer so that we check the next position of the space next time
            if(j< spacesSize && i == spaces[j]){
                ans+=' ';
                ans+=s[i];
                j++;
            }
            else ans+=s[i];
        }
        return ans;
    }
public:
    string addSpaces(string s, vector<int>& spaces) {

        //SOL 1

        //GIVES BEST TIME
        return solAddSpaces(s, spaces);

        // SOL 2
        //GIVES SECOND BEST TIME
        // return sol2(s, spaces);


        //SOL 3

        //DOESN'T GIVE ANY BETTER TIME

        // Trie* obj = new Trie();
        // obj->insert(s, spaces);
        // return obj->findFinalWord(s);
    }
};
