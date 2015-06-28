/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 15:42:28 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Ncurses.class.hpp>
#include <HostUserNames.class.hpp>
#include <OSInfo.class.hpp>
#include <CPUInfo.class.hpp>
#include <Time.class.hpp>
#include <RAMInfo.class.hpp>
#include <CPUUsage.class.hpp>
#include <NetworkUsage.class.hpp>

			Ncurses::Ncurses(void)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
}

			Ncurses::~Ncurses(void)
{
	endwin();
}

void		Ncurses::displayModule(HostUserNames * module)
{
	this->_y = 3;
	mvhline(this->_y, 1, '=', this->_width / 2 - 2);
	this->displayData(1, " Host / User Info ", "");
	this->_y++;
	this->displayData(1, "Hostname : ", module->getHostname());
	this->displayData(1, "Username : ", module->getUsername());
}

void		Ncurses::displayModule(OSInfo * module)
{
	mvhline(++this->_y, 1, '=', this->_width / 2 - 2);
	this->displayData(1, " OS Info ", "");
	this->_y++;
	this->displayData(1, "Sys. name : ", module->getSysname());
	this->displayData(1, "Node name : ", module->getNodename());
	this->displayData(1, "Sys. release : ", module->getRelease());
	this->displayData(1, "Sys. version : ", module->getVersion());
	this->displayData(1, "Identifier : ", module->getMachine());
}

void		Ncurses::displayModule(CPUInfo * module)
{
	mvhline(++this->_y, 1, '=', this->_width / 2 - 2);
	this->displayData(1, " CPU Info ", "");
	this->_y++;
	this->displayData(1, "Model : ", module->getModel());
	this->displayData(1, "Clock speed : ", module->getClockSpeed());
	this->displayData(1, "Nb cores : ", module->getNbCores());
}

void		Ncurses::displayModule(Time * module)
{
	this->_y = 3;
	mvhline(this->_y, this->_width / 2 + 1, '=', this->_width / 2 - 2);
	this->displayData(3, " Time Info ", "");
	this->_y++;
	this->displayData(3, "Date : ", module->getDate());
	this->displayData(3, "Time : ", module->getTime());
}

void		Ncurses::displayModule(RAMInfo * module)
{
	mvhline(++this->_y, this->_width / 2 + 1, '=', this->_width / 2 - 2);
	this->displayData(3, " Ressources ", "");
	this->_y++;
	this->displayData(3, "Max. RAM : ", std::to_string(module->getRamMax()) + " MB");
	this->displayData(3, "Used RAM : ", std::to_string(module->getRamUsed()) + " MB");
	this->displayData(3, "Free RAM : ", std::to_string(module->getRamFree()) + " MB");

	this->_y++;
	this->displayGraphPercent(" RAM Usage : ", module->getRamPercent());
}

void		Ncurses::displayModule(CPUUsage * module)
{
	module->getCpuPercent();

	this->_y += 2;
	for (size_t i = 0; i < module->getCpuP().size(); i++)
	{
		int percent = static_cast<int>(module->getCpuP()[i]);
		this->displayGraphPercent("CPU Core " + std::to_string(i + 1) + " : ", percent);
	}
	int percent = static_cast<int>((module->getCpuP()[0] + module->getCpuP()[1] + module->getCpuP()[2] + module->getCpuP()[3]) / 4);
	this->displayGraphPercent(" CPU Usage : ", percent);

}

void		Ncurses::displayGraphPercent(std::string msg, int percent)
{
	std::string usage(percent / 5, '=');
	usage.insert(0, "[");
	usage += std::string(20 - percent / 5, ' ') + "]";
	if (percent < 10)
		usage.push_back(' ');
	usage += " " + std::to_string(percent) + "%";
	this->displayData(3, msg, usage);
}

void		Ncurses::displayModule(NetworkUsage * module)
{
	(void)module;
}

bool		Ncurses::displayUI(void)
{
	getmaxyx(stdscr, this->_height, this->_width);
	if (this->_height < 50 || this->_width < 100)
	{
		mvprintw(0, 0, "The Window is too small.");
		mvprintw(1, 0, "It must be at least 100x50");
		return (false);
	}
	attron(COLOR_PAIR(1));
	border(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	mvhline(this->_height / 2, 0, ' ', this->_width);
	mvvline(1, this->_width / 2, ' ', this->_height / 2);
	mvvline(1, this->_width / 2 - 1, ' ', this->_height / 2);
	attroff(COLOR_PAIR(1));
	return (true);
}
