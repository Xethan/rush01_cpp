/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QtDisplay.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 16:10:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/28 17:35:58 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QT_HPP
# define QT_HPP

# include <QApplication>
# include <QPushButton>

class QtDisplay
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

	void		displayStuff(void);
};

#endif
