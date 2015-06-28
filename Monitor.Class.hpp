/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 20:13:31 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 19:16:40 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include <iostream>
# include <stdexcept>

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;
class CPUUsage;
class NetworkUsage;
class Ncurses;
class QtDisplay;

class Monitor
{
private:
	Ncurses * 	_ncurses;
	QtDisplay *	_qtdisplay;

	HostUserNames * _hostusernames;
	OSInfo *	_os_info;
	Time *		_time_info;
	CPUInfo *	_cpu_info;
	RAMInfo *	_ram_info;
	CPUUsage *	_cpu_usage;
	NetworkUsage * _network_usage;

				Monitor(Monitor const &copy);
	Monitor const & operator=(Monitor const &rhs);

public:
				Monitor(void);
				~Monitor(void);

	void		programLoop(void);
	void		loopNcurses(void);
	void		loopQt(void);
	void		displayNcurses(void);
	void		displayQt(void);

	HostUserNames *		getHostUserNames(void) const;
	OSInfo *			getOSInfo(void) const;
	Time *				getTimeInfo(void) const;
	CPUInfo *			getCPUInfo(void) const;
	RAMInfo *			getRAMInfo(void) const;
	CPUUsage *			getCPUUsage(void) const;
	NetworkUsage *		getNetworkUsage(void) const;
};

#endif
