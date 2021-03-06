/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:33:42 by ncolliau          #+#    #+#             */
/*   Updated: 2015/06/28 09:50:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HPP
# define TIME_HPP

# include <ctime>
# include <iomanip>

# include <IMonitorModule.class.hpp>

class Time : public IMonitorModule
{
private:
				Time(Time const &copy);
	Time const & operator=(Time const &rhs);

public:
				Time(void);
				~Time(void);
	std::string getDate(void) const;
	std::string getTime(void) const;
};

#endif
