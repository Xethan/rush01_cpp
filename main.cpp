/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:15:15 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 20:18:01 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.Class.hpp"

int main(void)
{
	try
	{
		Monitor monitor;
		int key;

		monitor.display_all();
		while ( ( key = getch() ) != 27 )
			monitor.display_all();
		endwin();
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		endwin();
	}
	return (0);
}