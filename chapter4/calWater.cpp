#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    stack<int> s1;
    stack<pair<int, int>> s2;
    string s;
    int sum = 0;
    cin>>s;
    for (int i = 0;i<s.size(); i++) {
        if (s[i] == '\\') {
            s1.push(i);
        } else if (s[i] == '/'&&s1.size()>0) {
            int j = s1.top();
            s1.pop();
            sum += i - j;
            int a = i - j;
            while (s2.size() > 0 && s2.top().first > j) {
                a += s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(j, a));
        }
    }

    vector<int> ans;
    cout << sum << endl;
    while (s2.size() > 0) {
        ans.push_back(s2.top().second);
        s2.pop();
    }
    cout << ans.size();
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<" ";
        cout<<ans[i];
    }
    cout << endl;
    return 0;
}
