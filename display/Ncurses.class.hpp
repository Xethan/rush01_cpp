/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 13:53:12 by ncolliau         ###   ########.fr       */
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

class Ncurses : public IMonitorDisplay
{
private:
	int		_height;
	int		_width;
	int		_y;

			Ncurses(Ncurses const &copy);
	Ncurses const & operator=(Ncurses const &rhs);

public:
			Ncurses(void);
			~Ncurses(void);

	void	displayModule(HostUserNames * module);
	void	displayModule(OSInfo * module);
	void	displayModule(CPUInfo * module);
	void	displayModule(Time * module);
	void	displayModule(RAMInfo * module);
	void	displayModule(CPUUsage * module);
	void	displayModule(NetworkUsage * module);
	void	displayUI(void);

	void	displayGraphPercent(std::string msg, int percent);

	template<typename T>
	void	displayData(int quarters, std::string msg, T data)
	{
		std::stringstream sstream;
		sstream << data;
		std::string string_data = sstream.str();
		int x_pos = this->_width * quarters / 4 - ( msg.size() + string_data.size() ) / 2;
		mvprintw(this->_y, x_pos, "%s%s", msg.c_str(), string_data.c_str());
		this->_y += 1;
	}

};

#endif
