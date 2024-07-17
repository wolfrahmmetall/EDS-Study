#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

/*
Код реализует алгоритм тернарного поиска для нахождения точки на отрезке, ближайшей к заданной точке
*/

template<typename T>
class point {
public:
    T x = 0;
    T y = 0;
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

    friend point<T> operator*(T k, const point& a) {
        return point<T>(k * a.x, k * a.y);
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

    double len() {
        return sqrt(x * x + y * y);
    }

};

template<class T>
double dist(const point<T>& a, const point<T>& b) {
    return (a - b).len();
}


int main() {
    point<double> p, a, b;
    std::cin >> p >> a >> b;
    for (int i = 0; i < 50; ++i) {
        point<double> m1 = a + 1.0 / 3 * (b - a);
        point<double> m2 = a + 2.0 / 3 * (b - a);
        if ((p - m1).len() > (p - m2).len()) {
            a = m1;
        } else {
            b = m2;
        }
    }
    std::cout << std::setprecision(6) << std::fixed << (p - a).len();
    return 0;
}
