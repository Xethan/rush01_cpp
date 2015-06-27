/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 22:05:21 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.Class.hpp"
#include "HostUserNames.Class.hpp"
#include "OSInfo.Class.hpp"
#include "CPUInfo.Class.hpp"
#include "RAMInfo.Class.hpp"
#include "Time.Class.hpp"

			Ncurses::Ncurses(void)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
}

			Ncurses::~Ncurses(void)
{
	endwin();
}

void		Ncurses::displayModule(HostUserNames * module) const
{
	this->displayUI("HostUserNames");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "hostname: " << module->getHostname() << std::endl \
		<< std::setw(20) << std::left << "username: " << module->getUsername() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(OSInfo * module) const
{
	this->displayUI("OSInfo");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "system name: " << module->getSysname() << std::endl \
		<< std::setw(20) << std::left << "node name: " << module->getNodename() << std::endl \
		<< std::setw(20) << std::left << "system release: " << module->getRelease() << std::endl \
		<< std::setw(20) << std::left << "system version: " << module->getVersion() << std::endl \
		<< std::setw(20) << std::left << "identifier: " << module->getMachine() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(Time * module) const
{
	this->displayUI("TimeDate");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "date: " << module->getDate() << std::endl \
		<< std::setw(20) << std::left << "time: " << module->getTime() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(CPUInfo * module) const
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

void		Ncurses::displayModule(RAMInfo * module) const
{
	this->displayUI("RAMInfo");

	std::stringstream ss;
	ss << std::setw(20) << std::left << "ramMax: " << module->getRamMax() << std::endl \
		<< std::setw(20) << std::left << "ramUsed: " << module->getRamUsed() << std::endl \
		<< std::setw(20) << std::left << "ramFree: " << module->getRamFree() << std::endl \
		<< std::setw(20) << std::left << "ramPercent: " << module->getRamPercent() << " %%" << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayUI(std::string str) const
{
	std::stringstream ss;
	ss << std::endl << "========= " << str << " ============" << std::endl;
	this->print(ss.str());
}

void		Ncurses::print(std::string str) const
{
	printw(str.c_str());
}
