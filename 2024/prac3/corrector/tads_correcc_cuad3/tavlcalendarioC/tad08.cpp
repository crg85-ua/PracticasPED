#include <iostream>
#include "tavlcalendario.h"

using namespace std;

int
main(void)
{
  TAVLCalendario a,b;
  TCalendario c1(1,1,2000,(char *)(char *)"fecha"),c2(2,2,2000,(char *)(char *)(char *)"fecha"),c3(3,3,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c6(6,6,2000,(char *)"fecha"),c7(7,7,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c11(11,11,2000,(char *)"fecha"),c12(12,12,2000,(char *)"fecha"),c13(13,12,2000,(char *)"fecha"),c14(14,12,2000,(char *)"fecha"),c15(15,12,2000,(char *)"fecha"),c16(16,12,2000,(char *)"fecha");
  TCalendario c17(17,12,2000,(char *)"fecha"),c18(18,12,2000,(char *)"fecha"),c19(19,12,2000,(char *)"fecha");
  TVectorCalendario v1,v2,v3,v4;
  
  a.Insertar(c8);
  a.Insertar(c12);
  a.Insertar(c3);
  a.Insertar(c4);
  a.Insertar(c9);
  a.Insertar(c14);
  a.Insertar(c16);
  a.Insertar(c11);
  a.Insertar(c7);
  a.Insertar(c6);
  a.Insertar(c15);
  a.Insertar(c1);
  a.Insertar(c13);
  a.Insertar(c10);
  a.Insertar(c2);
  a.Insertar(c5);
  a.Insertar(c17);
  a.Insertar(c18);
  a.Insertar(c19);
  cout<<"nodos_a="<<a.Nodos()<<endl;  

  b=a;
  
  cout<<"nodos_b="<<b.Nodos()<<endl;
  
  v1=a.Inorden();
  v2=a.Postorden();
  a.~TAVLCalendario();
  v3=a.Postorden();
  v4=b.Preorden();
  
  cout<<"nodos_a="<<a.Nodos()<<endl;
  cout<<"nodos_b="<<b.Nodos()<<endl;

  cout<<"inorden="<<v1<<endl;
  cout<<"postorden="<<v2<<endl;
  cout<<"postorden="<<v3<<endl;
  cout<<"preorden="<<v4<<endl;
  cout<<"altura="<<b.Altura()<<endl;
  cout<<"nodos hoja="<<b.NodosHoja()<<endl;
  cout<<"altura="<<a.Altura()<<endl;
  cout<<"nodos hoja="<<a.NodosHoja()<<endl;
}
