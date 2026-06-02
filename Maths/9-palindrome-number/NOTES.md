////*****************************OTHERS SOLUTION WORTH LEARNING************************************
////******************CHECKING THE MID TRICK**********************************
func isPalindrome(x int) bool {
    var reversedNum int
    
    // If x is a negative number it is not a palindrome
    // If x % 10 = 0, in order for it to be a palindrome the first digit should also be 0
    if x < 0 ||(x % 10 == 0 && x != 0) {
        return false
    }
    
    for x > reversedNum {   ////****** HERE IMPORTANT CHECKING IF HALF OF THAT
        reversedNum = reversedNum*10 + x%10
        x =x/10
    }
    
    // If x is equal to reversed number then it is a palindrome
    // If x has odd number of digits, dicard the middle digit before comparing with x
    // Example, if x = 23132, at the end of for loop x = 23 and reversedNum = 231
    // So, reversedNum/10 = 23, which is equal to x
    return x == reversedNum || x == reversedNum/10
}


////*******OTHER WAY IS TO STORE THE REVERSE IN A INT AND THEN COMPARE WITH ORIGINAL
int reverse=0;
then updating the reverse by getting the modulus values from the x  by reverse*10+ original%10;
