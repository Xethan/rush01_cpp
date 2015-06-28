/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 22:09:47 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
# define NCURSES_HPP

# include <sstream>
# include <iomanip>
# include <ncurses.h>

# include <IMonitorDisplay.class.hpp>

class HostUserNames;
class OSInfo;
class Time;
class CPUInfo;
class RAMInfo;
class CPUUsage;
class NetworkUsage;
class Monitor;

class Ncurses : public IMonitorDisplay
{
private:
	int		_height;
	int		_width;
	int		_y;
	int		_color;
	bool	_display[6];

			Ncurses(Ncurses const &copy);
	Ncurses const & operator=(Ncurses const &rhs);

public:
			Ncurses(void);
			~Ncurses(void);

	bool	loop(Monitor const & src);
	void	display(Monitor const & src);

	void	displayModule(HostUserNames * module);
	void	displayModule(OSInfo * module);
	void	displayModule(CPUInfo * module);
	void	displayModule(Time * module);
	void	displayModule(RAMInfo * module);
	void	displayModule(CPUUsage * module);
	void	displayModule(NetworkUsage * module);
	bool	displayUI(void);

	void	displayGraphPercent(std::string msg, int percent);
	void	displayTitle(int quarters, std::string title);
	void	change_color(void);

	template<typename T>
	void	displayData(int quarters, std::string msg, T data)
	{
		int x_pos;
		std::stringstream sstream;
		sstream << data;
		std::string string_data = sstream.str();
		x_pos = this->_width * quarters / 4 - 20;
		mvprintw(this->_y++, x_pos, "%-15s%s", msg.c_str(), string_data.c_str());
	}

};

#endif
