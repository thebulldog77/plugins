/**
 * @file plugins.cpp
 * This file is part of Wintermute Frontend.
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
    namespace Frontend {

        Plugin::Plugin() { }

        Plugin::~Plugin() { }

        void Plugin::start () const {
            Framework::instance()->start();
        }

        void Plugin::stop () const {
            Framework::instance()->stop();
        }

    }
}

Q_EXPORT_PLUGIN2(WntrFrontend, Wintermute::Frontend::Plugin)
// kate: indent-mode cstyle; space-indent on; indent-width 4;
