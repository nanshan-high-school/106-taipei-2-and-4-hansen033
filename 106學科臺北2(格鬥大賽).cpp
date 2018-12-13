#include<iostream>
using namespace std;
int main(){
	int people;
	while( cin >> people ){
		int attack[people], defence[people], win[people] = {0};
		for( int t = 0 ; t < people ; t ++ ){
			cin >> attack[t] >> defence[t];
		}
		for( int t = 0 ; t < people ; t ++){
			int winn = 1, winn2 = 1;
			for( int u = t ; u < people - 1 && winn == 1 ; u ++ ){
				if( attack[t] >= attack[u + 1] && defence[t] >= defence[u + 1] ){
					if( attack[t] > attack[u + 1] || defence[t] > defence[u + 1] ){
						win[t] ++;
					}else{
						winn = 0;
					}
				}
			}
			for( int u = t ; u > 0 && winn2 == 1 ; u -- ){
				if( attack[t] >= attack[u - 1] && defence[t] >= defence[u - 1] ){
					if( attack[t] > attack[u - 1] || defence[t] > defence[u - 1] ){
						win[t] ++;
					}else{
						winn2 = 0;
					}
				}
			}	
		}
		int biggest = 0;
		for( int t = 0 ; t < people ; t ++ ){
			if ( win[t] > biggest ){
				biggest = win[t];
			}
		}
		cout << biggest; 
	}
}
