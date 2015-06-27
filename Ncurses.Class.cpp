/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 20:37:46 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.Class.hpp"
#include "HostUserNames.Class.hpp"
#include "OSInfo.Class.hpp"
#include "CPUInfo.Class.hpp"
#include "Time.Class.hpp"

						Ncurses::Ncurses(void)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	//start_color();
	//init_pair(1, COLOR_WHITE, COLOR_BLACK);
	//init_pair(2, COLOR_BLACK, COLOR_RED);
}

						Ncurses::~Ncurses(void)
{
	endwin();
}

void					Ncurses::displayModule(HostUserNames * module) const
{
	this->displayUI("HostUserNames");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "hostname: " << module->getHostname() << std::endl \
		<< std::setw(20) << std::left << "username: " << module->getUsername() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void					Ncurses::displayModule(OSInfo * module) const
{
	this->displayUI("OSInfo");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "system name: " << module->getOSInfo().sysname << std::endl \
		<< std::setw(20) << std::left << "node name: " << module->getOSInfo().nodename << std::endl \
		<< std::setw(20) << std::left << "system release: " << module->getOSInfo().release << std::endl \
		<< std::setw(20) << std::left << "system version: " << module->getOSInfo().version << std::endl \
		<< std::setw(20) << std::left << "identifier: " << module->getOSInfo().machine << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void					Ncurses::displayModule(Time * module) const
{
	this->displayUI("TimeDate");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "date: " << module->getDate() << std::endl \
		<< std::setw(20) << std::left << "time: " << module->getTime() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void					Ncurses::displayModule(CPUInfo * module) const
{
	this->displayUI("CPUInfo");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "model: " << module->getModel() << std::endl \
		<< std::setw(20) << std::left << "clockspeed: " << module->getClockSpeed() << std::endl \
		<< std::setw(20) << std::left << "nbCores: " << module->getNbCores() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void					Ncurses::displayUI(std::string str) const
{
	std::stringstream ss;
	ss << std::endl << "========= " << str << " ============" << std::endl;
	this->print(ss.str());
}

void					Ncurses::print(std::string str) const
{
	printw(str.c_str());
}

// void OSInfo::displayNcurses(void) const
// {
// 	mvprintw(2, 0, "OS info");
// 	mvprintw(3, 0, "System name: %s", this->_os_info.sysname);
// 	mvprintw(4, 0, "Node name: %s", this->_os_info.nodename);
// 	mvprintw(5, 0, "System release: %s", this->_os_info.release);
// 	mvprintw(6, 0, "System version: %s", this->_os_info.version);
// 	mvprintw(7, 0, "Hardware identifier: %s", this->_os_info.machine);
// 	return;
// }
