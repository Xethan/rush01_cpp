/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 20:13:31 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 09:52:28 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include <iostream>
# include <stdexcept>

# include <Ncurses.class.hpp>

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;

class Monitor
{
private:
	std::string	_display_mode;
	Ncurses & 	_ncurses;
	//Qt const &

	HostUserNames * _hostusernames;
	OSInfo *	_os_info;
	Time *		_time_info;
	CPUInfo *	_cpu_info;
	RAMInfo *	_ram_info;
				Monitor(Monitor const &copy);
	Monitor const & operator=(Monitor const &rhs);

public:
				Monitor(std::string display_mode = "ncurses");
				~Monitor(void);
	void		display(void);
	void		displayNcurses(void);
};

#endif
