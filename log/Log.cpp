/**
 * @File Name: Log.cpp
 * @brief : 日志类
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-12-08
 * 
 */
#include "Log.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/DailyRollingFileAppender.hh>
#include <log4cpp/Priority.hh>

static const char* const dailyFileName = "server_file.log";
Log* Log::log_ = NULL;

Log::Log()
	: catRef_(log4cpp::Category::getRoot())
{
    log4cpp::Appender *appender = new log4cpp::DailyRollingFileAppender("dailyAppender", dailyFileName);
    log4cpp::PatternLayout *patternLayout = new log4cpp::PatternLayout();
    patternLayout->setConversionPattern("%d{%Y-%m-%d %H:%M:%S.%l} %t [%p] %m %n");
    appender->setLayout(patternLayout);

	catRef_.setPriority(log4cpp::Priority::DEBUG);
	catRef_.addAppender(appender);

	catRef_.info("Log create success");
}

Log &Log::getInstance()
{
    if (NULL == log_) {
        log_ = new Log;
    }
    return *log_;
}

void Log::destroy()
{
    if (NULL != log_) {
        log_->catRef_.info("Log destroy");
        log_->catRef_.shutdown();
        delete log_;
    }
}

void Log::setPriority(PriorityLevel pri)
{
    switch (pri)
    {
    case ERROR:
        catRef_.setPriority(log4cpp::Priority::ERROR);
        break;
    case WARN:
        catRef_.setPriority(log4cpp::Priority::WARN);
        break;
    case INFO:
        catRef_.setPriority(log4cpp::Priority::INFO);
        break;
    case DEBUG:
        catRef_.setPriority(log4cpp::Priority::DEBUG);
        break;
    default:
        catRef_.setPriority(log4cpp::Priority::DEBUG);
        break;
    }
}

void Log::error(const char *msg)
{
    catRef_.error(msg);
}

void Log::warn(const char *msg)
{
    catRef_.warn(msg);
}

void Log::info(const char *msg)
{
    catRef_.info(msg);
}

void Log::debug(const char *msg)
{
    catRef_.debug(msg);
}
