/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.Class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:49:20 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:09:26 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <string>
# include <stdexcept>
# include <ncurses.h>

class IMonitorModule
{

public:

	virtual ~IMonitorModule(void) {};
	//virtual void displayNcurses(void) const = 0;
	//virtual void displayQT(void) const = 0;

};

#endif