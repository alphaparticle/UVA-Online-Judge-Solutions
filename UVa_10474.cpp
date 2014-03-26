//ak92thelooser WA ( Not sure why )
// Can also be done by linear search 
#include <bits/stdc++.h>
using namespace std ;


long arr [11000];
vector < long > v;

int main(){
long n , q , i , j , k = 1, temp ,x ;
 while ( scanf("%ld %ld" ,&n ,&q)){
 	 if ( q == 0 && n == 0)
 	 break ; 
 	 memset ( arr , -1 ,sizeof arr) ; v.clear() ;
 	 for ( i = 0; i < n ; i++){
 	 	 scanf("%ld",&x);
 	 	 v.push_back (x);
 	 	 
 	 }
 	 sort(v.begin() ,v.end());
 	 for( i = 0 ; i < v.size() ; i++){
 	 	 if (arr[v[i]] < 0)
 	 	 arr[ v[i] ] = i+1 ;
 	 }
     printf("Case# %ld:\n",k++);
 	 for ( i = 0 ; i < q ;i++){
 	 	 scanf("%ld",&temp);
 	 	 if ( arr[temp] >= 0 )
 	 	 printf("%ld found at %ld\n",temp ,arr[temp]);
 	 	 else
 	 	 printf("%ld not found\n",temp); 
 	 }
 }
return 0 ;

}
