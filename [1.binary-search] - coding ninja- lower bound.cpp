/*
  question link -> https://www.naukri.com/code360/problems/lower-bound_8165382?count=25&search=&sort_entity=order&sort_order=ASC&page=1&leftPanelTabValue=SUBMISSION


  concept -> here we have used the concept of how to minimum larger value equal to , or greater than the target
  
*/

int lowerBound(vector<int> arr, int n, int x) {
	int low = 0;
	int high = n-1;
	//take intiall value
	int ans = n ;
	while(low<= high){
		int mid = (low+high)/2;
		if(x <= arr[mid]){
			/* we have a possibility of ans since either it will be equal to larger, 
			so we take and try to find if there some larger value than x which is smaller than current ans and also 
			if it is equal to x then we try to find if there is more occurance of it 
			*/
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;
}
