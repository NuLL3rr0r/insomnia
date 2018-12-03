#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <pqxx/pqxx>
#include "product.h"
#include "_error.h"
#include "_log.h"
#include "_PostgreSQL.h"

Product::Product()
{
}
Product::~Product()
{
}
void Product::setData()
{
}
void Product::print()
{
}
pqxx::result Product::getProducts()
{
	pqxx::connection C(_PostgreSQL::connection_string());
	try {
		if (C.is_open()) {
			 LOG_INFO << "Opened database successfully: " << C.dbname();
		} else {
			 LOG_ERROR << "Can't open database: " << C.dbname();
		}
		C.disconnect ();
	} catch (const _error &e) {
			LOG_ERROR << e.what();
	}
	LOG_INFO << "Connected to database: " << C.dbname();
	pqxx::work W(C);
	pqxx::result R =
		W.exec("SELECT id, title, price, created_at, deleted_at, tags FROM products");
		return R;
}
pqxx::result Product::getProduct(int id)
{
	pqxx::connection C(_PostgreSQL::connection_string());
	try {
		if (C.is_open()) {
			 LOG_INFO << "Opened database successfully: " << C.dbname();
		} else {
			 LOG_ERROR << "Can't open database: " << C.dbname();
		}
		C.disconnect ();
	} catch (const _error &e) {
			LOG_ERROR << e.what();
	}
	LOG_INFO << "Connected to database: " << C.dbname();
	pqxx::work W(C);
  C.prepare("find", "SELECT id, title, price, created_at, deleted_at, tags FROM products where id = $1");
  pqxx::result R = W.prepared("find")(id).exec();
  W.commit();
	return R;
}
void Product::addProduct( int id,
													std::string title,
													float price,
													boost::gregorian::date  created_at,
													boost::gregorian::date  deleted_at,
													std::string tags)
{
	pqxx::connection C(_PostgreSQL::connection_string());
	try {
		if (C.is_open()) {
			 LOG_INFO << "Opened database successfully: " << C.dbname();
		} else {
			 LOG_ERROR << "Can't open database: " << C.dbname();
		}
		C.disconnect ();
	} catch (const _error &e) {
			LOG_ERROR << e.what();
	}
	LOG_INFO << "Connected to database: " << C.dbname();
	pqxx::work W(C);
  /*C.prepare("insert", "INSERT INTO products (id, title, price, created_at, deleted_at, tags) \
	 										 VALUES($1, $2, $3, $4, $5, $6");*/
	C.prepare("insert", "INSERT INTO products \
												(id, title, price) VALUES \
												($1, $2, $3)");
  std::cout << "gholi" << '\n';
	//W.prepared("insert")(id)(title)(price)(created_at)(deleted_at)(tags);
	//std::cout<< W.prepared("insert");
  pqxx::result R = W.prepared("insert")(id)(title)(price).exec();
  W.commit();
}
