//队列的简单使用
/**
队列的常用函数size(),
front(),返回队首元素
pop() 从队列中取出并删除元素
push() 向队尾添加元素
empty()
**/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int n, q, t;
  string name;
  queue<pair<string, int>> que;

  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> name >> t;
    que.push(make_pair(name, t));
  }
  pair<string, int> u;

  int res = 0;
  ;
  while (!que.empty()) {
    u = que.front();
    que.pop();
    int a = min(u.second, q);
    u.second -= a;
    res += a;
    if (u.second > 0) {
      que.push(u);
    } else {
      cout << u.first << " " << res;
    }
  }
  return 0;
}
