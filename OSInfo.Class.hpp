/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfo.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:38:23 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 21:08:13 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP

# include <sys/utsname.h>
# include <sstream>

# include "IMonitorModule.Class.hpp"

class OSInfo : public IMonitorModule
{

public:

	OSInfo(void);
	~OSInfo(void);
	std::string getSysname(void) const;
	std::string getNodename(void) const;
	std::string getRelease(void) const;
	std::string getVersion(void) const;
	std::string getMachine(void) const;

private:

						OSInfo(OSInfo const &copy);
	OSInfo const &		operator=(OSInfo const &rhs);
	std::string _sysname;
	std::string _nodename;
	std::string _release;
	std::string _version;
	std::string _machine;
};

#endif
