//ak92thelooser
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std ;

typedef pair  < long , string > is ;
typedef pair < long , is > iis ; 

vector  < iis > V ;

string s ;



int main(){
 int test , i , j,  k , sz , q;
 long l ,r ;
 vector  < iis> :: iterator  it , fit;
scanf("%d",&test);
while ( test -- ){
	V .clear() ;
	 scanf("%d" ,&sz) ;
	 for ( i = 0 ; i < sz ; i++){
           cin >>s ; 
	      scanf("%ld %ld" , &l ,&r) ;
	      V.push_back ( iis ( r , is ( l , s))) ;
	 }

	 sort ( V.begin() , V.end() );
	 scanf("%d" ,&q) ;
	 for ( i = 0 ; i < q ; i++){
	 	  scanf("%ld" ,&l) ;
	 	  
	 	  int index = V.size() +10;
	 	  for ( j = 0 ; j < V.size() ;j ++){
	 	  	 if ( V[j].first >= l && V[j].second.first <= l ){
	 	  	 	index = j ; break ;
	 	  	 }
	 	  }
	 	 
	 	  bool f = true ;
	 	 
	 	   for (j = index+1 ;j < V.size() ; j++ )
	 	   if ( V[j].first >= l && V[j].second.first <= l ){
	       f = false ; break ;}

	   
	   if ( f && index < V.size() )
	   printf("%s\n",V[index].second.second.c_str());
	   else
	   printf("UNDETERMINED\n");
	 }
	 if(test)
	 printf("\n");

}

	return 0 ;
}
