/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:33:42 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/27 17:47:43 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
# define TIME_HPP

# include <ctime>
# include <iomanip>

# include "IMonitorModule.Class.hpp"

class Time : public IMonitorModule
{

public:

	Time(void);
	~Time(void);
	std::string getDate(void) const;
	std::string getTime(void) const;

private:

	Time(Time const &copy);
	Time const &operator=(Time const &rhs);

	std::string _date;
	std::string _time;
};

#endif