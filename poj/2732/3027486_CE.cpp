//Squares
// 2005 ECNA ACM contest
// t feil

#include <iostream>
using namespace std;

#define DEBUG false

int rooms[1000][4], n;

//count squares in n by m rectangle
int CountSq(int n, int m){
  int count=0, temp;
  if(n>m){
    temp=n; n=m; m=temp;}
  for(int i=0;i<n;i++)
    count += (n-i)*(m-i);
  return count;
}

//count squares in n by m rect crossing line l up 
int CountWithLine(int n,  int m,  int l){
  int count;
  count = CountSq(n,m);
  count -= CountSq(n-l,m);
  count -= CountSq(l,m);
  return count;
}

bool overlap(int x1, int y1, int y2, int a1, int b1, int b2){
  if(x1==a1)
    if(!(b1>=(y2-2) || b2<=(y1+2)))
      return true;
    else return false;
  else return false;
}

//count squares overlapping in both rooms
int CountCommonSq(int x1, int y1, int x2, int y2,
                  int a1, int b1, int a2, int b2){
  int left, right, width;

  //if A meets on soutside or northside
  if(overlap(x1,y1,y2,a2,b1,b2) || overlap(x2,y1,y2,a1,b1,b2)){ 
    left = (y1+1>b1+1 ? y1+1 : b1+ 1);
    right = (y2-1<b2-1 ? y2-1 : b2-1);
    width = right-left;
    return CountWithLine(x2-x1+a2-a1, width, a2-a1);
  }
  else
  if (overlap(y2,x1,x2,b1,a1,a2) || overlap(y1,x1,x2,b2,a1,a2)){
    left = (x1+1>a1+1 ? x1+1 : a1+1);
    right = (x2-1<a2-1 ? x2-1 : a2-1);
    width=right-left;
    return CountWithLine(y2-y1+b2-b1, width, y2-y1);
  }
  else
  return 0;
}

int main(){
  int x1,  x2, y1, y2, a1, a2, b1, b2;
  int count, probno=1;

  cin>>n;
  while(n>0){
    count=0;
    for(int i=0;i<n;i++){
       cin>>x1>>y1>>x2>>y2;
       if(x1<x2) {rooms[i][0]=x1; rooms[i][2]=x2;}
         else    {rooms[i][0]=x2; rooms[i][2]=x1;}
       if(y1<y2) {rooms[i][1]=y1; rooms[i][3]=y2;}
         else    {rooms[i][1]=y2; rooms[i][3]=y1;}
//      for(int j=0;j<4;j++)
//        cin>>rooms[i][j];
}

    //first count squares in all the rooms
    for(int i=0;i<n;i++)
{
if(DEBUG) cout<<"room "<<i<<": "<< CountSq(rooms[i][2]-rooms[i][0], rooms[i][3]-rooms[i][1])<<endl;
      count += CountSq(rooms[i][2]-rooms[i][0], rooms[i][3]-rooms[i][1]);
}

    //now count overlapping rooms
    for(int i=0;i<n-1;i++)
      for(int j=i+1; j<n; j++)
{if (DEBUG) cout<<"rooms "<<i<<' '<<j<<": "<< CountCommonSq(
             rooms[i][0],rooms[i][1],rooms[i][2],rooms[i][3],
             rooms[j][0],rooms[j][1],rooms[j][2],rooms[j][3])<<endl;
        count += CountCommonSq(
             rooms[i][0],rooms[i][1],rooms[i][2],rooms[i][3],
             rooms[j][0],rooms[j][1],rooms[j][2],rooms[j][3]);
}

    cout<<"Case "<<probno++<<": "<<count<<endl;

    cin>>n;
  }

  return 0;
}
