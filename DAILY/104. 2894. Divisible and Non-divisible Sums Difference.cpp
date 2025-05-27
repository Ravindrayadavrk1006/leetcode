class Solution {
private:
    /*
        arithmatic progression sum -> AP sum
            formula n/2*(2*a-(n-1)*d) or 2*(start + last)
        sum of n natural numbers = (n*n+1)/2
    */
    int sol_difference_of_sums(int n, int m){
        //sum of n natural numbers n*n+1/2
        int sum_till_n = (n*(n+1))/2;
        int count_multiple_of_m_till_n = n/m;
        //AP sum -> n/2*(2*a-(n-1)*d) formula
        int sum_arithmatic_progression = (count_multiple_of_m_till_n*(2*m+ (count_multiple_of_m_till_n-1)*m))/2;

        //according to the question  nums1 = total_sum- sum_arithmatic_progression
        //nums2 = sum_arithmatic_progression
        //=> nums1 - nums2 = total_sum - 2*sum-arithmatic_progression
        return sum_till_n - 2*sum_arithmatic_progression ;
    }
public:
    int differenceOfSums(int n, int m) {
        return sol_difference_of_sums(n, m);
    }
};
