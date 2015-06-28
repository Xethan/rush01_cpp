/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 22:21:05 by mgouault         ###   ########.fr       */
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
#include <Monitor.class.hpp>

			Ncurses::Ncurses(void) : \
				_color(1)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	this->_display[0] = true;
	this->_display[1] = true;
	this->_display[2] = true;
	this->_display[3] = true;
	this->_display[4] = true;
	this->_display[5] = true;
}

			Ncurses::~Ncurses(void) {}

bool		Ncurses::loop(Monitor const & src)
{
	int key;

	while ((key = getch()) != 27)
	{
		if (key == 10)
			this->change_color();
		if (key == 32)
		{
			endwin();
			return (true);
		}
		if (key >= 49 && key <= 54)
			this->_display[key - 49] = (this->_display[key - 49] == true) ? false : true;
		clear();
		this->display(src);
		//mvprintw(48, 1, "%d", key);
		refresh();
		sleep(1);
	}
	endwin();
	return false;
}


void		Ncurses::display(Monitor const & src)
{
	if (this->displayUI() == false)
		return;
	if (this->_display[0])
		this->displayModule(src.getHostUserNames());
	if (this->_display[1])
		this->displayModule(src.getOSInfo());
	if (this->_display[2])
		this->displayModule(src.getCPUInfo());
	if (this->_display[3])
		this->displayModule(src.getTimeInfo());
	if (this->_display[4])
		this->displayModule(src.getRAMInfo());
	if (this->_display[4])
		this->displayModule(src.getCPUUsage());
	if (this->_display[5])
		this->displayModule(src.getNetworkUsage());
}

void		Ncurses::displayModule(HostUserNames * module)
{
	this->_y = 1;
	this->displayTitle(1, "Host / User Info");
	this->displayData(1, "Hostname : ", module->getHostname());
	this->displayData(1, "Username : ", module->getUsername());
}

void		Ncurses::displayModule(OSInfo * module)
{
	this->_y = 6;
	this->displayTitle(1, "OS Info");
	this->displayData(1, "Sys. name : ", module->getSysname());
	this->displayData(1, "Node name : ", module->getNodename());
	this->displayData(1, "Sys. release : ", module->getRelease());
	this->displayData(1, "Sys. version : ", module->getVersion());
	this->displayData(1, "Identifier : ", module->getMachine());
}

void		Ncurses::displayModule(CPUInfo * module)
{
	this->_y = 14;
	this->displayTitle(1, "CPU Info");
	this->displayData(1, "Model : ", module->getModel());
	this->displayData(1, "Clock speed : ", module->getClockSpeed());
	this->displayData(1, "Number Cores : ", module->getNbCores());
}

void		Ncurses::displayModule(Time * module)
{
	this->_y = 1;
	this->displayTitle(3, "Time Info");
	this->displayData(3, "Date : ", module->getDate());
	this->displayData(3, "Time : ", module->getTime());
}

void		Ncurses::displayModule(RAMInfo * module)
{
	this->_y = 6;
	this->displayTitle(3, "Ressources");
	this->displayData(3, "Max. RAM : ", std::to_string(module->getRamMax()) + " MB");
	this->displayData(3, "Used RAM : ", std::to_string(module->getRamUsed()) + " MB");
	this->displayData(3, "Free RAM : ", std::to_string(module->getRamFree()) + " MB");
	this->_y++;
	this->displayGraphPercent("RAM Usage : ", module->getRamPercent());
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
	this->_y++;
	this->displayGraphPercent("CPU Usage : ", percent);

}

void		Ncurses::displayModule(NetworkUsage * module)
{
	this->_y = this->_height / 2 - 1;
	this->displayTitle(2, "Network Usage");
	this->displayData(2, "Packets in : ", module->getNetworkThroughput(NetworkUsage::pktsIn) + " pkts");
	this->displayData(2, "Packets out : ", module->getNetworkThroughput(NetworkUsage::pktsOut) + " pkts");
	this->displayData(2, "Data in : ", module->getNetworkThroughput(NetworkUsage::bytesIn) + " bytes");
	this->displayData(2, "Data out : ", module->getNetworkThroughput(NetworkUsage::bytesOut) + " bytes");
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
	attron(COLOR_PAIR(this->_color));
	border(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	mvhline(2, 0, ' ', this->_width);
	mvhline(this->_height / 2, 0, ' ', this->_width);
	mvvline(2, this->_width / 2, ' ', this->_height / 2 - 2);
	mvvline(2, this->_width / 2 - 1, ' ', this->_height / 2 - 2);
	std::string title("System Monitor by mgouault and ncolliau");
	attroff(COLOR_PAIR(this->_color));
	mvprintw(1, this->_width / 2 - title.size() / 2, title.c_str());
	return (true);
}

void		Ncurses::displayGraphPercent(std::string msg, int percent)
{
	std::string usage(percent / 5, '=');
	usage.insert(0, "[");
	usage += std::string(20 - percent / 5, ' ') + "]";
	if (percent < 10)
		usage.push_back(' ');
	usage += " " + std::to_string(percent) + " %";
	this->displayData(3, msg, usage);
}

void		Ncurses::displayTitle(int quarters, std::string title)
{
	int x_pos = this->_width * quarters / 4 - title.size() / 2;
	int x_pos_box = (quarters <= 2) ? 1 : this->_width / 2 + 1;

	attron(COLOR_PAIR(this->_color));
	if (quarters == 2)
		mvhline(++this->_y, x_pos_box, ' ', this->_width - 2);
	else
		mvhline(++this->_y, x_pos_box, ' ', this->_width / 2 - 2);
	mvprintw(this->_y, x_pos, "%s", title.c_str());
	attroff(COLOR_PAIR(this->_color));
	this->_y += 2;
}

void		Ncurses::change_color(void)
{
	this->_color += (this->_color == 4) ? -3 : 1;
}
