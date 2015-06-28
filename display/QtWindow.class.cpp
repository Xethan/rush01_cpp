/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtWindow.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 20:49:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 23:39:06 by ncolliau         ###   ########.fr       */
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

void	QtWindow::displayModule(Time *module)
{
	QLabel *l_title = this->createLabel("--- Time Info ---", 5, 270);
	static_cast<void>(l_title);
	QLabel *l_date = this->createLabel("Date : " + module->getDate(), 5, 290);
	static_cast<void>(l_date);
	QLabel *l_time = this->createLabel("Time : " + module->getTime(), 5, 310);
	static_cast<void>(l_time);
}

void	QtWindow::displayModule(RAMInfo *module)
{
	QLabel *l_title = this->createLabel("--- Ressources ---", this->width() / 2, 0);
	static_cast<void>(l_title);
	QLabel *l_max = this->createLabel("Max. RAM : " + std::to_string(module->getRamMax()), this->width() / 2, 20);
	static_cast<void>(l_max);
	QLabel *l_used = this->createLabel("Used RAM : " + std::to_string(module->getRamUsed()), this->width() / 2, 40);
	static_cast<void>(l_used);
	QLabel *l_free = this->createLabel("Free RAM : " + std::to_string(module->getRamFree()), this->width() / 2, 60);
	static_cast<void>(l_free);
	QLabel *l_name = this->createLabel("RAM Percentage : ", this->width() / 2, 80);
	static_cast<void>(l_name);
	QProgressBar *ram_usage = new QProgressBar(this);
	ram_usage->move(this->width() / 2 + 150, 80);
	ram_usage->setValue(module->getRamPercent());
}

void	QtWindow::displayModule(CPUUsage *module)
{
	module->getCpuPercent();

	QLabel *l_title = this->createLabel("--- CPU Usage ---", this->width() / 2, 110);
	static_cast<void>(l_title);
	for (size_t i = 0; i < module->getCpuP().size(); i++)
	{
		QLabel *l_name = this->createLabel("CPU Core " + std::to_string(i + 1) + " : ", this->width() / 2, 140 + i * 30);
		static_cast<void>(l_name);
		int percent = static_cast<int>(module->getCpuP()[i]);
		QProgressBar *ram_usage = new QProgressBar(this);
		ram_usage->move(this->width() / 2 + 150, 140 + i * 30);
		ram_usage->setValue(percent);
	}
	QLabel *l_name = this->createLabel("CPU Usage : ", this->width() / 2, 290);
	static_cast<void>(l_name);
	int percent = static_cast<int>((module->getCpuP()[0] + module->getCpuP()[1] + module->getCpuP()[2] + module->getCpuP()[3]) / 4);
	QProgressBar *ram_usage = new QProgressBar(this);
	ram_usage->move(this->width() / 2 + 150, 290);
	ram_usage->setValue(percent);
}

void	QtWindow::displayModule(NetworkUsage *module)
{
	QLabel *l_title = this->createLabel("--- Network Usage ---", this->width() / 2, 320);
	static_cast<void>(l_title);
	QLabel *l_pckt_in = this->createLabel("Packets in : " + module->getNetworkThroughput(NetworkUsage::pktsIn) + " pkts", this->width() / 2, 340);
	static_cast<void>(l_pckt_in);
}

QLabel	*QtWindow::createLabel(std::string msg, int x_pos, int y_pos)
{
	QString qs(msg.c_str());
	QLabel *label = new QLabel(qs, this);
	label->move(x_pos, y_pos);
	return (label);
}