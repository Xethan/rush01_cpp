/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:49:20 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:53:41 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <ncurses.h>

class IMonitorModule
{

public:

	virtual ~IMonitorModule(void) {};
	virtual void display(void) const = 0;

};

#endif