#include <bits/stdc++.h>
using namespace std ;

int arr[1005][1005] ;
bool vis [1005][1005] ;

int N, M ; bool f ;
typedef pair <int,int> ii ;
vector < ii > starting ,ending;
int temp ;
int dx[]= { 0 , 0 , -1 , 1} ;
int dy[]= { 1 , -1 , 0 , 0 };

void bk ( int x ,int y , int cur , int max ){
      
      if ( y < 0 || y >= M || x < 0 || x >= N )
      return ;
      
      if ( vis[x][y] )
      return ;

     // if ( x == N-1 && cur != max)
      //return ;
    // cout << "> " << x <<" "<<y << " "<< cur <<" "<<max<<endl;
      vis[x][y] = true ;
      ending.push_back( ii (x,y));
      if ( x == N-1 ){
      	  if ( y < temp){
      	  	 temp = y ; f = true ;
      	  }
      	  return ;          
      }
      

     int i ;
     if ( cur == max ){
     	  max++ ; cur = 1 ;
     	for ( i = 0 ; i < 4 ; i++)
     	if ( arr [ x+dx[i] ] [ y+dy[i]] == cur )
     	bk ( x+dx[i] , y +dy[i] , cur , max );
     }
     else {
     	cur += 1 ;
     	for ( i = 0 ; i < 4 ; i++)
     	if ( arr[x+dx[i]] [ y + dy[i]] == cur )
     	bk ( x+dx[i] , y +dy[i] , cur , max) ;
    }

 return ;
}



int main(){
int i,j,k ,test , x ;
scanf("%d" ,&test) ;
  while ( test -- ){
  	  starting . clear() ; 
  	  ending . clear() ;
  	 
  	  scanf("%d %d"  , &N , &M) ;
  	 
  	  for ( i = 0  ; i < N ; i++)
  	  for( j = 0 ; j < M; j++)
  	  scanf("%d", &arr[i][j]) ;
      
      for ( i = 0 ; i < N; i++)
      for ( j = 0 ; j < M ; j++)
      vis[i][j]= false ;

      for ( i = 0 ; i < M ; i++ )
      	  if ( arr[0][i] == 1 ){
      	  	// cout<<"\n-----------\n";
      	  	 f = false ; temp = M ;
      	  	 bk ( 0, i , 1 , 1);
      	  
      	  	 	 for ( j = 0 ; j < ending.size() ; j++)
      	  	 	 vis [ ending[j].first][ending[j].second] = false ;
      	  	 	 ending.clear() ;
      	  	 

      	  	 if ( f )
      	  	 starting . push_back ( ii ( i , temp)) ;
      	   ending.clear();
       }

    sort ( starting.begin() , starting.end() );
    printf("%d %d\n%d %d\n",1 , starting[0].first+1 , N  , starting[0].second+1);
    if(test)
    printf("\n");
}

return 0 ;


}
