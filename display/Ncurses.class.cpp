/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 11:09:03 by mgouault         ###   ########.fr       */
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

	int h, w;
	getmaxyx(stdscr, h, w);
	this->_h = h;
	this->_w = w;
}

			Ncurses::~Ncurses(void)
{
	endwin();
}

void		Ncurses::displayModule(HostUserNames * module)
{
	move(1, 3);
	this->_y = 1;
	this->_x = 3;

	this->print("Hostname: " + module->getHostname());
	this->print("Username: " + module->getUsername());
}

void		Ncurses::displayModule(OSInfo * module)
{
	move(4, 3);
	this->_y = 4;
	this->_x = 3;

	this->print("======= OS Info =======");
	this->print("Sys. name: " + module->getSysname());
	this->print("Node name: " + module->getNodename());
	this->print("Sys. release: " + module->getRelease());
	this->print("Sys. version: " + module->getVersion());
	this->print("Identifier: " + module->getMachine());
}

void		Ncurses::displayModule(CPUInfo * module)
{
	move(11, 3);
	this->_y = 11;
	this->_x = 3;

	this->print("====== CPU Info =======");
	this->print("Model: " + module->getModel());
	this->print("Clock speed: " + module->getClockSpeed());
	std::stringstream ss;
	ss << "Nb cores: " << module->getNbCores();
	this->print(ss.str());
}

void		Ncurses::displayModule(Time * module)
{
	move(this->_h / 2, this->_w / 4 + 3);
	this->_y = this->_h / 2;
	this->_x = this->_w / 4 + 3;

	this->print("Date: " + module->getDate());
	this->print("Time: " + module->getTime());
}

void		Ncurses::displayModule(RAMInfo * module)
{
	move(this->_h / 2 + 4, this->_w / 4 + 3);
	this->_y = this->_h / 2 + 4;
	this->_x = this->_w / 4 + 3;

	this->print("======= Ressources ======");
	this->print("Max. RAM: " + std::to_string(module->getRamMax()));
	this->print("Used RAM: " + std::to_string(module->getRamUsed()));
	this->print("Free RAM: " + std::to_string(module->getRamFree()));

	std::stringstream ss;
	ss << "RAM Usage: ";
	int p1 = module->getRamPercent() / 10;
	int p2 = p1;
	ss << "[";
	while (p1 > 0)
	{ ss << "=="; --p1; }
	ss << ">";
	while (p2 < 10)
	{ ss << "  "; ++p2; }
	ss << "] " << module->getRamPercent() << " %% " \
		<< "(" << module->getRamUsed() << " MB / " << module->getRamMax() << " MB)";

	this->print(ss.str());
}

void		Ncurses::displayModule(CPUUsage * module)
{
	move(this->_h / 2 + 10, this->_w / 4 + 3);
	this->_y = this->_h / 2 + 10;
	this->_x = this->_w / 4 + 3;

	module->getCpuPercent();

	std::stringstream ss;
	ss << "CPU Usage: ";
	int p = static_cast<int>((module->getCpuP()[0] + module->getCpuP()[1] + module->getCpuP()[2] + module->getCpuP()[3]) / 4);
	int p1 = p / 10;
	int p2 = p1;
	ss << "[";
	while (p1 > 0)
	{ ss << "=="; --p1; }
	ss << ">";
	while (p2 < 10)
	{ ss << "  "; ++p2; }
	ss << "] " << p << " %% ";

	this->print(ss.str());

}

void		Ncurses::displayModule(NetworkUsage * module)
{
	(void)module;
}

void		Ncurses::displayUI(void)
{
	move(0, 0);
	addch('#');
	for (int i = 0 ; i < this->_w - 2; i++)
		addch('-');
	addch('#');
	for (int i = 0 ; i < this->_h - 2 ; i++)
	{ move(i + 1, 0); addch('|'); }
	addch('\n');
	addch('#');
	for (int i = 0 ; i < this->_w - 2; i++)
		addch('-');
	addch('#');
	for (int i = 0 ; i < this->_h - 2 ; i++)
	{ move(i + 1, this->_w - 1); addch('|'); }
	move(0, this->_w / 2 - 1);
	addch('#');
	for (int i = 0 ; i < this->_h / 2 - 2 ; i++)
	{ move(i + 1, this->_w / 2 - 1); addch('|'); }
	move(this->_h / 2 - 1, 0);
	addch('#');
	for (int i = 0 ; i < this->_w - 2 ; i++)
	{ move(this->_h / 2 - 1, i + 1); addch('-'); }
	addch('#');
	move(this->_h / 2 - 1, this->_w / 2 - 1);
	addch('#');
}

void		Ncurses::print(std::string str)
{
	std::stringstream ss;
	ss << std::setw(14) << std::left << str;

	move(this->_y, this->_x);
	printw(ss.str().c_str());
	this->_y++;
}
