#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void solve()
{
	int n;cin >> n;
	if(n==1 || n==3) cout << "Alice" << endl;
	else if (n==2) cout << "Bob" << endl;
	else if (n%2 == 0) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
	int t;cin >> t;
	while(t--)
		solve();
	return 0;
}
