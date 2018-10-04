%module mikkola
%{
#include "mikkola.h"
%}

%include "std_vector.i"

namespace std {
   %template(DoubleVector) vector<double>;
}


%include "mikkola.h"
