/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtWindow.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 20:49:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 23:14:48 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QtWindow.class.hpp>
#include <HostUserNames.class.hpp>
#include <OSInfo.class.hpp>
#include <CPUInfo.class.hpp>
#include <Time.class.hpp>
#include <RAMInfo.class.hpp>
#include <CPUUsage.class.hpp>
#include <NetworkUsage.class.hpp>

QtWindow::QtWindow(void) : QWidget()
{
	this->setFixedSize(1000, 1000);

	this->_ncurses_button = new QPushButton("Passer en mode texte", this);
	this->_ncurses_button->setCursor(Qt::PointingHandCursor);
	return;
}

QtWindow::~QtWindow(void) {}

void	QtWindow::displayModule(HostUserNames *module)
{
	QLabel *l_host = this->createLabel("Hostname : " + module->getHostname(), 5, 30);
	static_cast<void>(l_host);
	QLabel *l_user = this->createLabel("Username : " + module->getUsername(), 5, 50);
	static_cast<void>(l_user);
}

void	QtWindow::displayModule(OSInfo *module)
{
	QLabel *l_title = this->createLabel("--- OS Info ---", 5, 70);
	static_cast<void>(l_title);
	QLabel *l_sys = this->createLabel("Sys. name : " + module->getSysname(), 5, 90);
	static_cast<void>(l_sys);
	QLabel *l_node = this->createLabel("Node name : " + module->getNodename(), 5, 110);
	static_cast<void>(l_node);
	QLabel *l_release = this->createLabel("Sys. release : " + module->getRelease(), 5, 130);
	static_cast<void>(l_release);
	QLabel *l_version = this->createLabel("Sys. version : " + module->getVersion(), 5, 150);
	static_cast<void>(l_version);
	QLabel *l_machine = this->createLabel("Identifier : " + module->getMachine(), 5, 170);
	static_cast<void>(l_machine);
}

void	QtWindow::displayModule(CPUInfo *module)
{
	QLabel *l_title = this->createLabel("--- CPU Info ---", 5, 190);
	static_cast<void>(l_title);
	QLabel *l_model = this->createLabel("Model : " + module->getModel(), 5, 210);
	static_cast<void>(l_model);
	QLabel *l_clock_speed = this->createLabel("Clock speed : " + module->getClockSpeed(), 5, 230);
	static_cast<void>(l_clock_speed);
	QLabel *l_nbcores = this->createLabel("Number Cores : " + std::to_string(module->getNbCores()), 5, 250);
	static_cast<void>(l_nbcores);
}

void	QtWindow::displayModule(RAMInfo *module)
{
	QProgressBar *ram_usage = new QProgressBar(this);
	ram_usage->move(this->width() / 2, 50);
	ram_usage->setValue(module->getRamPercent());
}

QLabel	*QtWindow::createLabel(std::string msg, int x_pos, int y_pos)
{
	QString qs(msg.c_str());
	QLabel *label = new QLabel(qs, this);
	label->move(x_pos, y_pos);
	return (label);
}