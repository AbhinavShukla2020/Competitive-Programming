//Find smallest prime factor using sieve
//Time complexity: O(nlog(log(n)))

int smallestPrimeFactor[MAXN+1];
void sieve(){
	for(int i=0;i<MAXN;i++){
		smallestPrimeFactor[i]=i;
	}
	for(int i=2;i<sqrt(MAXN);i++){
		if(smallestPrimeFactor[i]==i){
			for(int j=i*i;j<MAXN;j+=i){
				if(smallestPrimeFactor[j]==j){
					smallestPrimeFactor[j]=i;
				}
			}
		}
	}
}
