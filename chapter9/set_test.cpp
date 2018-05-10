#include <iostream>
#include <set>
/**
 * set 常见的用法
 * size()
 * clear() 清空set
 * begin() 返回指向set开头的迭代器
 * end() 返回指向set结尾的迭代器
 * insert(key)
 * erase(key)
 * find(key) 搜索与key 一致的元素，并返回指向该元素的迭代器
 *           没有与key 一致的元素，则返回末尾end()
 */
using namespace std;

void print(set<int> s) {
    cout << s.size() << ":";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << " " << (*it);
    }
    cout << endl;
}

int main() {
    set<int> s;
    s.insert(8);
    s.insert(1);
    s.insert(7);
    s.insert(4);
    s.insert(8);
    s.insert(4);

    print(s);

    s.erase(7);
    print(s);
    s.insert(2);
    print(s);
    if (s.find(10) == s.end()) {
        cout << "not found" << endl;
    }
    return 0;
}