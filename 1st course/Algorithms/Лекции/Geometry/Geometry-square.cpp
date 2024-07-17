#include<iostream>
#include<vector>
#include<cmath>

/*
Код вычисляет площадь многоугольника по его координатам в двумерном пространстве
*/

template<typename T>
class point {
    T x = 0;
    T y = 0;
public:
    point() {}
    point(T x, T y) : x(x), y(y) {}

    friend point<T> operator+(const point& a, const point& b) {
        return point<T>(a.x + b.x, a.y + b.y);
    }

    friend point<T> operator-(const point& a, const point& b) {
        return point<T>(a.x - b.x, a.y - b.y);
    }

    friend T operator*(const point& a, const point& b) {
        return a.x * b.x + a.y * b.y;
    }

    friend T operator^(const point& a, const point& b) {
        return a.x * b.y - b.x * a.y;
    }

    friend std::istream& operator >> (std::istream& is, point& p) {
        is >> p.x >> p.y;
        return is;
    }

    friend std::ostream& operator << (std::ostream& os, const point& p) {
        os << p.x << ' ' << p.y;
        return os;
    }
};


int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<point<int> > v(n);
    for (auto& p : v) {
        std::cin >> p;
    }
    int64_t s = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t j = (i + 1) % n;
        s += v[i] ^ v[j];
    }
    std::cout << std::abs(s / 2.0);
    return 0;
}
