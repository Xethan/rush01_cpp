#include <limits.h>
#include <unistd.h>

#include <sys/utsname.h>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

std::string		getHostName(void)
{
	char name[_POSIX_HOST_NAME_MAX + 1];
	if (gethostname(name, _POSIX_HOST_NAME_MAX) == -1)
		return "gethostname error";

	std::string ret = name;
	return ret;
}

std::string		getUserName(void)
{
	char * name;
	if (!(name = getlogin()))
		return "getlogin error";

	std::string ret = name;
	return ret;
}

std::string		getOSInfo(void)
{
	struct utsname buf;
	if (uname(&buf) == -1)
		return "uname error";

	std::stringstream ss;
	ss << "system name: " << buf.sysname << std::endl \
		<< "node name: " << buf.nodename << std::endl \
		<< "system release: " << buf.release << std::endl \
		<< "system version: " << buf.version << std::endl \
		<< "hardware identifier: " << buf.machine;
	std::string ret = ss.str();
	return ret;
}

std::string		getDate(void)
{
	std::time_t t = std::time(0);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%d/%m/%y");
	std::string ret = ss.str();
	return ret;
}
//		http://en.cppreference.com/w/cpp/io/manip/put_time
std::string		getTime(void)
{
	std::time_t t = std::time(0);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%T");
	std::string ret = ss.str();
	return ret;
}

int				main(void)
{
	std::cout << "hostname: " << getHostName() << std::endl;
	std::cout << "username: " << getUserName() << std::endl << std::endl;

	std::cout << "-- OS info --" << std::endl << getOSInfo() << std::endl << std::endl;

	std::cout << "date: " << getDate() << std::endl;
	std::cout << "time: " << getTime() << std::endl << std::endl;

	return (0);
}
