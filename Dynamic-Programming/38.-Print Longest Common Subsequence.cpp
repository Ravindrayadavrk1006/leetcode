
/*
  PROBLEM LINK: - https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM
	concept of finding the longest common subsequence string , here we are using the code of finding
	the LCS length tabulation approach , now once we have the table.
	we can find the lcs string by going in the similar fashion in the dp array.
	we start from (n,m) and then we are checking the string if current element in both strings have same current character we add it to the answer
	and then we move (i-1,j-1) and if the character are different , we move to the position of max(dp(i-1,j), dp(i,j-1))
	since we have to the move to the position in the same way as we did in finding the tabulation because the answer will come from that direction


*/


string tabulation_dp(int n, int m, string& s1, string& s2){
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	//we have initialized the first row and first column with zero value in the above dp vector defintion itself
	//i<=n since we have done index shifting
	//here normal tabulation dp done for finding the LCS
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	//the above nested for loops will do the finding of length of lcs

	int i = n;
	int j = m;
	string lcs = "";
	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
			lcs = s1[i-1] + lcs;
			i--;
			j--;
		}
		else if(dp[i-1][j]> dp[i][j-1]){
			i--;
		}
		else j--;
	}
	return lcs;
}
string findLCS(int n, int m,string &s1, string &s2){
	return tabulation_dp(n, m, s1, s2);
}
