#include <iostream>
using namespace std;
main()
{
	int n;
	cin>>n;
	int hang =1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n-i;j++) {
			cout<<" ";
		}
		for(int k=1;k<=hang;k++){
			cout<<"* ";
		}
		cout<<endl;
		hang++;
	}
}