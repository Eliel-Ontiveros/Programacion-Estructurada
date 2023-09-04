#include <iostream>
using namespace std ;

int main ()
{
    int a,b,c;
    //ingresamos los numeros
    cout << "Ingrese primer numero : " ;
    cin >> a;
    cout << "Ingrese segundo numero : " ;
    cin >> b;
    cout << "Ingrese tercer numero : " ;
    cin >> c;

    if(a>b && a<c || a<b && a>c )
        cout << "El numero intermedio es : " << a;
    else if(b>a && b<c || b<a && b>c)
        cout << "El numero intermedio es : " << b;
    else if(c>a && c<b || c<a && c>b)
        cout << "El numero intermedio es : " << c;
    else
        cout << "No existe un numero intermedio";
}
