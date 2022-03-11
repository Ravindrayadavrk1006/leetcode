class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> dupnums(nums.size());
        copy(nums.begin(),nums.end(),dupnums.begin());
        sort(dupnums.begin(),dupnums.end());//sorting the new dupnums array
        // cout<<"dupnums array";
        // cout<<"size of dupnums array"<<dupnums.size();
        // for(int i=0;i<dupnums.size();i++)
        // {
        //     cout<<dupnums[i]<<" ";
        // }
        int forward=0;
        int backward=nums.size()-1;
        while(forward<=backward)
        {
            int temp=dupnums[forward]+dupnums[backward];
            if(temp==target)
            {
                break;
            }
            if(temp<target)++forward;
            else --backward;
        }
        //we have the forward and backward position here now
        //getting their values
        // cout<<"passed the first while loop";
        int valueforward=dupnums[forward];
        int valuebackward=dupnums[backward];
        //finding their location in original array
        int locationforward=-1;
        int locationbackward=-1;
        int i=0;
        if(valueforward==valuebackward)
        {
            // cout<<"equal loop"<<endl;
             while((locationforward==-1 || locationbackward==-1) && i<dupnums.size())
            {
                // cout<<"inside the while loop";
                if(locationforward==-1)
                {
                    if(nums[i]==valueforward)locationforward=i;
                    ++i;
                    continue;
                }
                if(nums[i]==valuebackward)locationbackward=i;
                // cout<<"locationforward=>"<<locationforward<<" "<<"locationbackward=>"<<locationbackward<<endl;
                ++i;

            }

        }
        else
        {
             while((locationforward==-1 || locationbackward==-1) && i<dupnums.size())
            {
                if(nums[i]==valueforward)locationforward=i;
                else if(nums[i]==valuebackward)locationbackward=i;
                // cout<<"locationforward=>"<<locationforward<<" "<<"locationbackward=>"<<locationbackward;
                ++i;

            }
        }
        return vector<int>{locationforward,locationbackward};
    }

};