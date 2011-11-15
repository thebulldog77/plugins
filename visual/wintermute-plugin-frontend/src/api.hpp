/*
 * @file api.hpp
 * This file is part of Wintermute Frontend
 *
 * Copyright (C) 2011 - Jacky Alcine
 *
 * Wintermute Frontend is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Wintermute Frontend is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <QObject>
#include <QString>

namespace Wintermute {
    namespace Frontend {
        struct AbstractBackend;
        struct System;

        class System : public QObject {
            Q_OBJECT
            Q_DISABLE_COPY(System)

            signals:
                void started();
                void stopped();
                void addedNewBackend(AbstractBackend& );
                void addedNewBackend(const QString& );
                void removedBackend(AbstractBackend& );
                void removedBackend(const QString& );

            private:
                static System* s_inst;
                System(QObject* = 0);
                ~System();

            public:
                static System* instance();
                static void registerBackend(AbstractBackend&);
                static void unregisterBackend(AbstractBackend& );

            public slots:
                static void showAbout();
                static void start();
                static void stop();
        };

        class AbstractBackend : public QObject {
            Q_OBJECT
            Q_PROPERTY(const bool Active READ active)

            public:
                AbstractBackend(QObject* = 0);
                ~AbstractBackend();
                const bool active() const;
                void start();
                void stop();
        };
    }
}
