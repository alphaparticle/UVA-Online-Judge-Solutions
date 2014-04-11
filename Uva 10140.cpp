//ak92thelooser
// Segmented seive

#include <bits/stdc++.h>
using namespace std ;
#define MM 1000000
bool p[MM+10] ;
vector <long long> v ;
void seive(){
	long long i, j ;
	p[0] = p[1] = false ;
	for ( i  = 2 ; i <= MM ; i++)
    if (p[i]){
    	 v.push_back(i); //cout<<i <<" ";
    	 for ( j = i*i ; j <= MM ; j += i)
    	 p[j] = false ;
    }
}

vector <long long > temp ;
long long first( long long lo, long long i)
{
    if(lo%i==0)
            return max(lo,i*i);
    else
        return max(lo + (i-lo%i),i*i);
}
int main(){
 // freopen("input.txt" , "r" , stdin);
 // freopen("x.txt" , "w" , stdout) ;
  long long l , r , i , j , k , mini , maxi , a, b , c ,d , past , future ; ;
  memset ( p , true , sizeof p) ;
  seive() ;
 // return 0;
  // cout << v.size() << endl;
  while ( scanf("%lld %lld" ,&l ,&r) == 2 ){
      memset ( p , true , sizeof  p);
      temp.clear() ;

      for ( i = 0 ; v[i]*v[i] <= r ; i++ ){
         //cout << i <<" "<< v[i] << endl;
          for ( j = first (l,v[i]) ; j <= r ; j += v[i] ){
           // cout << j - l + 1 <<" ";
            p[j-l+1] = false ;
            }
      }
      if ( l == 1)
      {
         p[l] = false ;
      }


    for (i = 1 ; i <= r-l+1 ; i ++ )
    if ( p[i] ){ //cout << i <<" ";
    temp.push_back(i+l-1) ; }
    
     maxi = 0 ; mini = 999999999999 ;
     c = a = b = d =1 ;

     for ( i = 0 ; i < temp.size()-1 && i+1 < temp.size() ; i++ ){
         //cout << temp[i]+l <<" "<<temp[i]+l << endl;
         if( temp[i+1] - temp[i] < mini){
         	 mini = temp[i+1] - temp[i] ;
         	 a  = temp[i] ; b = temp[i+1] ;
         }
         
         if(temp[i+1] - temp[i] > maxi){
         	 maxi = temp[i+1] - temp[i] ;
         	 c  = temp[i] ; d = temp[i+1] ;
         }
     }
    if ( temp.size() >= 2 ){
    	 printf("%lld,%lld are closest, %lld,%lld are most distant.\n",a,b,c,d);

    }
    else printf("There are no adjacent primes.\n");


  }

	return 0 ;
}
