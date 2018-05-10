#include <iostream>
#include <map>
#include <string>
/**
 * map 常见的用法
 * size()
 * clear() 清空map
 * begin() 返回指向map开头的迭代器
 * end() 返回指向map结尾的迭代器
 * insert((key,val))
 * erase(key)
 * find(key) 搜索与key 一致的元素，并返回指向该元素的迭代器
 *           没有与key 一致的元素，则返回末尾end()
 */
using namespace std;

void print(map<string, int> m) {
    cout << m.size() << ":" << endl;

    for (auto it = m.begin(); it != m.end(); it++) {
        pair<string, int> item = *it;
        cout << item.first << "-->" << item.second << endl;
    }
    return;
}


int main() {
    map<string, int> m;
    m["red"] = 32;
    m["blue"] = 688;
    m["yellow"] = 122;
    m["blue"] += 312;


    print(m);


    m.insert(make_pair("zebra", 101010));
    print(m);
    m.insert(make_pair("white", 0));
    print(m);
    m.erase("yellow");
    print(m);

    pair<string, int> target = *m.find(("red"));

    cout << target.first << "-->" << target.second << endl;

    return 0;
}