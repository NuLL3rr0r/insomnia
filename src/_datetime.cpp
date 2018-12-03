#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "_datetime.h"
#include "_math.h"


void _datetime::init()
{
  // current date/time based on current system
  time_t now = time(0);

  // convert now to string form
  char* dt = ctime(&now);

  // convert now to string form
  std::string strdt = ctime(&now);

  // convert now to tm struct for UTC
  tm *gmtm = gmtime(&now);
  std::string strUTCdt = asctime(gmtm);

  //boost datetime
  boost::gregorian::date weekstart(2002,boost::gregorian::Feb,1);

  std::cout<< "(now)[time_t now = time(0);]: "<< now <<"\n";
  std::cout<< "(dt)[char* dt = ctime(&now);]: "<< dt <<"\n";
  std::cout<< "(strdt)[std::string strdt = ctime(&now);]: "<< strdt <<"\n";
  std::cout<< "(strdt)[std::string strUTCdt = asctime(gmtm);]: "<< strUTCdt <<"\n";
  std::cout<< "(now)[boost::gregorian::date weekstart(2002,Feb,1);]: "<< weekstart <<"\n";
}

void _datetime::sample()
{
  auto start = std::chrono::system_clock::now();
  std::cout << "f(44) = " << _math::fibonacci(44) << '\n';
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
