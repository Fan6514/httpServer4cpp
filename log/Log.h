/**
 * @File Name: Log.h
 * @brief : 日志类
 * @Author : Fan6514 (lvfan6514@163.com)
 * @Version : 1.0
 * @Creat Date : 2022-12-08
 * 
 */
#ifndef LOG_H
#define LOG_H

#include <log4cpp/Category.hh>

typedef enum
{
    EMERG  = 0,     // emergency
    FATAL  = 0,     // fatal
    ALERT  = 100,   // alert
    CRIT   = 200,   // critical
    ERROR  = 300,   // error
    WARN   = 400,   // wanning
    NOTICE = 500,   // notice
    INFO   = 600,   // infomation
    DEBUG  = 700,   // debug
    NOTSET = 800   
} PriorityLevel;

class Log
{
public:
    Log();

    static Log& getInstance();
    static void destroy();

    void setPriority(PriorityLevel pri);
    void error(const char* msg);
    void warn(const char* msg);
    void info(const char* msg);
    void debug(const char* msg);
    
private:
    static Log *log_;
    log4cpp::Category &catRef_;
};

inline std::string int2string(int line)
{
    std::ostringstream os;
    os << line;
    return os.str();
}

#define postfix(msg)  std::string(msg).append(" ##")\
    .append(__FILE__).append(":").append(__func__)\
    .append(":").append(int2string(__LINE__))\
    .append("##").c_str()

#define LOG_ERROR(msg) Log::getInstance().error(msg) 
#define LOG_WARN(msg)  Log::getInstance().warn(msg)
#define LOG_INFO(msg)  Log::getInstance().info(msg)
#define LOG_DEBUG(msg) Log::getInstance().debug(msg)
#define LOG_ERROR_FILE(msg) Log::getInstance().error(postfix(msg)) 
#define LOG_WARN_FILE(msg)  Log::getInstance().warn(postfix(msg))
#define LOG_INFO_FILE(msg)  Log::getInstance().info(postfix(msg))
#define LOG_DEBUG_FILE(msg) Log::getInstance().debug(postfix(msg))

#endif