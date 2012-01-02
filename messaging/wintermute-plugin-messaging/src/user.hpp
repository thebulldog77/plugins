/**
 * @file user.hpp
 * This file is part of Wintermute Messaging.
 *
 * Copyright (C) 2011 - Jacky Alcine <jacky.alcine@thesii.org>
 *
 * Wintermute Messaging is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wintermute Messaging is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute Messaging; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifndef WNTRMESSAGING_USER_HPP
#define WNTRMESSAGING_USER_HPP

#include <QObject>

namespace Wintermute {
    namespace Messaging {
        class User : public QObject
        {
            Q_OBJECT
            Q_DISABLE_COPY(User)
        public:
            virtual ~User();

        public slots:

        private:
            explicit User(QObject *parent = 0);

        };
    }
}

#endif // USER_HPP
