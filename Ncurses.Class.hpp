/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:42:25 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include "IMonitorDisplay.hpp"

class Ncurses : public IMonitorDisplay
{

public:

	Ncurses(void);
	~Ncurses(void);
	void displayData(IMonitorModule *data) const;
	void end_display(void) const;

private:

	Ncurses(Ncurses const &copy);
	Ncurses const &operator=(Ncurses const &rhs);

};

#endif