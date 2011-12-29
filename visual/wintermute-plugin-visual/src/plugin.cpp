/**
 * @file plugins.cpp
 * This file is part of Wintermute Visual.
 *
 * Copyright (C) 2011 - Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * Wintermute Linguistics is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wintermute Linguistics is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute Linguistics; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include "api.hpp"
#include "plugin.hpp"
#include <QObject>
#include <QtPlugin>
#include <QStringList>

namespace Wintermute {
    namespace Visual {
        Plugin::Plugin() : AbstractPlugin() {
            connect(this,SIGNAL(started()),Framework::instance(),SLOT(start()));
            connect(this,SIGNAL(stopped()),Framework::instance(),SLOT(stop()));
        }

        void Plugin::start () const { }
        void Plugin::stop () const { }

        Plugin::~Plugin() { }
    }
}

Q_EXPORT_PLUGIN2(wplugin-visual, Wintermute::Visual::Plugin)
// kate: indent-mode cstyle; space-indent on; indent-width 4;
