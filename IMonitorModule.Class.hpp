/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.Class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:49:20 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:05:25 by mgouault         ###   ########.fr       */
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
	virtual		~IMonitorModule(void) {};
};

#endif
