#include "log.h"

#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>

logger::logger()
{
    boost::log::add_console_log();
    boost::log::add_file_log("iha.log");
}


logger & logger::instance()
{
    static logger lg;
    return lg;
}
