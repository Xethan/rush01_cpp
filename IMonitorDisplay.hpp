/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:49:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 13:53:42 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <ncurses.h>

# include "IMonitorModule.hpp"

class IMonitorDisplay
{

public:

	virtual ~IMonitorDisplay(void) {};
	virtual void displayData(IMonitorModule *data) const = 0;

};

#endif