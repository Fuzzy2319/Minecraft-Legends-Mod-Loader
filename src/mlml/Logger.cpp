#include "mlml/Logger.hpp"
using namespace std;

namespace mlml
{
    bool Logger::log(LogLevel level, wstring message)
    {
        FILE *logFile = fopen("./mlml.log", "a");

        if (logFile == NULL)
        {
            return false;
        }

        time_t t = time(nullptr);
        tm tm = *localtime(&t);
        ostringstream oss;
        oss << put_time(&tm, "[%d/%m/%Y %H:%M:%S] ");
        string time = oss.str();

        wstring severity;

        switch (level)
        {
        case LogLevel::Debug:
            severity = L"Debug";
            break;
        case LogLevel::Info:
            severity = L"Info";
            break;
        case LogLevel::Warning:
            severity = L"Warning";
            break;
        case LogLevel::Error:
            severity = L"Error";
            break;
        }

        severity += L" : ";

        fputs(time.c_str(), logFile);
        fputws(severity.c_str(), logFile);
        fputws(message.c_str(), logFile);
        fputws(L"\n", logFile);

        fclose(logFile);

        return true;
    }
}
