/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 09:53:06 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Monitor.class.hpp>
#include <HostUserNames.class.hpp>
#include <OSInfo.class.hpp>
#include <CPUInfo.class.hpp>
#include <Time.class.hpp>
#include <RAMInfo.class.hpp>

			Monitor::Monitor(std::string display_mode) : \
								_display_mode(display_mode), _ncurses(*(new Ncurses))
{
	this->_hostusernames = new HostUserNames();
	this->_os_info = new OSInfo();
	this->_time_info = new Time();
	this->_cpu_info = new CPUInfo();
	this->_ram_info = new RAMInfo();
}

			Monitor::~Monitor(void)
{
	delete this->_hostusernames;
	delete this->_os_info;
	delete this->_time_info;
	delete this->_cpu_info;
	delete this->_ram_info;
}

void		Monitor::display(void)
{
	clear();
	this->displayNcurses();
	refresh();
	sleep(1);
}

void		Monitor::displayNcurses(void)
{
	this->_ncurses.displayUI();
	this->_ncurses.displayModule(this->_hostusernames);
	this->_ncurses.displayModule(this->_os_info);
	this->_ncurses.displayModule(this->_cpu_info);
	this->_ncurses.displayModule(this->_time_info);
	this->_ncurses.displayModule(this->_ram_info);
	this->_ncurses.displayModule();
}
