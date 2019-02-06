#ifndef _AQUARIUS_H_
#define _AQUARIUS_H_
#include <iostream>
#include <fstream>

class Aquarius{
  public:
    int CODE;
    char DATE[10];
    double PH;
    double SALINITY;
    double NITRATES;
    double NITRITES;
    double AMMONUIM;
    int STATUS;
};
#endif
