/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 20:53:33 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QT_HPP
# define QT_HPP

# include <QApplication>
# include <QtWindow.class.hpp>

# include <IMonitorDisplay.class.hpp>

class Monitor;

class QtDisplay : public IMonitorDisplay
{
private:

	int _ac;
	char **_av;

				QtDisplay(void);
				QtDisplay(QtDisplay const & src);
	QtDisplay const &	operator=(QtDisplay const & src);

public:
				QtDisplay(int ac, char **av);
				~QtDisplay(void);


	bool		loop(Monitor const & src);
	int			display(Monitor const & src);
};

#endif
