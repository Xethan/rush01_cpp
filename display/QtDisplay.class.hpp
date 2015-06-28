/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 19:11:49 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QT_HPP
# define QT_HPP

# include <QApplication>
# include <QPushButton>

# include <IMonitorDisplay.class.hpp>

class Monitor;

class QtDisplay : public IMonitorDisplay
{
private:
	QApplication const & _app;

				QtDisplay(void);
				QtDisplay(QtDisplay const & src);
	QtDisplay const &	operator=(QtDisplay const & src);

public:
				QtDisplay(int ac, char **av);
				~QtDisplay(void);

	QApplication const & getApp(void) const;

	bool		loop(Monitor const & src);
	void		display(Monitor const & src);
};

#endif
