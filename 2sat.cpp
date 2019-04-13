/// Name: 2SAT
/// Description:
/// Detail:
/// Request: SAT2
/// Guarantee: struct SAT2 {
/// Dependencies: graph, tarjan
/// Parent:
struct SAT2 {
    SAT2(int n):graph(2*n){}
    void add(int m1, int x1, int m2, int x2) {
        imply(not m1, x1, m2, x2);
        imply(not m2, x2, m1, x1);
    }
    void imply(int m1, int x1, int m2, int x2) {
        graph.addEdge1(2*x1+m1, 2*x2+m2);
    }
    bool hasSolution() const {
        auto owner = vector<int>(graph.size(), -1);
        graph.tarjan([&](int rep){
            return [&owner, rep](int v){
                owner[v] = rep;
            };
        });
        for (auto i=0; i<graph.size()/2; ++i)
            if (owner[2*i] == owner[2*i+1])
                return false;
        return true;
    }
    Graph graph;
};
