/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 00:05:30 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.Class.hpp"

int		main(void)
{
	try
	{
		Monitor monitor;
		int key;

		monitor.display();
		while ( ( key = getch() ) != 27 )
			monitor.display();
		endwin();
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		endwin();
	}
	return (0);
}
