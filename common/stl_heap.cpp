#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
   int a[ 10 ] = { 3, 100, 52, 77, 22, 31, 1, 98, 13, 40 };
   std::vector< int > v( a, a + 10 ); // copy of a
   std::vector< int > v2;
   std::ostream_iterator< int > output( cout, " " );

   std::copy( v.begin(), v.end(), output );
   std::make_heap( v.begin(), v.end() );
   std::sort_heap( v.begin(), v.end() );
   cout << "\n\n";
   std::copy( v.begin(), v.end(), output );


   cout << endl;
   return 0;
}