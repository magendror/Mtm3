#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace mtm {
    class Exception : public std::exception {};
    class NegativeDays : public Exception {};
    class InvalidDate : public Exception {};
}

#endif
