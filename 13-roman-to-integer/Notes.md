/*************since the conditions are less without using the concept of hashmap we can do using else if***************/
/******** hashing value and doing substraction takes heigher time since we are doing calculation of extra substraction and although visiting the node is constant but 
takes extra time for creating a iterator *********/
/**** third trick of storing the subtracted values too in hash map fails if we store the keys in form of int and hence need to store the keys of subtracted constant in
form of key typeof string *****/
class Solution {
public:
    int romanToInt(string s) {
        int n=s.length(); // length of string
        int res=0; //to store ans 
        int i;
        for(i=0;i<n;i++){
            if(s[i]=='I'){
                if(i<n && s[i+1]=='V'){ 
                    res+=4;
                    i++;
                }
                else if(i<n && s[i+1]=='X'){
                    res+=9;
                    i++;
                }
                else
                    res++;
            }
            else if(s[i]=='X'){
                if(i<n && s[i+1]=='L'){
                    res+=40;
                    i++;
                }
                else if(i<n && s[i+1]=='C'){
                    res+=90;
                    i++;
                }
                else
                    res+=10;
            }
            else if(s[i]=='C'){
                if(i<n && s[i+1]=='D'){
                    res+=400;
                    i++;
                }
                else if (i<n && s[i+1]=='M'){
                    res+=900;
                    i++;
                }
                else{
                    res+=100;
                }
            }
            else if (s[i]=='V')
                res+=5;
            else if(s[i]=='L')
                res+=50;
            else if(s[i]=='D')
                res+=500;
            else if(s[i]=='M')
                res+=1000;
        }
        
        return res;
    }
};
