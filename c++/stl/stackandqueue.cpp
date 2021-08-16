/* Stack and Queue in STL
1)  stack<int> s;
2) s.push(),   s.pop(),  s.clear(),  s.empty(), s.size();

3) queue<int>q;
4) queue.push(), q.pop(), q.clear(), q.empty(),  q.size();
*/
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    stack<int> s;

    s.push(10);
    s.push(20);

    cout<<s.top();
    s.pop();
    return 0;
}

