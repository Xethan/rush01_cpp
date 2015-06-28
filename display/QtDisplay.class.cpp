/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 17:35:47 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QtDisplay.class.hpp>

				QtDisplay::QtDisplay(int ac, char **av) : \
					_app(*(new QApplication(ac, av))) {}

				QtDisplay::~QtDisplay(void) {}

QApplication const & QtDisplay::getApp(void) const
{
	return this->_app;
}

void			QtDisplay::displayStuff(void)
{
	QPushButton bouton("TEST");
	bouton.show();
}
