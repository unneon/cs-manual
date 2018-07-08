# Sum over subsets

## Code

```cpp
for (auto i=0; i<(1<<n); ++i)
	dyn[i] = xs[i];
for (auto i=0; i<n; ++i)
	for (auto mask=0; mask<(1<<n); ++mask)
		if (mask & (1 << i))
			dyn[mask] += dyn[mask ^ (1 << i)];
```

## Problems
- [Special Pairs](https://www.hackerearth.com/problem/algorithm/special-pairs-7/?utm_source=header&utm_medium=search&utm_campaign=he-search)
- [Compatible Numbers](https://codeforces.com/contest/165/problem/E)
- [Vowels](https://codeforces.com/contest/383/problem/E)
- [Covering Sets](https://www.codechef.com/problems/COVERING)
- [COCI 2011/2012 Problem KOSARE](http://hsin.hr/coci/archive/2011_2012/contest6_tasks.pdf)
- [Vim War](https://www.hackerrank.com/contests/w16/challenges/vim-war)
- [Jzzhu and Numbers](https://codeforces.com/problemset/problem/449/D)
- [Subset](https://www.hackerrank.com/contests/countercode/challenges/subset)
- [Jersey Number](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=635&page=show_problem&problem=4997)
- [Beautiful Sandwich](https://www.codechef.com/SNFL16MR/problems/BEAUTY)
- [Pepsi Cola](https://codeforces.com/group/qcIqFPYhVr/contest/203881/problem/K) [(join group)](https://codeforces.com/group/qcIqFPYhVr/join)
- [Uchiha and Two Products](https://www.hackerearth.com/problem/algorithm/uchiha-brothers-and-two-products-circuit/)
- [Strange Functions](https://www.codechef.com/IPC15P2B/problems/STR_FUNC)
- [Varying Kibibits](https://codeforces.com/contest/800/problem/D)

## Sources

- https://codeforces.com/blog/entry/45223
- https://www.geeksforgeeks.org/sum-subsets-dynamic-programming/
