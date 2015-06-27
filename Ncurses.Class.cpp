/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:24 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:25:08 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurses.Class.hpp"

Ncurses::Ncurses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	//start_color();
	//init_pair(1, COLOR_WHITE, COLOR_BLACK);
	//init_pair(2, COLOR_BLACK, COLOR_RED);
	return;
}

Ncurses::~Ncurses(void)
{
	return;
}