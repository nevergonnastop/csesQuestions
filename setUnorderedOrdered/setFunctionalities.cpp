#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> s;
    s.insert({2,1});
    // s.erase(3);

    // for (const int& elem : s) {
    //     std::cout << elem << " ";
    // }

    auto it = s.lower_bound(2);
    if(it == s.begin()){
        cout << it->first << endl;
    }
    // if (it != s.end()) {
    //     std::cout << "\nLower bound of 4: " << *it << endl;
    // }

    // it = s.upper_bound(4);
    // if (it != s.end()) {
    //     std::cout << "Upper bound of 4: " << *it << endl;
    // }

    std::cout << "Size: " << s.size() << endl;
    return 0;
}
