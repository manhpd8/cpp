#include <iostream>
using namespace std;
main() {
	int n;
	cin>>n;
	for(int i=1; i<=n-1; i++) {
		for(int j=1; j<=n-i; j++) {
			cout<<" ";
		}
		for(int k=1; k<=i; k++) {
			if(k==1 || k==i) {
				cout<<"* ";
			} else {
				cout<<"  ";

			}
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++) cout<<"* ";
}