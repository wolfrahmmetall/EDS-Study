#include<iostream>
#include<vector>

struct Edge {
    int u;
    int v;
    int w;
};

std::istream& operator >> (std::istream& is, Edge& edge) {
    is >> edge.u >> edge.v >> edge.w;
    return is;
}

std::ostream& operator << (std::ostream& os, const std::vector<int>& v) {
    for (const auto& item : v) {
        std::cout << item << ' ';
    }
    return os;
}

const int inf = 2009000999;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<Edge> edges(m);
    for (auto& e : edges) {
        std::cin >> e;
    }
    int start = 0;
    std::cin >> start;

    std::vector<int> dist(n, inf);
    std::vector<int> p(n, -1);
    dist[start] = 0;

    int isRelax = true;
    for(int k = 0; k < n - 1 && isRelax; ++k) {
        isRelax = false;
        for (const auto& e : edges) {
            if (dist[e.u] != inf && dist[e.u] + e.w < dist[e.v] && p[e.u] != e.v) {
                dist[e.v] = dist[e.u] + e.w;
                p[e.v] = e.u;
                isRelax = true;
            }
            if (dist[e.v] != inf && dist[e.v] + e.w < dist[e.u] && p[e.v] != e.u) {
                dist[e.u] = dist[e.v] + e.w;
                p[e.u] = e.v;
                isRelax = true;
            }
        }
    }
    std::cout << dist << '\n';

}

int main() {
    /*
    Оптимизируем ввод и вывод
    */
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int num = 0;
    std::cin >> num;
    while (num) {
        solve();
        --num;
    }
    return 0;
}
