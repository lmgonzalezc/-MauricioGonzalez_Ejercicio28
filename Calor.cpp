#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
  int nx = 200;
  int nt = 200;
  double dx = 0.01;
  double dt = 0.5;
  double uo[nx][nt];
  double un[nx][nt];
  double k = 200.0;
  double c = 900.0;
  double rho = 2700;
  int i, j;
  ofstream outfile;

  for(i=0;i<nx;i++){
    for(j=0;j<nt;j++){
      uo[i][j]=0.0;
      if((i>80) && (i<120)){
        if(j==0){
          uo[i][j] = 500;
        } 
      }
      else{
          uo[i][j] = 300;
      }
    }
  }
  for(i=1;i<nx-1;i++){
    for(j=1;j<nt-1;j++){
      un[i][j] = uo[i][j-1]+ ((dt*k)/(pow(dx,2)*c*rho))*(uo[i+1][j]+uo[i-1][j] - 1*uo[i][j-1]);
    }
  }

  for(i=0;i<nx;i++){
    for(j=0;j<nt;j++){	
      if((i==0) || (i=200)){
        un[i][j] = 300;
      }
    }
  }
    
  for(i=1;i<nx-1;i++){
    for(j=1;j<nt-1;j++){
      uo[i][j] = un[i][j];
    }
  }
  outfile.open("Calor.dat");
  for(j=0;j<nx;j++){
    for(i=0;i<nt;i++){
      outfile << uo[i][j] << endl;
    }
  }
  outfile.close();
  return 0;
}
