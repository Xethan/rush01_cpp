/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 20:13:31 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/27 20:18:23 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include <iostream>
# include <stdexcept>

# include "Ncurses.Class.hpp"

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;

class Monitor
{
private:
						Monitor(Monitor const &copy);
	Monitor const &		operator=(Monitor const &rhs);

	std::string			_display_mode;
	Ncurses const &		_ncurses;
	//Qt const &

	HostUserNames *		_hostusernames;
	OSInfo *			_os_info;
	Time *				_time_info;
	CPUInfo *			_cpu_info;
	RAMInfo *			_ram_info;

public:
						Monitor(std::string display_mode = "ncurses");
						~Monitor(void);
	void				display(void) const;
	void				displayNcurses(void) const;
};

#endif
