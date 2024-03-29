/*
 * @file api.hpp
 * This file is part of Wintermute Visual
 *
 * Copyright (C) 2011 - Jacky Alcine
 *
 * Wintermute Visual is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Wintermute Visual is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __API_HPP__
#define __API_HPP__

#include <QObject>
#include <backend.hpp>
#include <wntr/plugins.hpp>
#include <wntr/config.hpp>

using Wintermute::Backends::AbstractBackend;
using Wintermute::Backends::AbstractFramework;
class QString;

namespace Wintermute {
    namespace Visual {
        struct Framework;

        /// @todo Introduce support for asking a question and getting a response.
        class Framework : public AbstractFramework {
            Q_OBJECT
            Q_ENUMS(AlertLevel)

            public:
                typedef enum {
                    LowAlert = 0,
                    MediumAlert,
                    HighAlert,
                    CriticalAlert
                } AlertLevel;

                Framework(QObject* = 0);
                virtual ~Framework();
                static Framework* instance();

            public slots:
                void showAboutDialog();
                void sendResponse(const QString&);
                void displayAlert(const AlertLevel&, const QString&);

            private:
                static Framework* s_inst;
                virtual void initialize();
                virtual void deinitialize();

            signals:
                void responseDisplayed(const QString&);
                void alertDisplayed(const AlertLevel&, const QString&);
        };
    }
}

#endif /* __API_HPP__ */
