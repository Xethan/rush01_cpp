/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:39:22 by mgouault         ###   ########.fr       */
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
	ss << std::setw(14) << std::left << "Hostname: " << module->getHostname() << std::endl \
		<< std::setw(14) << std::left << "Username: " << module->getUsername() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(OSInfo * module) const
{
	this->displayUI("OSInfo");

	std::stringstream ss;
	ss << std::setw(14) << std::left << "Sys. name: " << module->getSysname() << std::endl \
		<< std::setw(14) << std::left << "Node name: " << module->getNodename() << std::endl \
		<< std::setw(14) << std::left << "Sys. release: " << module->getRelease() << std::endl \
		<< std::setw(14) << std::left << "Sys. version: " << module->getVersion() << std::endl \
		<< std::setw(14) << std::left << "Identifier: " << module->getMachine() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(CPUInfo * module) const
{
	this->displayUI("CPUInfo");

	std::stringstream ss;
	ss << std::setw(14) << std::left << "Model: " << module->getModel() << std::endl \
		<< std::setw(14) << std::left << "Clock speed: " << module->getClockSpeed() << std::endl \
		<< std::setw(14) << std::left << "Nb cores: " << module->getNbCores() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(Time * module) const
{
	this->displayUI("TimeDate");

	std::stringstream ss;
	ss << std::setw(14) << std::left << "Date: " << module->getDate() << std::endl \
		<< std::setw(14) << std::left << "Time: " << module->getTime() << std::endl;

	std::string str;
	str = ss.str();
	this->print(str);
}

void		Ncurses::displayModule(RAMInfo * module) const
{
	this->displayUI("RAMInfo");

	std::stringstream ss;
	ss << std::setw(14) << std::left << "Maximum: " << module->getRamMax() << " MB" << std::endl \
		<< std::setw(14) << std::left << "Used: " << module->getRamUsed() << " MB" << std::endl \
		<< std::setw(14) << std::left << "Free: " << module->getRamFree() << " MB" << std::endl \
		<< std::setw(14) << std::left << "Usage: ";

	int p1 = module->getRamPercent() / 10;
	int p2 = p1;
	ss << "[";
	while (p1 > 0)
	{ ss << "=="; --p1; }
	ss << ">";
	while (p2 < 10)
	{ ss << "  "; ++p2; }
	ss << "] " << module->getRamPercent() << " %% " \
		<< "(" << module->getRamUsed() << " / " << module->getRamMax() << ")" <<std::endl;

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
