//0 N-1
//1dia = ci moedas
//2 = Gi
//3 = Ci
//4 = Ai deseja salvar ai moedas férias

#include <stdio.h>
#define min(a,b) a < b ? (a) : (b)
#define LIMITE 99999999

int main(){
	int GI[5001],CI[5001],AI[5001],dp[5001],pos[5001];
	for(int i = 0; i < 5000; i++)
		GI[i] = CI[i] = AI[i] = dp[i] = pos[i] = 0;
	int n,info = LIMITE;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&GI[i]);
		if(i == GI[i])info = min(info,GI[i]);
	}

	for(int i = 0; i < n; i++)
		scanf("%d",&CI[i]);

	for(int i = 0; i < n; i++)
		scanf("%d",&AI[i]);

	int acabou = 0,qtd = 1,l = 1;
	for(int i = 0; i < n; i++){
		pos[i] = GI[i];
		dp[i] = CI[pos[i]];
	}
	while(!acabou && LIMITE != info){
		for(int i = 0; i < n; i++){
			pos[i] = GI[pos[i]];
			dp[i] += CI[pos[i]];
		}
		int cont = 0;
		for(int i = 0; i < n; i++)
			if(dp[i] >= AI[i])cont++;;
		qtd++;
		if(cont == n)acabou = 1;	
	}
	if(LIMITE != info)printf("%d\n",qtd);
	else printf("%d\n",AI[info]/CI[info]);
	return 0;
}
