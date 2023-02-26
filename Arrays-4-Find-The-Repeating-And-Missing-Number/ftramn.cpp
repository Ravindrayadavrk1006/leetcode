coding -ninja problem link ---> https://www.codingninjas.com/codestudio/problems/find-the-repeating-and-missing-number_1062727?leftPanelTab=0

/*
many approaches for this problem
[1.]
    sort the array in nlogn 
    a.find the duplicate in O(n)
    b.find the missing by checking while(nums[i]+2 != nums[i+1]) 
    the missing will be nums[i]+1
[2.] doing hasing count the occurance O(n) t.c s.c O(n) and then t.c O(n)
for finding if count[i] == 2 is the repeating and count[i]==0 for missing

[3].we use the mathematics formula
eg suppose given array 4 3 6 2 1 1
we sum the sum of n natural number n(n+1)/2 and then we find the sum of array
we get  
sum of n natural number = 1+2+3+4+5+6
sum of array = 4+3+6+2+1+1
we get n_natural_number - sum of array = 5- 1 i.e the missing number - repeating number
let missing number = X and repeating element Y
we got X-Y = 4
 a .we also know sum of square of number = n*n+1*2n+1/6
b .we sum the square of array elements 
when we substract a -b  we get X^2-Y^2 = 24
we also X^2-Y^2 = x+y * x-y 
we already have x+y value we put in the above equation and we get x+y = 6
now we have x+y = 6 and x-y = 4 
we can eaily find x and y

[4]
eg . 1 4 2 5 2
 we use the xor concept 
 xor is used to find the number present even number of times
 here if we xor the complete array and then with the number 1 to n 
 we get missing_number^number repeating 
 let missing number = X
 number repeating= Y 
now we have X^Y
 suppose X^Y = 3^2
 which is equal to 011 ^ 010 =  101
 since in xor we get 1 only when one bit is 1 and other is 0 
 using this same concept we know the position in the xor where we get 1 
 if 3 is having bit 1 then 2 will have 0 bit
 so we try to divide the numbers of array in two bucket where we xor the elemnt
 which have 0 corresponding to the right most bit in xor where it is one
 in one bucket and where the bit is 1 in in other bucket
 eg 
 right most set  001 in the xor reslt we get this bit mask by xorvalue & ~(xorvalue-1)
 1 ,5 will be one bucket and 4 ,2,2 in other bucket
 now we will also divide  the values from 1 to n in the buckets
 1,2,3,4,5
 so now the final values in each bucket will be
 1,5,1,3,5   and in other bucket 4,2,2,2,4
 and when we xor the buckets values we finllay have
 3 in first bucket and 2 in other bucket



*/
//sol 4
void sol(vector<int> nums,vector<int>& temp)
{
    int n = nums.size();
    int xor_val = 0;
    for(auto val: nums)
    {
        xor_val= xor_val^val;
    }
    for(int i =1 ; i<=n ; i++)
    {
        xor_val= xor_val^i;
    }

    //finding the right most bit mask
    int rmbm = xor_val & ~(xor_val-1);

    //dividing them in bucket and xoring the values at same time
    int val_1 = 0;
    int val_2 = 0;
    for(int val:nums)
    {
        if(val&rmbm)
        {
            val_1=val_1^val;
        }
        else
        {
            val_2 = val_2^val;
        }
    }
    //now we have to xor the values 1 to n too
    for(int i =1 ; i<=n ; i++)
    {
        if(i&rmbm)
        {
            val_1=val_1^i;
        }
        else
        {
            val_2 = val_2^i;
        }
    }
    // temp[0]=val_2;
    // temp[1]=val_1;
    int i = 0;
    for(int i = 0; i<n; i++)
    {
        if(nums[i]==val_1)
        {
            temp[0]=val_1;
            temp[1]=val_2;
            break;
        }
        if(nums[i] == val_2)
        {
            temp[0]=val_2;
            temp[1]=val_1;
            break;
        }
    }
}
vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    // Write your code here.
    vector<int> temp(2,0) ;
    sol(nums,temp);
    return temp;
}
