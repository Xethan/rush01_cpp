/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:25:17 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include "IMonitorDisplay.Class.hpp"

class Ncurses : public IMonitorDisplay
{

public:

	Ncurses(void);
	~Ncurses(void);
private:

	Ncurses(Ncurses const &copy);
	Ncurses const &operator=(Ncurses const &rhs);

};

#endif