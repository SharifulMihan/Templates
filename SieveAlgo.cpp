#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N,1);
vector<int> lp(N),hp(N);

void Sieve(){
	//Sieve Algorithm
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i){
		if (isPrime[i] == true){
			lp[i] = hp[i] = i;
			for (int j = 2*i; j < N; j+=i){ 
				isPrime[j] = false;
				hp[j] = i;
				if (lp[j] == 0) lp[j] = i;
			}
		}
	}
}

int main()
{
	Sieve();

	//Find Prime Factoraisation.
	long long n;
	cin>>n;

	vector<int> prime_factors;
	map<int,int> mPrime_factors;// Count PrimeFactors.

	while(n>1)
	{
		int pri_fac = hp[n];
		while(n%pri_fac==0){
			n /= pri_fac;
			prime_factors.push_back(pri_fac);
			mPrime_factors[pri_fac]++; // Count Prime Factor.
		}
	}
	
	// Print
	for(int prime:prime_factors) cout<<prime<<" ";
	cout<<endl;
	cout<<"PrimeFactors Count: "<<endl;
	for(auto prim:mPrime_factors) cout<<prim.first<<" >> "<<prim.second<<endl;
}