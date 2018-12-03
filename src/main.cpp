#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>

#include <pistache/endpoint.h>
#include <pistache/net.h>
#include <pqxx/pqxx>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "_PostgreSQL.h"
#include "_error.h"
#include "_log.h"
#include "_CSVWriter.h"
#include "_datetime.h"
#include "product.h"



int main(int argc, char const *argv[])
{
	std::cout<<"Insomnai version .013. Check Logfile."<<std::endl;
	try
	{		
		/*
    pqxx::result R = Product::getProducts();
    CSVWriter writer("products.csv");
    writer.addData(R);
    pqxx::result R2 = Product::getProduct(1);
    writer.addData(R2);
		//Product::addProduct(32, "m1911", 720.5, weekstart, weekstart, "{book}");
		*/
	}
	catch(const _error& e)
	{
    LOG_ERROR << e.what();
		return 1;
	}
	catch(...)
	{
    LOG_ERROR << "Error: unknown exception";
		return 2;
	}
	return 0;
}
