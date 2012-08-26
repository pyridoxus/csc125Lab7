//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
using namespace std;

template <class T>
class Array
{
	public:
		Array(void);
		Array(int n);
		Array(const Array<T> &a);
		~Array();
		int getSize(void);
		int setValue(int n, T v);
		T *getAddress(void);	// Debugging
		T getValue(int n);
		void operator =(const Array<T> &a);
		friend Array<T> operator +(Array<T> &a, Array<T> &b)
		{
			int c;
			if(a.getSize() < b.getSize()) c = a.getSize();
			else c = b.getSize();
			Array<T> n(c);
			for(int d = 0; d < c; d++) n.setValue(d, a.getValue(d) + b.getValue(d));
			return n;
		}
		friend Array<T> operator +(Array<T> &a, T b)
		{
			Array<T> n(a.getSize());
			for(int d = 0; d < a.getSize(); d++) n.setValue(d, a.getValue(d) + b);
			return n;
		}
		inline friend ostream &operator <<(ostream &output, const Array<T> &a)
		{
			cout << "Array:" << endl;
			cout << "  Size: " << a.n << endl;
			cout << "  Contents: ";
			for(int b = 0; b < a.n; b++) output << a.f[b] << " ";
			cout << endl;
			return output;
		}
	private:
		T *f;
		int n;
};


template <class T>
Array<T>::Array(void)
{
//	cout << "Empty Constructor " << this << endl;	// Debugging
	this->n = 0;
	this->f = 0;
	return;
}

template <class T>
Array<T>::Array(int n)
{
//	cout << "Initialize Constructor " << this << endl;	// Debugging
	this->n = n;
	this->f = new T[n];
	return;
}

template <class T>
Array<T>::Array(const Array &a)
{
//	cout << "Copy Constructor " << this << " from " << &a << endl;	// Debugging
	if(f)	delete[] this->f;
	*this = a;
	return;
}

template <class T>
Array<T>::~Array()
{
//	cout << "Destructor " << this << endl; 	// Debugging
	if(f) delete[] this->f;
	return;
}

template <class T>
int Array<T>::getSize(void)
{
	return this->n;
}

template <class T>
int Array<T>::setValue(int n, T v)
{
	if((n >= 0) && (n < this->n))
	{
		this->f[n] = v;
		return 0;	// index in range
	}
	return 1;	// index out of range
}

template <class T>
T *Array<T>::getAddress(void)
{
	return this->f;	// This is for printing object to cout, and also debugging
}

template <class T>
T Array<T>::getValue(int n)
{
	return this->f[n];
}

template <class T>
void Array<T>::operator =(const Array<T> &a)
{
	int d;
	if(this != &a)	// Don't copy itself
	{
		if(f) delete[] this->f;
		this->n = a.n;
		this->f = new T[this->n];
		for(d = 0; d < this->n; d++) this->f[d] = a.f[d];
	}
	return;
}

#endif /* ARRAY_H_ */
