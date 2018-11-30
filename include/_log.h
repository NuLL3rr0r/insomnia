#ifndef INC_LOG_H
#define INC_LOG_H

/*#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>*/

#include <string>

class _log
{
private:
  int a;
	//boost::log::sources::severity_logger<boost::log::trivial::severity_level> lg;
public:
    _log();
    ~_log();
    void init();
    //static void log(boost::log::trivial::severity_level, std::string);
};
#endif
