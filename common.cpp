#include "common.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int getNumber(int min, int max){
       string line;
       getline(cin, line);

       const char *pnum = line.c_str();
       char *endptr;
       int num = strtol(pnum, &endptr, 10);

       if (line.size() == 0){
	       cout << endl;
	       cout << "Error. You must enter a positive integer," << endl;
	       return -1;
       }
       if (line.size() + pnum != endptr){
	       cout << endl;
	       cout << "Error. You must enter a positive integer." << endl;
	       return -1;
       }
       if (num > max){
	      cout << endl;
	      cout << "Error. This number can't be more than " << max << endl;
	      return -1;
       }
       if (num < min){
	       cout << endl;
	       cout << "Error. This number can't be less than " << min << endl;
	       return -1;
       }
       return num;
}

void slow_print(string s, int delay){
  for(size_t i = 0; i < s.size(); ++i){
    cout << s[i];
    fflush(stdout);
    usleep(delay);
  }
  cout << endl;
 }
