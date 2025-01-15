class Solution {
private:

    /*
        if the count of bits set in num1 and num2 are same then return num1, 
        else if num1 has less bit set than num2 then set the rightmost set_bits_countnum2 - set_bitcountnum1 unset bit
        else if num1 has more set bit than num2 set bit then unset the rightmost set_bits_countnum1 - set_bitcountnum2 set bits 
    
    */
    int solMinimizeXor(int num1, int num2){
        //intially our anser will be num1 supposing that bot num1 and num2 has same number of set bits
        int ans = num1;
        //count the number of set bits in num2
        int count_setbits_num2 = 0;
        for(int i = 0; i<32; i++){
            if(((num2>>i) & 1 ) == 1)count_setbits_num2++;  
        }

        //count the number of set bits in num1
        int count_setbits_num1 = 0;
        for(int i = 0; i<32; i++){
            if(((ans>>i) & 1 ) == 1)count_setbits_num1++;  
        }
        cout<<count_setbits_num1<<" "<<count_setbits_num2<<endl; 

        //if both num1 and num2 has same number of set bits then return num1 
        if(count_setbits_num1 == count_setbits_num2)return ans;
        //if less bits in answer are set to 1
        //then we try to set rightmost  (count_setbits_num2 - righmost count_setbits_num1 ) number of unset bits 
        if(count_setbits_num1 < count_setbits_num2){
            cout<<"code is here count_setbits_num1 < count_setbits_num2 ";
            int curr_bit = 0;
            while(count_setbits_num1 < count_setbits_num2){
                if(((ans >> curr_bit) & 1) == 0) {
                    count_setbits_num1++;
                    ans |= (1 << curr_bit );
                }
                curr_bit++;
            }
            return ans;
        }
        //if num1 has more bits set than num2//
        //we try to unset rightmost count_setbits_num1 - count_setbits_num2 number of set bits
        if(count_setbits_num1 > count_setbits_num2){
            int curr_bit = 0;
            while(count_setbits_num1 > count_setbits_num2){
                if(((ans >> curr_bit) & 1) == 1) {
                    count_setbits_num1--;

                    //see in CP notebook also in bit manipulation section
                    ans &= ~( 1 << curr_bit);
                }
                curr_bit++;
            }
            return ans;
        }
        //code will never reach here
        return ans;
    }
public:
    int minimizeXor(int num1, int num2) {
        return solMinimizeXor(num1, num2);
    }
};
