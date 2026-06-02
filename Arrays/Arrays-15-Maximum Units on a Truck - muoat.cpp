class Solution {
    /*
        using FRACTIONAL KNAPSACK CONCEPT
        since the values i.e units in box are given per box hence we don't even have to divide to get per unit value
        straighforward just sort on basis of second element in each array and proceed
    */
//custom sorting in descending order helper function
static bool sort_helper(vector<int> first, vector<int> second)
{
    return first[1]>second[1];
}
private:
    int sol(vector<vector<int>>& boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        int i = 0;
        int box_left= truckSize;
        int value = 0;
        while(i<n && box_left>=0)
        {
            if(box_left - boxTypes[i][0]>=0)
            {
                value=value + boxTypes[i][0]*boxTypes[i][1];
                box_left-=boxTypes[i][0];
                i++;
            }
            else
            {
                value=value + box_left*boxTypes[i][1];
                box_left = 0;
                i++;
            }
        }
        return value;
    }

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort the array according to the per unit basis
        sort(boxTypes.begin(),boxTypes.end(),sort_helper);
        return sol(boxTypes,truckSize);

    }
};
