/// Name: Takeover queue
/// Description:
/// Detail:
/// Request: TakeoverQueue
/// Guarantee: struct TakeoverQueue {
/// Dependencies:
/// Parent:
template <typename O, typename X, typename Y, typename T, typename F, typename G, typename H, typename I> struct TakeoverQueue {
	struct OQC {
		const H& order;
		const I& id;
		bool operator()(const O& o1, const O& o2) const {
			return make_pair(order(o1), id(o1)) < make_pair(order(o2), id(o2));
		}
	};
	using OQCI = typename set<O, OQC>::iterator;
	using OQCI2 = pair<OQCI, OQCI>;
	struct DQC {
		const G& countdown;
		const I& id;
		bool operator()(const OQCI2& d1, const OQCI2& d2) const {
			return make_pair(countdown(*d1.first, *d1.second), id(*d1.first)) < make_pair(countdown(*d2.first, *d2.second), id(*d2.first));
		}
	};
	TakeoverQueue(F key, G countdown, H order, I id):oq(OQC{this->order, this->id}),dq(DQC{this->countdown, this->id}),key(key),countdown(countdown),order(order),id(id){}
	bool empty() const {
		return oq.empty();
	}
	Y score() const {
		return key(*oq.begin(), lastx);
	}
	vector<O> winners() const {
		auto rs = vector<O>({*oq.begin()});
		auto y = key(rs[0], lastx);
		for (auto it=next(oq.begin()); it!=oq.end() and key(*it, lastx) == y; ++it)
			rs.push_back(*it);
		return rs;
	}
	void insert(O o) {
		auto io2 = oq.insert(o).first;
		auto io3 = next(io2);
		auto has1 = io2 != oq.begin();
		auto has3 = io3 != oq.end();
		if (has1) {
			auto io1 = prev(io2);
			if (has3)
				dq.erase(dq.find({io3, io1}));
			dq.emplace(io2, io1);
		}
		if (has3)
			dq.emplace(io3, io2);
	}
	void advance(X x) {
		lastx = x;
		while (true) {
			auto di = dq.begin();
			if (di == dq.end() or key(*di->first, x) >= key(*di->second, x))
				break;
			auto d = *di;
			dq.erase(di);
			if (d.second != oq.begin()) {
				auto io3 = prev(d.second);
				dq.erase(dq.find({d.second, io3}));
				dq.emplace(d.first, io3);
			}
			oq.erase(d.second);
		}
	}
	set<O, OQC> oq;
	set<OQCI2, DQC> dq;
	F key;
	G countdown;
	H order;
	I id;
	X lastx;
};
