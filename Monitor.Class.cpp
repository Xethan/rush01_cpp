/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 22:02:10 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.Class.hpp"
#include "HostUserNames.Class.hpp"
#include "OSInfo.Class.hpp"
#include "CPUInfo.Class.hpp"
#include "Time.Class.hpp"
#include "RAMInfo.Class.hpp"

							Monitor::Monitor(std::string display_mode) : \
								_display_mode(display_mode), _ncurses(*(new Ncurses))
{
	this->_hostusernames = new HostUserNames();
	this->_os_info = new OSInfo();
	this->_time_info = new Time();
	this->_cpu_info = new CPUInfo();
	this->_ram_info = new RAMInfo();
	return;
}

							Monitor::~Monitor(void)
{
	delete this->_hostusernames;
	delete this->_os_info;
	delete this->_time_info;
	delete this->_cpu_info;
	delete this->_ram_info;
	return;
}

void						Monitor::display(void) const
{
	clear();
	this->displayNcurses();
	refresh();
	usleep(25000);
}

void						Monitor::displayNcurses(void) const
{
	this->_ncurses.displayModule(this->_hostusernames);
	this->_ncurses.displayModule(this->_os_info);
	this->_ncurses.displayModule(this->_cpu_info);
	this->_ncurses.displayModule(this->_time_info);
	this->_ncurses.displayModule(this->_ram_info);
}
