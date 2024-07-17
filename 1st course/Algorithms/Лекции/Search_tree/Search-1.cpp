#include <iostream>
#include <random>
#include <ctime>

std::mt19937_64 rd(time(0));

template<typename T>
class tree {
private:
    struct node {
        T value;
        node* left = nullptr;
        node* right = nullptr;
        node(T value) : value(value) {}
        ~node() {
            delete left;
            delete right;
        }
    } *root = nullptr;

    node* find(node* v, const T& key) {
        if (v == nullptr) return nullptr;
        if (key == v->value) return v;
        if (key < v->value) {
            return find(v->left, key);
        } else {
            return find(v->right, key);
        }
    }

    void add(node* &v, const T& key) {
        if (v == nullptr) {
            v = new node(key);
        } else if (key < v->value) {
            add(v->left, key);
        } else if (key > v->value) {
            add(v->right, key);
        }
    }

    void print(const node* v) const {
        if (v == nullptr) return;
        print(v->left);
        std::cout << v->value << ' ';
        print(v->right);
    }

    node* max(node* v) const {
        while (v->right != nullptr) {
            v = v->right;
        }
        return v;
    }

    node* min(node* v) const {
        while (v->left != nullptr) {
            v = v->left;
        }
        return v;
    }

    void erase(node* &v, const T& key) {
        if (v == nullptr) return;
        if (key < v->value) {
            erase(v->left, key);
        } else if (key > v->value) {
            erase(v->right, key);
        } else {
            if (v->left == nullptr && v->right == nullptr) {
                delete v;
                v = nullptr;
            } else if (v -> left != nullptr && v->right != nullptr) {
                node* tmp = max(v->left);
                v->value = tmp->value;
                erase(v->left, tmp->value);
            } else {
                node* tmp = v;
                v = (v->left != nullptr) ? v->left : v->right;
                delete tmp;
            }
        }
    }

public:
    tree() {}

    ~tree() {
        delete root;
    }

    void add(const T key) {
        add(root, key);
    }

    bool find(const T key) const {
        return find(root, key) != nullptr;
    }

    void print() const {
        print(root);
    }

    void erase(const T key) {
        erase(root, key);
    }
};

int main() {
/*
    Код создает дерево поиска и выполняет следующие операции:
        1. Добавляет узлы с значениями 40, 20, 70, 15, 30, 60 и 83 в дерево
        2. Удаляет узел с значением 40
        3. Печатает все элементы дерева в порядке возрастания
*/
    tree<int> t;
    t.add(40);
    t.add(20);
    t.add(70);
    t.add(15);
    t.add(30);
    t.add(60);
    t.add(83);
    t.erase(40);
    t.print();
    return 0;
}
