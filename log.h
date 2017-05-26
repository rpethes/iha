#ifndef LOG_H
#define LOG_H
#include <boost/log/core.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};

namespace src = boost::log::sources;
typedef src::severity_logger<severity_level> typeSeverityLogger ;
class logger
{
protected:
    typeSeverityLogger _slg;
    logger();
public:
    static logger & instance();

    typeSeverityLogger & logSrc()
    {
        return _slg;
    }
};

#define LOG BOOST_LOG_SEV(logger::instance().logSrc(), normal)
#define NOTE BOOST_LOG_SEV(logger::instance().logSrc(), notification)
#define WARNING BOOST_LOG_SEV(logger::instance().logSrc(), warning)
#define ERR BOOST_LOG_SEV(logger::instance().logSrc(), error)
#define CRITICAL BOOST_LOG_SEV(logger::instance().logSrc(), critical)

#endif // LOG_H
