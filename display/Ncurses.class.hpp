/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:51:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 12:36:46 by mgouault         ###   ########.fr       */
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
	//int		_y;

			Ncurses(Ncurses const &copy);
	Ncurses const & operator=(Ncurses const &rhs);

public:
			Ncurses(void);
			~Ncurses(void);

	void	displayModule(HostUserNames * module) const;
	void	displayModule(OSInfo * module) const;
	void	displayModule(CPUInfo * module) const;
	void	displayModule(Time * module) const;
	void	displayModule(RAMInfo * module) const;
	void	displayModule(CPUUsage * module) const;
	void	displayModule(NetworkUsage * module) const;
	void	displayUI(void);

	template<typename T>
	void	displayData(int y_pos, std::string msg, T data) const
	{
		std::stringstream sstream;
		sstream << data;
		std::string string_data = sstream.str();
		int x_pos = this->_width / 4 - ( msg.size() + string_data.size() ) / 2;
		mvprintw(y_pos, x_pos, "%s%s", msg.c_str(), string_data.c_str());
	}

};

#endif
