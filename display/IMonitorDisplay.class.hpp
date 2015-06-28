/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:49:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 09:49:54 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <ncurses.h>

# include <IMonitorModule.class.hpp>

class IMonitorDisplay
{
public:
	virtual	~IMonitorDisplay(void) {};
};

#endif
