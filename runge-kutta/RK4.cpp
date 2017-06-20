#include <iostream>
#include <cstdlib>
#include <cmath>
#define func(x,y) pow(x,2)*pow(y,2); //fonksiyon deðiþtirilebilir
using namespace std;

class RungeKutta4
{
	
public:
	double RK4(double xS,double xE,double h,double y0)
	{
		double x0 = 0.0;
		double * x = (double *)malloc(sizeof(double));//adým deðerlerini tutan tam sayý dizisi.Örnek h=.25 için x0 = 4 ise x1=4.25 x2=4.50 ... xn+1=xn + h
		double *temp;
		//*x = xS;
		temp = x; //temp pointer'ý x'in baþlangýç adresini kaybetmemek için kullandým
		
		for(int i = 0; xS!=xE ;i++)
		{
			*x=xS; //var olan xS deðerini x'in anlýk dizi elemanýna aktarýrýr
			xS += h; //xn+1 = xn + h;
			x++;//bir sonraki dizi elemanýna gider
			x = (double *)malloc(sizeof(double));
		}
		x = temp; // x adresi baþa döndü
		x0 = x[0];
		double F1 = func(x0,y0);
		cout << "F1 : " << F1 << endl;
		double F2 = func(x0 + (h/2),y0 + (h/2)*F1);
		cout << "F2 : " << F2 << endl;
		cout << "F2x : " << x0 + (h/2) << endl;
		cout << "F2y : " << y0 + (h/2)*F1 << endl;
		double F3 = func(x0 + (h/2),y0 + (h/2)*F2);
		cout << "F3 : " << F3 << endl;
		cout << "F3x : " << x0 + (h/2) << endl;
		cout << "F3y : " << y0 + (h/2)*F2 << endl;
		double F4 = func(x0 + h,y0 + h*F3);
		cout << "F4 : " << F4 << endl;
		cout << "F4x : " << x0 + h << endl;
		cout << "F4y : " << y0 + h*F3 << endl;
		double yx = y0 + (h/6)*(F1 + 2*F2 + 2*F3 + F4);
		return yx;
	}
};

int main()
{
	//RK4
	RungeKutta4 * met = new RungeKutta4();
	cout << met->RK4(0.0,2.0,0.25,1.0) << endl;
	system("pause");
}