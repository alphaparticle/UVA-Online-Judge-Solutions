//ak92thelooser
// Binary Search 
#include <bits/stdc++.h>
using namespace std ;

vector <long> arr ;


int main(){
int n ,q, i, j , k;
long x , small ,large  ;
vector <long> :: iterator it ,fit ;
scanf("%d",&n);
for ( i  = 0 ; i < n ; i++ ){
	scanf("%ld",&x);
	arr.push_back (x);
}
scanf("%d",&q);
for ( i = 0; i < q; i++){
	 scanf("%ld" ,&x);
	 it = lower_bound(arr.begin() , arr.end() , x);
	 fit = it ;
	 if ( it == arr.end())
	 {
	 	fit-- ;
	 }
	 //if(it == arr.end())
	 //cout<<"------------------\n";
	 
	 while (*it <= x && it != arr.end() )
	 it++;
	 while (*fit >= x && fit != arr.begin())
	 fit-- ;
	//cout <<" "<<*fit <<" "<<*it<< endl;
	 
	 if ( it == arr.end() && *fit < x )
	 {
	 	 printf("%ld X\n" , *fit) ; continue ;
	 }

	 if ( it != arr.end() && *fit == x && *it > x)
	 {
	 	 printf("X %ld\n" ,*it); continue ;
	 }

	 if ( it != arr.end() && *fit < x && *it > x)
	 {
	 	 printf("%ld %ld\n",*fit ,*it) ; continue ;
	 }
	 if ( it == arr.end() && *fit == x )
	 {
	 	 printf("X X\n");
	 }
}
	return 0 ; 
}
