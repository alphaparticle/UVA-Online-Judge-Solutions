#include <bits/stdc++.h>
using namespace std ;
unsigned long long arr [21] , ans ;
int cont[28] ;
char str[28] ; 

int main(){
 arr[1] = 1 ;
 int i ,j, cases , len ;
 for ( i  = 2 ; i <= 20 ; i++ )
 arr[i] = i*arr[i-1] ;
 scanf("%d",&cases);
 for ( j = 1 ; j <= cases ; j++){
 	 memset (cont , 0 , sizeof cont);
 	 scanf("%s",str);
 	 len = strlen(str) ;
 	 for ( i = 0 ; i < len ; i++ )
 	 cont[ str[i]- 'A' ]++ ;
 	ans = arr[len] ; 
 	for ( i = 0 ; i <26 ; i++)
 	if ( cont[i] ){
 		 ans /= arr[cont[i]] ;
 	}
   printf("Data set %d: %lld\n",j ,ans);
 }


	return 0 ;
}
