/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 12:38:17 by ncolliau         ###   ########.fr       */
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
}

			Ncurses::~Ncurses(void)
{
	endwin();
}

void		Ncurses::displayModule(HostUserNames * module) const
{
	mvhline(1, 1, '=', this->_width / 2 - 2);
	this->displayData(1, " Host / User Info ", "");
	this->displayData(1, "Hostname : ", module->getHostname());
	this->displayData(2, "Username : ", module->getUsername());
}

void		Ncurses::displayModule(OSInfo * module) const
{
	mvhline(4, 1, '=', this->_width / 2 - 2);
	this->displayData(4, " OS Info ", "");
	this->displayData(6, "Sys. name : ", module->getSysname());
	this->displayData(7, "Node name : ", module->getNodename());
	this->displayData(8, "Sys. release : ", module->getRelease());
	this->displayData(9, "Sys. version : ", module->getVersion());
	this->displayData(10, "Identifier : ", module->getMachine());
}

void		Ncurses::displayModule(CPUInfo * module) const
{
	mvhline(12, 1, '=', this->_width / 2 - 2);
	this->displayData(12, " CPU Info ", "");
	this->displayData(14, "Model : ", module->getModel());
	this->displayData(15, "Clock speed : ", module->getClockSpeed());
	this->displayData(16, "Nb cores : ", module->getNbCores());
}

void		Ncurses::displayModule(Time * module) const
{
	this->displayData(this->_height / 2 + 1, "Date : ", module->getDate());
	this->displayData(this->_height / 2 + 1, "Time : ", module->getTime());
}

void		Ncurses::displayModule(RAMInfo * module) const
{
	mvprintw(this->_height / 2 + 5, 1, "======= Ressources ======");
	mvprintw(this->_height / 2 + 6, 1, "Max. RAM : %lld", module->getRamMax());
	mvprintw(this->_height / 2 + 7, 1, "Used RAM : %lld", module->getRamUsed());
	mvprintw(this->_height / 2 + 8, 1, "Free RAM : %lld", module->getRamFree());

	// std::stringstream ss;
	// ss << "RAM Usage: ";
	// int p1 = module->getRamPercent() / 10;
	// int p2 = p1;
	// ss << "[";
	// while (p1 > 0)
	// { ss << "=="; --p1; }
	// ss << ">";
	// while (p2 < 10)
	// { ss << "  "; ++p2; }
	// ss << "] " << module->getRamPercent() << " %% " \
	// 	<< "(" << module->getRamUsed() << " MB / " << module->getRamMax() << " MB)";

	// this->print(ss.str());
}

void		Ncurses::displayModule(CPUUsage * module) const
{
	(void)module;
	// move(this->_h / 2 + 9, this->_w / 4 + 3);
	// this->_y = this->_h / 2 + 9;
	// this->_x = this->_w / 4 + 3;

	// module->getCpuPercent();

	// std::stringstream ss;
	// ss << "CPU Usage: ";
	// int p = static_cast<int>((module->getCpuP()[0] + module->getCpuP()[1] + module->getCpuP()[2] + module->getCpuP()[3]) / 4);
	// int p1 = p / 10;
	// int p2 = p1;
	// ss << "[";
	// while (p1 > 0)
	// { ss << "=="; --p1; }
	// ss << ">";
	// while (p2 < 10)
	// { ss << "  "; ++p2; }
	// ss << "] " << p << " %% ";

	// this->print(ss.str());

}

void		Ncurses::displayModule(NetworkUsage * module) const
{
	(void)module;
}

void		Ncurses::displayUI(void)
{
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	getmaxyx(stdscr, this->_height, this->_width);
	border(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	mvhline(this->_height / 2, 0, ' ', this->_width);
	mvvline(1, this->_width / 2, ' ', this->_height / 2);
	mvvline(1, this->_width / 2 - 1, ' ', this->_height / 2);
	attroff(COLOR_PAIR(1));
}
