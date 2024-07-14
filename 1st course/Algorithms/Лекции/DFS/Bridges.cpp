#include<iostream>
#include<vector>
#include<functional>
#include<set>

using node = size_t;

/*
Код ищет мосты и точки сочленения в графе с помощью DFS
*/

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<node>> gr(n);
    for (size_t i = 0; i < m; ++i) {
        size_t u = 0, v = 0;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    std::vector<int> used(n);
    std::vector<int> tin(n);
    std::vector<int> tup(n);
    std::set<node> points;
    int timer = 0;

    std::function<void(node, node)> dfs = [&] (node v, node p) {
        used[v] = true;
        int count = 0;
        ++timer;
        tin[v] = tup[v] = timer;
        for (const auto& to : gr[v]) {
            if (to == p) continue;
            if (used[to]) {
                tup[v] = std::min(tin[to], tup[v]);
            } else {
                dfs(to, v);
                ++count;
                tup[v] = std::min(tup[v], tup[to]);
                if (tin[v] < tup[to]) {
                    std::cout << v << '-' << to << '\n';
                }
                if (tin[v] <= tup[to] && p != -1) {
                    points.insert(v);
                }
            }
        }
        if (p == -1 && count > 1) {
            points.insert(v);
        }
    };
    dfs(0, -1);
    for (const auto& v : points) {
        std::cout << v << ' ';
    }
    return 0;
}
