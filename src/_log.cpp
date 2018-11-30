#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include "_log.h"

//namespace logging = boost::log;
//namespace src = boost::log::sources;
//namespace sinks = boost::log::sinks;
//namespace keywords = boost::log::keywords;

_log::_log()
{
	init();
    //boost::log::add_common_attributes();
}
_log::~_log()
{

}
void _log::init()
{
  a = 5;
    //boost::log::add_file_log("sample3.log");
    //boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
}
/*void CustomLog::log(boost::log::trivial::severity_level severity_level, std::string str_message)
{
	BOOST_LOG_SEV(lg, severity_level) << str_message;
}*/
