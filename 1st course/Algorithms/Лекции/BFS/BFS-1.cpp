#include<iostream>
#include<vector>
#include<queue>

using node = size_t;

// https://informatics.msk.ru/mod/statements/view.php?chapterid=160#1

int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<std::vector<node> > gr(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            if (x == 1) {
                gr[i].push_back(j);
            }
        }
    }
    node start = 0, finish = 0;
    std::cin >> start >> finish;
    --start, --finish;

    std::queue<node> q;
    std::vector<int> dist(n, n);
    std::vector<int> parent(n, -1);

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (const auto& to : gr[cur]) {
            if (dist[to] > dist[cur] + 1) {
                dist[to] = dist[cur] + 1;
                parent[to] = cur;
                q.push(to);
            }
        }
    }
    node v = finish;
    while (v != -1) {
        std::cout << v + 1 << ' ';
        v = parent[v];
    }






    return 0;
}
