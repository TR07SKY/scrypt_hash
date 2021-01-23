#include "uint256.h"

#include <stdarg.h>

#ifndef WIN32
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif
#include <map>
#include <list>
#include <utility>
#include <vector>
#include <string>

#include <boost/version.hpp>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

typedef long long  int64;
typedef unsigned long long  uint64;

#define BEGIN(a)            ((char*)&(a))
#define END(a)              ((char*)&((&(a))[1]))

std::vector<unsigned char> ParseHex(const char* psz);
std::vector<unsigned char> ParseHex(const std::string& str);
bool IsHex(const std::string& str);
