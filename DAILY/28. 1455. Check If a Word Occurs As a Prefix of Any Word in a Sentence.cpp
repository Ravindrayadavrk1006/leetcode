class Solution {
private:

    /*
        BRUTE FORCE APPROACH ->
        we are breaking the sentence using the space delimiter here using the istringstream and getline to do it,
        we store the output in a wordVec then we starting traversing this word vector and check if the searchWord is a prefix in any word by taking prefix of searchWord size from each word, once we find the anwer we return the answer
    
    */
    int solIsPrefixOfWord(string sentence, string searchWord){
        istringstream sent(sentence);
        vector<string> wordsVec;
        string word;
        //storing each word in a vector called wordVec
        while(getline(sent, word, ' ')){
            wordsVec.push_back(word);
        }
        int wordsCount = wordsVec.size();
        int toFindSize = searchWord.size();
        //traversing the sentence word by word and checking if given searchWord is a prefix in any word , as soon as we find the solution we return the answer
        for(int i = 0; i< wordsCount; i++){
            if(wordsVec[i].substr(0, toFindSize) == searchWord)return i+1; 
        }
        return -1;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        return solIsPrefixOfWord(sentence, searchWord);
    }
};
