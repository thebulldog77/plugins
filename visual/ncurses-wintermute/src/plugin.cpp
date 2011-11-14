/**
 * plugins.cpp
 * This file is part of nCurses for Wintermute.
 *
 * Copyright (C) 2011 - Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * nCurses for Wintermute is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * nCurses for Wintermute is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with nCurses for Wintermute; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include "plugin.hpp"
#include "ncurses.hpp"
#include "core.hpp"
#include <QObject>
#include <QtPlugin>
#include <QStringList>

namespace Wintermute {
    namespace nCurses {
        Plugin::Plugin() { }

        Plugin::~Plugin() { }

        void Plugin::initialize () const {
            connect(Wintermute::Core::instance(),SIGNAL(started()),
                    Wintermute::Curses::Curses::instance(),SLOT(start()));
            connect(Wintermute::Core::instance(),SIGNAL(started()),
                    Wintermute::Curses::Curses::instance(),SLOT(stop()));
        }

        void Plugin::deinitialize () const {
        }

        QObject* Plugin::instance () {
            return NULL;
        }

    }
}

Q_EXPORT_PLUGIN2(nCurses-wintermute, Wintermute::nCurses::Plugin)
// kate: indent-mode cstyle; space-indent on; indent-width 4;
