#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void func(double*, double, double, double, const int, const int, const double);

int main(){
  //definiere Vektoren um die k-Werte zu speichern
  double k1[3];
  double k2[3];
  double k3[3];
  double k4[3];
  
  //definiere Schrittgröße und Anzahl der Schritte
  const int N = 10000; 
  const int tmax = 100;
  const double dt = tmax/double(N);
  
  // definiere die Randbedingungen
  double x = 1;
  double y = 1;
  double z = 1;
  
  //definiere die angegebenen Konstanten
  const int a = 10;
  const int b = 28;
  const double c = 8/3.0;
  
  cout << 0 << "\t" << x << "\t" << y << "\t" << z << endl;
  for(int i = 1; i <= N; i++){ //Schleife um über alle t zu laufen
    
    //bestimme k1
    func(k1,x,y,z,a,b,c);
    //bestimme k2
    func(k2,x+0.5*dt*k1[0],y+dt*0.5*k1[1],z+dt*0.5*k1[2],a,b,c);
    //bestimme k3
    func(k3,x+dt*0.5*k2[0],y+dt*0.5*k2[1],z+dt*0.5*k2[2],a,b,c);
    //bestimme k4    
    func(k4,x+dt*k3[0],y+dt*k3[1],z+dt*k3[2],a,b,c);
    
    //bestimme den neuen Funktionswert
    x = x + dt*(1/6.0)*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
    y = y + dt*(1/6.0)*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
    z = z + dt*(1/6.0)*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
    
    //Ausgabe der Funktionswerte
    cout << i*dt << "\t" << x << "\t" << y << "\t" << z << endl;
  }
    
  
  return 0;
}

//Unterfunktion
void func(double* k, double x, double y, double z, const int a, const int b, const double c){
  k[0] = a * (y-x);
  k[1] = x * (b - z) - y;
  k[2] = x * y - c * z;
} 
