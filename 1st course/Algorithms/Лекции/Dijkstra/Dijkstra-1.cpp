#include<iostream>
#include<vector>
#include<set>

using node = int;
using dist = int;
const int inf = 2009000999;

int main() {
    int num = 0;
    std::cin >> num;
    while (num) {
        size_t n = 0, m = 0;
        std::cin >> n >> m;
        std::vector<std::vector<std::pair<node, dist> > > gr(n);
        for (size_t i = 0; i < m; ++i) {
            int u = 0, v = 0, w = 0;
            std::cin >> u >> v >> w;
            gr[v].push_back({u, w});
            gr[u].push_back({v, w});
        }
        size_t start = 0;
        std::cin >> start;

        std::set<std::pair<dist, node> > q;
        std::vector<int> r(n, inf);
        r[start] = 0;
        q.insert({0, start});
        while (!q.empty()) {
            node cur = q.begin()->second;
            q.erase(q.begin());
            for (auto a : gr[cur]) {
                node to = a.first;
                dist w = a.second;
                if (r[cur] + w < r[to]) {
                    if (r[to] != inf) {
                        q.erase({r[to], to});
                    }
                    r[to] = r[cur] + w;
                    q.insert({r[to], to});
                }
            }
        }
        for (size_t i = 0; i < r.size(); ++i) {
            std::cout << r[i] << ' ';
        }
        std::cout << '\n';
        --num;
    }
    return 0;
}
