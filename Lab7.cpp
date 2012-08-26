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
#include "Array.h"
#include <iostream>
using namespace std;

int main(void)
{
  Array<char> c(3);
  c.setValue(0,'c');
  c.setValue(1,'s');
  c.setValue(2,'c');
  cout << c;

  Array<int> i(3);
  i.setValue(0,1);
  i.setValue(1,2);
  i.setValue(2,5);
  cout << i;

  Array<int> j(3);
  j.setValue(0,10);
  j.setValue(1,20);
  j.setValue(2,50);
  cout << j;

  Array<int> ij;
  ij = i + j;
  cout << ij;

  return 0;
}
