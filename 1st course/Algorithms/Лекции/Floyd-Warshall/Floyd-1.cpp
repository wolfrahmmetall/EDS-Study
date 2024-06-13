#include<iostream>
#include<vector>
#include<cmath>

/*
В первой строке вводится количество вершин графа, стартовая и финишная вершина,
между которыми ищем путь
Далее идет матрица смежности
Если путь существует, выводим расстояние, если нет - выводим -1
*/

const int inf = (1 << 20);

int main() {
    size_t n = 0, s = 0, f = 0;
    std::cin >> n >> s >> f;
    --s, --f;
    std::vector<std::vector<int> > gr(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
            if (gr[i][j] == -1) {
                    gr[i][j] = inf;
            }
        }
    }
    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }
    std::cout << (gr[s][f] == inf ? -1 : gr[s][f]);
    return 0;
}
