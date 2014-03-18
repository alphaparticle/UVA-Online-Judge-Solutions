//ak92thelooser
#include <bits/stdc++.h>
using namespace std ;
int n , p ;
int arr[21] ;
bool f ;
void bk ( int cur , int cur_len ){
      //cout<<"!"<<cur;
      
      if ( cur_len == p){
      	 f = true ;
      	 return ;
      }
      if ( cur >= n){
      return ;
  }

      if (f)
      return ;
      bk ( cur+1 , cur_len) ;
      if (f)
      return ;
      bk ( cur+1 , cur_len + arr[cur] );
      return ;
}

int main(){
 int test , i , j, k;
 scanf("%d",&test) ;
 while ( test -- ){
 	  scanf("%d" ,&p);
 	  scanf("%d" ,&n);
 	  for ( i = 0; i < n ; i++)
 	  scanf("%d" ,&arr[i] );
 	f = false ;
 	bk ( 0 , 0 );
 	if ( f )
 		printf("YES\n");
 	else
 	printf("NO\n");
 }
return 0 ;
}
