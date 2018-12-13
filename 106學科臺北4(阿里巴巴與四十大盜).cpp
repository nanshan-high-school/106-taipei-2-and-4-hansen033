#include <iostream>
#include <math.h>
using namespace std;
int main() {
  //輸入
  int BackLoadKG, BackLoadL, things;
  cin >> BackLoadKG >> BackLoadL >> things;
  //創立格子
  int rankT = pow(2, things);
  int rank[rankT][things], KG[rankT] = {0}, L[rankT] = {0}, value[rankT] = {0}, ans = 0;
  //輸入格
  int thinfo[things][3];
  for( int t = 0 ; t < things ; t ++ )
    cin >> thinfo[t][0] >> thinfo[t][1] >> thinfo[t][2];
  //二
  for( int x = 0 ; x < things ; x ++ ){
    int change = pow(2, x);
    int add = 0;
    for( int y = 0 ; y < rankT ; y ++ ){
      rank[y][x] = add;
      if( y % change == 0 ){
      	add = (add == 0) ? 1 : 0;
	  }
    }
  }
//  for( int x = 0 ; x < rankT ; x ++ ){
//    for( int y = 0 ; y < things ; y ++ ){
//      cout << rank[x][y] << " ";
//    }
//    cout << endl;
//  }
  
  //計算容量
  for( int t = 0 ; t < rankT ; t ++){
    for( int t2 = 0 ; t2 < things ; t2 ++ ){
      if (rank[t][t2] == 1){
        KG[t] += thinfo[t2][0];
        L[t] += thinfo[t2][1];
        value[t] += thinfo[t2][2];
      }
    }
  }
  //判斷結果
  for( int t = 0 ; t < rankT ; t ++ ){
    if( KG[t] <= BackLoadKG && L[t] <= BackLoadL && value[t] > ans ){
      ans = value[t];
    }
  }
  //輸出
  cout << ans;
  system("Pause");
  return 0;
}
