https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_799400?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;
/*
concept used we sort both the arrays independently this is done
separately because departure time will never be before arrival time of a train which
states for a train to consider it's departure it's arrival will be before it's arrival

now we have sorted both the arrays
at -->> 50 120 200 550 700 850
dt -->  500 550 600 700 900 1000
we start from 120 in at and 500 in dt
we standing at 120 we see if dt pointer value i.e 500 is smaller than pt_a i.e pointer 
in at array
since not smaller which means a station won't be freed and we go and take a new station and move the 
pt_a value to 200 we have current station value as 2 and we chech with the max station value and if
current station value is greater than the max station value we update max station value

now pt_a at 200 and pt_dt at 500 since pt_a value is smaller than pt_dt value
we require a new station
if pt_dt value smaller than pt_a value we decrement the current station value

*/
int sol(int a[],int dt[], int n)
{
    sort(a,a+n);
    sort(dt,dt+n);
    int pt_a= 1;
    int pt_dt=0;
    int current_platforms=1;
    int max_platforms= 1;
    while(pt_a<n && pt_dt<n)
    {
        if(dt[pt_dt]<a[pt_a])
        {
            pt_dt++;
            current_platforms--;
        }
        else{
            current_platforms++;
            pt_a++;
            max_platforms=max(current_platforms,max_platforms);
        }
    }
    return max_platforms;
    
}
int calculateMinPatforms(int at[], int dt[], int n) {
    return sol(at,dt,n);
}
