/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 20:29:34 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QtDisplay.class.hpp>
#include <Monitor.class.hpp>

				QtDisplay::QtDisplay(int ac, char **av) : _ac(ac), _av(av) {}

				QtDisplay::~QtDisplay(void) {}

bool			QtDisplay::loop(Monitor const & src)
{
	std::cout << this->display(src) << std::endl;
	return false;
}

int				QtDisplay::display(Monitor const & src)
{
	(void)src;
	QApplication app(this->_ac, this->_av);
	QPushButton bouton("Passer en mode texte");
	bouton.setCursor(Qt::PointingHandCursor);
    bouton.show();
	return app.exec();
}
