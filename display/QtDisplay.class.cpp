/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 23:37:27 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QtDisplay.class.hpp>
#include <Monitor.class.hpp>

				QtDisplay::QtDisplay(int ac, char **av) : _ac(ac), _av(av) {}

				QtDisplay::~QtDisplay(void) {}

bool			QtDisplay::loop(Monitor const & src)
{
	this->display(src);
	return false;
}

int				QtDisplay::display(Monitor const & src)
{
	QApplication app(this->_ac, this->_av);
	QtWindow window;
	window.displayModule(src.getHostUserNames());
	window.displayModule(src.getOSInfo());
	window.displayModule(src.getCPUInfo());
	window.displayModule(src.getTimeInfo());
	window.displayModule(src.getRAMInfo());
	window.displayModule(src.getCPUUsage());
	window.displayModule(src.getNetworkUsage());
	window.show();
	return app.exec();
}
