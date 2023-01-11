/* time example */
#include <iostream>
using namespace std;
#include <time.h> /* time_t, struct tm, difftime, time, mktime */

int main() {
  time_t timer;

  time(&timer); /* get current time; same as: timer = time(NULL)  */

  cout << "\n";

  cout << "\n";

  cout << ctime(&timer);

  return 0;
}