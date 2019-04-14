/// Name: Sieve of Eratosthenes
/// Description:
/// Detail:
/// Request: Sieve
/// Guarantee: struct Sieve {
/// Dependencies:
/// Parent:
struct Sieve {
    Sieve(int n):prime(n+1,true),fac(n+1,1){
        prime[0] = prime[1] = false;
        for (auto p=2; p<=n; ++p)
            if (prime[p]) {
                fac[p] = p;
                for (auto j=2*p; j<=n; j+=p)
                    prime[j] = false, fac[j] = p;
            }
    }
    vector<int> factor(int i) const {
        auto ps = vector<int>();
        while (i > 1)
            ps.push_back(fac[i]), i /= fac[i];
        return ps;
    }
	struct Count { int p, alpha; };
	vector<Count> counts(int i) const {
		auto fs = vector<Count>();
		while (i > 1) {
			auto p = fac[i];
			auto l = 0;
			while (fac[i] == p)
				i /= p, ++l;
			fs.push_back(Count{p, l});
		}
        return fs;
	}
    vector<int> uniqfacs(int i) const {
        auto ps = vector<int>();
        while (i > 1) {
            ps.push_back(fac[i]);
            while (ps.back() == fac[i])
                i /= fac[i];
        }
        return ps;
    }
	vector<int> divisors(int i) const {
		auto ds = vector<int>({1});
		for (auto c : counts(i)) {
			auto l = (int)ds.size();
			for (auto k=0; k<c.alpha; ++k)
				for (auto j=0; j<l; ++j)
					ds.push_back(ds.rbegin()[l-1] * c.p);
		}
		return ds;
	}
    vector<int> allPrimes() const {
        vector<int> ps;
        for (auto p=2; p<(int)prime.size(); ++p)
            if (prime[p])
                ps.push_back(p);
        return ps;
    }
    vector<bool> prime;
    vector<int> fac;
};