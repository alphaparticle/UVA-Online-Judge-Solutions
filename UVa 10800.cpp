#include <bits/stdc++.h>
using namespace std ;

char arr[100][100] ;
string a ;


void solve ( int x ,int y ){

 int i = 0 ;
 //cout << x <<" ------ "<< y << endl;
 if ( a[i] == 'R' ){
   arr[x][y] = '/' ; y++ ;
 }
 else if ( a[i] == 'C' ){
   arr[x][y] = '_' ; y++ ;
 }
 else if (a[i] == 'F' ) {
   arr[x][y] = '\\' ; y++;
 }
 i++ ;
 //  cout << x << " "<< y << endl;
     while ( i < a.length() ){
        if ( a[i] == 'R'){
            if ( a[i-1] == 'R' ){ x-- ; arr[x][y] = '/' ; y++ ;}
        else if (a[i-1] == 'C') {  arr[x][y] = '/' ; y++ ;}
        else if (a[i-1] == 'F') { arr[x][y] = '/' ; y++ ;}
        }
       else if (a[i] == 'C' ){

            if (a[i-1] == 'C' ) { arr[x][y] = '_' ; y++; }
       else if (a[i-1] == 'R' ) {  x-- ; arr[x][y] = '_' ; y++ ;}
       else if (a[i-1] == 'F' ) { arr[x][y] = '_' ;y++ ; }
        }
        else if ( a[i] == 'F' ){

             if ( a[i-1] == 'F' ){ x++ ; arr[x][y] ='\\' ; y++ ;}
         else if (a[i-1] == 'C' ){ x++ ; arr[x][y]= '\\' ; y++ ; }
         else if (a[i-1] == 'R') {  arr[x][y] = '\\' ; y++ ;}
        }
        //cout << x <<" "<< y <<endl;
        i++ ;
     }
}


int main(){
  // freopen("output.txt", "w" ,stdout);
  int test , i , j , k , kase = 1 ; ;
  cin >> test ;
  while ( test -- ){
    memset ( arr , ' ' , sizeof arr) ;
   cin >> a ;
    int height[a.length()] ; memset(height , 0, sizeof height) ;
    j = 1 ;
    height[0] = 1 ;
    for ( i = 1 ; i < a.length () ; i++){
        if( a[i]== 'C' && a[i-1] == 'R')
        j++ ;
        else if (a[i] == 'R' && a[i-1] == 'R' )
        j++ ;
        else if ( a[i] == 'F' && ( a[i-1] == 'C' || a[i-1] == 'F') )
        j-- ;
      height[i] = j ;
      //cout<<height[i]<<" ";
    }
    //cout << endl;
    sort ( height , height+a.length() );
    
  //  for ( i = 0 ; i < a.length() ; i++)
  //  cout << height[i] <<" ";
  //  cout << endl;
    
    int n , m ;
    n = m = 0;
    n = 1; 
     m = a.length()+3 ;
     if ( height[a.length()-1] >= 1)
     n = height[a.length()-1]  ;
     if (height[0] <= 0 ){
       n += abs(height[0]) + 1 ;
     }
     n += 1 ;
    //cout << n << " "<< m << endl;
    for ( i = 0 ; i < n ; i++)
    arr[i][0] = '|' ; 
  arr[n-1][0] = '+' ;
  for ( i = 1 ; i < m ; i++)
  arr[n-1][i] = '-' ;
  
  if (height[0] <= 0)
    height[0] -- ;
   if (height[0] < 0)
   solve(n-2 +height[0],2) ;
   else
    solve(n-2 ,2);
   cout<<"Case #"<<kase++<<":"<<endl;
   for ( i = 0 ; i < n ; i++){
     for(j = 0 ; j < m; j++)
     cout<<arr[i][j] ;
   cout<<endl;
   }
   
   cout << endl;
   
  }
  
  return  0 ;
}










