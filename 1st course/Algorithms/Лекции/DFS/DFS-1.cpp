#include<iostream>
#include<vector>
#include<functional>

/*
6 5
0 1
1 4
3 4
0 3
4 5
*/

std::ostream& operator << (std::ostream& os, const std::vector<size_t>& v) {
    for (const auto& a : v) {
        os << a << ' ';
    }
    return os;
}


int main() {
    size_t n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<size_t> > gr(n);
    for (size_t i = 0; i < m; ++i) {
        size_t u = 0, v = 0;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    std::vector<size_t> used(n);
    std::vector<size_t> path;
    std::vector<size_t> ans;
    std::function<void(size_t, size_t)> dfs = [&] (size_t v, size_t p) {
        used[v] = 1;
        path.push_back(v);
        //std::cout << path << '\n';
        for (const auto& to : gr[v]) {
            if (used[to] == 0) {
                dfs(to, v);
            } else if (used[to] == 1 && to != p) {
                ans = path;
                ans.push_back(to);
            }
        }
        used[v] = 2;
        path.pop_back();
        //std::cout << path << '\n';
    };

    for (size_t i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }

    std::cout << ans;
    return 0;
}
