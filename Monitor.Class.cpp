/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 13:32:34 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Monitor.class.hpp>
#include <HostUserNames.class.hpp>
#include <OSInfo.class.hpp>
#include <CPUInfo.class.hpp>
#include <Time.class.hpp>
#include <RAMInfo.class.hpp>
#include <CPUUsage.class.hpp>
#include <NetworkUsage.class.hpp>

			Monitor::Monitor(std::string display_mode) : \
								_display_mode(display_mode), _ncurses(*(new Ncurses))
{
	this->_hostusernames = new HostUserNames();
	this->_os_info = new OSInfo();
	this->_time_info = new Time();
	this->_cpu_info = new CPUInfo();
	this->_ram_info = new RAMInfo();
	this->_cpu_usage = new CPUUsage();
	this->_network_usage = new NetworkUsage();
}

			Monitor::~Monitor(void)
{
	delete this->_hostusernames;
	delete this->_os_info;
	delete this->_time_info;
	delete this->_cpu_info;
	delete this->_ram_info;
	delete this->_cpu_usage;
	delete this->_network_usage;
}

void		Monitor::display(void)
{
	clear();
	this->displayNcurses();
	refresh();
	usleep(100000);
}

void		Monitor::displayNcurses(void)
{
	this->_ncurses.displayUI();
	this->_ncurses.displayModule(this->_hostusernames);
	this->_ncurses.displayModule(this->_os_info);
	this->_ncurses.displayModule(this->_cpu_info);
	this->_ncurses.displayModule(this->_time_info);
	this->_ncurses.displayModule(this->_ram_info);
	this->_ncurses.displayModule(this->_cpu_usage);
	this->_ncurses.displayModule(this->_network_usage);
}
