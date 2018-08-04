#include <stdio.h>
#include <string.h>
#define max(a,b) a > b ? (a) : (b)

int knapsack(int arr[],int peso[],int W,int n){
	int dp[n+1][W+1];
	for(int i = 0; i <= n; i++)
		for(int w = 0; w <= W; w++)
			if(i == 0 || w == 0)
				dp[i][w] = 0;
			else if(arr[i-1] <= w)
				dp[i][w] = max(dp[i-1][w],dp[i-1][w-arr[i-1]]+peso[i-1]);
			else dp[i][w] = dp[i-1][w];
	return dp[n][W];
}

int main(){
	int arr[51],peso[51],N,W,n,K,i;
	scanf("%d",&N);
	while(N--){
		i = 0;
		memset(arr,0,sizeof(arr));
		memset(peso,0,sizeof(peso));
		scanf("%d",&n);
		int aux = n;
		while(aux--){
			scanf("%d %d",&peso[i],&arr[i]);
			i++;
		}
		scanf("%d",&W);
		scanf("%d",&K);
		n = sizeof(arr)/sizeof(arr[0]);
		printf(knapsack(arr,peso,W,n) >= K ? "Missao completada com sucesso\n" : "Falha na missao\n");
	}
	return 0;
}
