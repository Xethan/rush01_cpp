/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 20:04:41 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.Class.hpp"
#include "Ncurses.Class.hpp"
#include "HostUserNames.Class.hpp"
#include "OSInfo.Class.hpp"
#include "CPUInfo.Class.hpp"
#include "Time.Class.hpp"

							Monitor::Monitor(std::string display_mode) : \
								_display_mode(display_mode), _ncurses(*(new Ncurses))
{
	this->_os_info = new OSInfo();
	this->_hostusernames = new HostUserNames();
	this->_time_info = new Time();
	this->_cpu_info = new CPUInfo();
}

							Monitor::~Monitor(void)
{
	delete this->_os_info;
	delete this->_hostusernames;
	delete this->_time_info;
	delete this->_cpu_info;
}

void						Monitor::display(void) const
{
	clear();
	this->displayNcurses();
	refresh();
}

void						Monitor::displayNcurses(void) const
{
	this->_ncurses.displayModule(this->_hostusernames);
	this->_ncurses.displayModule(this->_os_info);
	this->_ncurses.displayModule(this->_cpu_info);
	this->_ncurses.displayModule(this->_time_info);
}
