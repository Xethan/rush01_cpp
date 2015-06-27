/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:03:45 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 18:24:13 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

# include <iostream>
# include <stdexcept>

# include "Ncurses.Class.hpp"
# include "HostUserNames.Class.hpp"
# include "OSInfo.Class.hpp"
# include "Time.Class.hpp"
# include "CPUInfo.Class.hpp"
# include "RAMInfo.Class.hpp"

class Monitor
{

public :

	Monitor(std::string display_mode = "ncurses");
	~Monitor(void);
	void display_all(void) const;

private:

	Monitor(Monitor const &copy);
	Monitor const &operator=(Monitor const &rhs);

	std::string _display_mode;
	IMonitorModule *_hostusernames;
	IMonitorModule *_os_info;
	IMonitorModule *_time_info;
	IMonitorModule *_cpu_info;
	IMonitorModule *_ram_info;
	Ncurses _ncurses;
	//Class QT;
};

#endif