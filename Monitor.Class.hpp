/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 20:13:31 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 17:39:46 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include <iostream>
# include <stdexcept>

# include <Ncurses.class.hpp>
# include <QtDisplay.class.hpp>

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;
class CPUUsage;
class NetworkUsage;

class Monitor
{
private:
	std::string	_display_mode;
	Ncurses & 	_ncurses;
	QtDisplay &	_qtdisplay;

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
				Monitor(std::string display_mode);
				~Monitor(void);
	void		ProgramLoop(void);
	void		displayNcurses(void);
	void		displayQt(void);
};

#endif
