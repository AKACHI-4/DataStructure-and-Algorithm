
// sieve + segemented siev
vector<bool> sieve(long long n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (long long i=2; i*i<=n; i++) {
        if (isPrime[i]) {
            for (long long j=i*i; j<=n; j+=i)
                isPrime[j] = false;
        }
    }
    
    return isPrime;
}

void getPrimeinRange(long long L, long long R) {
    vector<bool> primes = sieve(sqrt(R));
    vector<bool> isPrime(R-L+1, true);

    // i*i<=R same as i<=sqrt(R)
    for (long long i=2; i*i<=R; i++) {
        if (!primes[i]) continue;

        // breaking down (L+i-1/i*i) - does make sense .. 
        for (long long j=max(i*i, (L+i-1)/i*i); j<=R; j+=i) {
            isPrime[j - L] = false; // this to not a big job .. 
        }
    }

    // easy-peasy
    for (long long i=L; i<=R; i++) {
        if (isPrime[i-L]) cout << i << " ";
    }
}

int32_t main() {
    int L, R;
    cin >> L >> R;
    getPrimeinRange(L, R);

    return 0;
}
