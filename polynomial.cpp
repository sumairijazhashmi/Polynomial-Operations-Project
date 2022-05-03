//     Copyright (C) 2020  Sumair Ijaz Hashmi - LUMS roll number: 24100004

//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.

//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.

//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include<iostream>
#include<cmath>
using namespace std;

class Polynomial
{
	public:
		Polynomial(); //default constructor
		Polynomial(const Polynomial &poly); //copy constructor
		Polynomial(int d, double array[]); //parameterized constructor
		~Polynomial(); //destructor
		void operator=(const Polynomial &poly); //overload =
		
		friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2); //p1 + p2
		friend Polynomial operator+(double c, const Polynomial &p); //c + p
		friend Polynomial operator+(const Polynomial &p, double c ); //p + c
		
		friend Polynomial operator-(const Polynomial &p1, const Polynomial &p2); //p1 - p2
		friend Polynomial operator-(double c, const Polynomial &p); //c - p
		friend Polynomial operator-(const Polynomial &p, double c ); //p - c
		
		friend Polynomial operator*(const Polynomial &p1, const Polynomial &p2); //p1 * p2
		friend Polynomial operator*(double c, const Polynomial &p); //c * p
		friend Polynomial operator*(const Polynomial &p, double c ); //p * c
		
		double extract_coeff(int exponent);
		double evaluate_polynomial(double value);
		
	private:
		double *coeffs;
		int degree;		
};

//default constructor
Polynomial::Polynomial()
{
	degree = 3;
	coeffs = new double[degree];
	for (int i=0; i<degree; i++)
	{
		coeffs[i] = 0;
	}
}

//parameterized constructor
Polynomial::Polynomial(int d, double array[])
{
	degree = d;
	coeffs = new double[degree];
	for (int i=0; i< degree; i++)
	{
		coeffs[i] = array[i];
	}
}

//copy constructor
Polynomial::Polynomial(const Polynomial &poly)
{
	degree = poly.degree;
	coeffs = new double[degree];
	for(int i=0; i<degree; i++)
	{
		coeffs[i] = poly.coeffs[i];
	}
}

//destructor
Polynomial::~Polynomial()
{
	delete [] coeffs;
}

//overload =
void Polynomial::operator=(const Polynomial &poly)
{
	this->degree = poly.degree;
	coeffs = new double[degree];
	for(int i=0; i<degree; i++)
	{
		coeffs[i] = poly.coeffs[i];
	}
}

//p1+p2
Polynomial operator +(const Polynomial &p1, const Polynomial &p2)
{
/*
	Polynomial temp;
	if (p1.degree >= p2.degree)
	{
		temp.degree = p1.degree;
	}
	else
	{
		temp.degree = p2.degree;
	}
	temp.coeffs = new double[temp.degree];
	if (p1.degree < p2.degree)
	{
		for (int i=0; i<p1.degree; i++)
		{
			temp.coeffs[i] = p1.coeffs[i] + p2.coeffs[i];
		}
		for (int i=p1.degree; i<temp.degree;i++)
		{
			temp.coeffs[i] = p2.coeffs[i];
		}
	}
	if (p2.degree < p1.degree)
	{
		for (int i=0; i<p2.degree; i++)
		{
			temp.coeffs[i] = p1.coeffs[i] + p2.coeffs[i];
		}
		for (int i=p2.degree; i<temp.degree;i++)
		{
			temp.coeffs[i] = p1.coeffs[i];
		}
	}
	if (p2.degree == p1.degree)
	{
		for (int i=0; i<temp.degree; i++)
		{
			temp.coeffs[i] = p1.coeffs[i] + p2.coeffs[i];
		}
	}
	return temp;
*/
Polynomial temp;
	if (p1.degree >= p2.degree)
	{
		temp = p1;
		for (int i=0; i<p2.degree; i++)
		{
			temp.coeffs[i] = p1.coeffs[i] + p2.coeffs[i];
		}
	}
	else
	{
		temp = p2;
		for (int i=0; i<p1.degree; i++)
		{
			temp.coeffs[i] = p1.coeffs[i] + p2.coeffs[i];
		}
	}
	
	return temp;
}

//c + p
Polynomial operator +(double c, const Polynomial &p)
{
	Polynomial temp;
	temp = p;
	temp.coeffs[0] += c;
	return temp;
}

//p + c
Polynomial operator +(const Polynomial &p, double c)
{
	Polynomial temp;
	temp = p;
	temp.coeffs[0] += c;
	return temp;
}

//p1-p2
Polynomial operator -(const Polynomial &p1, const Polynomial &p2)
{
	Polynomial temp;
	temp = p1 + (-1*p2);
	return temp;
}

//c - p
Polynomial operator -(double c, const Polynomial &p)
{
	Polynomial temp;
	temp = -1*p;
	temp.coeffs[0] += c;
	return temp;
}

//p - c
Polynomial operator -(const Polynomial &p, double c)
{
	Polynomial temp;
	temp = p;
	temp.coeffs[0] -= c;
	return temp;
}

//p*p
Polynomial operator*(const Polynomial &p1, const Polynomial &p2) //p1 * p2
{
	Polynomial temp;
	if (p1.degree >= p2.degree)
	{
		temp = p1;
		for (int i=0; i<temp.degree; i++)
		{
			temp.coeffs[i] *= p2.coeffs[i];	
		}
	}
	else
	{
		temp = p2;
		for (int i=0; i<temp.degree; i++)
		{
			temp.coeffs[i] *= p1.coeffs[i];	
		}
	}
	return temp;
}

Polynomial operator*(double c, const Polynomial &p)  //c * p
{
	Polynomial temp;
	temp = p;
	for (int i=0; i< temp.degree; i++)
	{
		temp.coeffs[i] *= c;
	}
	return temp;
}

Polynomial operator*(const Polynomial &p, double c)  //p * c
{
	Polynomial temp;
	temp = p;
	for (int i=0; i< temp.degree; i++)
	{
		temp.coeffs[i] *= c;
	}
	return temp;
}

double Polynomial::extract_coeff(int exponent)
{
	return coeffs[exponent];
}
double Polynomial::evaluate_polynomial(double value)
{
	double result = 0;
	for(int i=0; i<degree; i++)
	{	
		result += coeffs[i]*pow(value,i);
	}
	return result;
}

//int* array_ptr = new int[size];

int main()
{
	double a[] = {2,3,5,3,1};
	double b[] = {4,6,7};
	
	Polynomial poly1(5,a);
	Polynomial poly2(3,b);
	
	Polynomial poly3;
	
	poly3 = poly1-poly1;
	
	double coeff = poly3.extract_coeff(4);
	
	cout << coeff << endl;
	
	
	return 0;
}
