/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtWindow.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 20:49:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 22:15:45 by ncolliau         ###   ########.fr       */
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
	this->setFixedSize(500, 500);

	this->_ncurses_button = new QPushButton("Passer en mode texte", this);
	this->_ncurses_button->setCursor(Qt::PointingHandCursor);
	return;
}

QtWindow::~QtWindow(void) {}

void	QtWindow::displayModule(HostUserNames *module)
{
	std::string test("Hostname : " + module->getHostname());
	QString text(test.c_str());
	this->_hostusernames = new QPushButton(text, this);
	this->_hostusernames->move(0, 25);
}

void	QtWindow::displayModule(RAMInfo *module)
{
	this->_ram_usage = new QProgressBar(this);
	this->_ram_usage->move(0, 50);
	this->_ram_usage->setValue(module->getRamPercent());
}