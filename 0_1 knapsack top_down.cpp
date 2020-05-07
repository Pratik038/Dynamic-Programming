#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,W; cin>>n>>W;
	int wt[n],val[n],dp[n+1][W+1];
	for(int i=0;i<n;i++) cin>>val[i];
	for(int i=0;i<n;i++) cin>>wt[i];
	
	for(int i=0;i<n+1;i++)
		for(int j=0;j<W+1;j++)
			if(i==0 || j==0)
				dp[i][j]=0;
	
	for(int i=1;i<n+1;i++)
		for(int j=1;j<W+1;j++)
		{
			if(wt[i-1]<=j)
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	cout<<dp[n][W];
	return 0;
}
