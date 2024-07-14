#include<iostream>
#include<vector>
#include<functional>

using node = size_t;

class Graph {
    std::vector<std::vector<node>> gr_;
public:

    Graph(size_t sz) {
        gr_.resize(sz);
    }

    std::vector<node>& operator[] (size_t index) {
        return gr_[index];
    }


    std::vector<node> find_diameter() {
        std::vector<node> ans, path;
        std::vector<int> used(gr_.size(), 0);

        std::function<void(node v)> dfs = [&] (node v) {
            used[v] = true;
            path.emplace_back(v);
            for (const auto& to : gr_[v]) {
                if (!used[to]) {
                    dfs(to);
                }
            }
            if (ans.size() < path.size()) {
                ans = path;
            }
            path.pop_back();
        };
        dfs(0);
        used.assign(gr_.size(), 0);
        dfs(ans.back());
        return ans;
    }

};



int main() {
    size_t n = 0;
    std::cin >> n;
    Graph g(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t u = 0, v = 0;
        std::cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::cout << g.find_diameter().size();
    return 0;
}
