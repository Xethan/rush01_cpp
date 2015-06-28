/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 19:12:00 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QtDisplay.class.hpp>
#include <Monitor.class.hpp>

				QtDisplay::QtDisplay(int ac, char **av) : \
					_app(*(new QApplication(ac, av))) {}

				QtDisplay::~QtDisplay(void) {}

QApplication const & QtDisplay::getApp(void) const
{
	return this->_app;
}

bool			QtDisplay::loop(Monitor const & src)
{
	(void)src;
	return true;
}

void			QtDisplay::display(Monitor const & src)
{
	(void)src;
}
