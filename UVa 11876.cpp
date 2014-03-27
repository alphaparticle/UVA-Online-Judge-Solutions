//ak92theloooser
// Sieve + No.of Divisors + Binary Search

#include <bits/stdc++.h>
using namespace std ;
#define M 1000000

bool p[M+10];
vector <long> prime ;

long NOD  [ M+10 ];
//long divi [M*10] ;

void seive(){
	p[0] = p[1]= false ;
	long long i , j ;
	for (i = 2 ; i <= M ; i++ )
	if ( p[i] ){
		 prime.push_back (i);
		 for( j = i*i ; j <= M ; j += i)
		 p[j] = false ;
	}
}

long numDiv ( long x ){
int ans  , temp , power ;
int i , j ;
ans = 1 ;
for ( i = 0 ; prime[i]*prime[i] <= x && x > 1; i++ ){
   power = 0 ;
   while ( x % prime[i] == 0 && x > 1){
       power++;
       x /= prime[i] ;
    }
   if ( power >= 1){
   ans *= (power+1) ;
   i = 0 ;
  }
  
}
if ( x > 1)
ans *= 2;
return ans ;
}

int main(){
long i , j , k , ans , a , b , test , kase = 1;
memset ( p , true , sizeof p);
//memset ( divi , 0 , sizeof divi) ;
seive() ; 
vector < long > NOD ;
NOD.push_back(1);
NOD.push_back(2) ;
vector <long> :: iterator it , fit;
//cout << numDiv (12) ; return 0 ;
for ( i = 3 ; i <= M; i++ ){
	it = NOD.end() ; it-- ;
	  if ( *it > M)
	   break ;
	  
	 NOD.push_back ( *it +  numDiv( *it ) ); 
    //	 cout<< i-1 <<" " << NOD[i-1] << endl;
}

scanf("%ld",&test);
while (test--){
   scanf("%ld %ld" ,&a ,&b);
   it = lower_bound ( NOD.begin() , NOD.end() , a);
   while (*it < a)
   it -- ;
   fit = lower_bound ( NOD.begin() , NOD.end() , b);
   while ( *fit > b)
   fit--;
   //cout << *fit <<" "<< *it <<" "<< fit - NOD.begin() <<" "<<it - NOD.begin() << endl;
   ans = (fit - NOD.begin()) - (it - NOD.begin()) + 1;
   printf("Case %ld: %ld\n" , kase++ , ans);
}

	return 0 ;
}
