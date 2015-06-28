/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:08:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 17:39:47 by mgouault         ###   ########.fr       */
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

				Monitor::Monitor(std::string display_mode, int ac, char **av) : \
					_display_mode(display_mode), _ncurses(*(new Ncurses)), _qtdisplay(*(new QtDisplay))
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

void		Monitor::ProgramLoop(void)
{
	int key;

	while ( ( key = getch() ) != 27 )
	{
		if (key == 10) { this->_ncurses.change_color(); }
		clear();
		// this->displayNcurses();
		// this->displayQt();
		// mvprintw(48, 1, "%d", key);
		refresh();
		usleep(100000);
	}
	endwin();
}

void			Monitor::displayNcurses(void)
{
	if (this->_ncurses.displayUI() == false)
		return;
	this->_ncurses.displayModule(this->_hostusernames);
	this->_ncurses.displayModule(this->_os_info);
	this->_ncurses.displayModule(this->_cpu_info);
	this->_ncurses.displayModule(this->_time_info);
	this->_ncurses.displayModule(this->_ram_info);
	this->_ncurses.displayModule(this->_cpu_usage);
	this->_ncurses.displayModule(this->_network_usage);
}
