//Generate first n primes using sieve
//Time complexity: O(nlog(n))

bool isPrime[MAXN+1];
vector<int> primes;
void getPrimes(){
	for(int i=0;i<=MAXN;i++){
		isPrime[i]=true;
	}
	for(int i=2;i<sqrt(MAXN);i++){
		if(isPrime[i]){
			for(int j=i*i;j<=MAXN;j+=i){
				isPrime[j]=false;
			}
		}
	}
	for(int i=2;i<=MAXN;i++){
		if(isPrime[i]){
			primes.push_back(i);
			cout<<i<<endl;
		}
	}
}
