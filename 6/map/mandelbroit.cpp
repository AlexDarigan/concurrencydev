// Author	: David Darigan (C00263218)
// Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
// Git URL	: https://github.com/AlexDarigan/concurrencydev
/*! \file mandelbroit.cpp
    \brief A file demonstrating mandelbroit patterns using paralleization

*/

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <complex>      /* complex number data type */
#include <time.h>       /* time */
#include <limits>

using namespace std ;

const int ROW=1000;
const int COL=1000;
const int DEPTH=10;

int calc(complex<int> c, int depth){
    int count=0;
    complex<int> z=0;
    for(int i=0;i<depth;++i){
	if (abs(z)>2.0){
            break;
	}
	z=z*z+c;
	count++;
    }
    return count;
}


void mandel( int p[ROW][COL], int depth){
  #pragma omp parallel for collapse(2)	  
  for(int i=0;i<ROW;++i){
        for(int k=0;k<COL;++k){
	  p[i][k]=calc(complex<int>(i,k),depth);
	}
    }
}

int main(void){

  
  int myArray[ROW][COL];
  /* initialize random seed: */
  srand (time(NULL));
  
  clock_t begin = clock();
  mandel(myArray,DEPTH);
  clock_t end = clock();
  double timeSec = (end - begin) / static_cast<double>( CLOCKS_PER_SEC );
  std::cout << timeSec << std::endl;
}


// 
// mandelbroit.cpp ends here
