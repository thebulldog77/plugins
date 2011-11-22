/**
 * plugins.cpp
 * This file is part of Wintermute Graphics.
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

#include "gui.hpp"
#include "plugin.hpp"
#include <QObject>
#include <QtPlugin>
#include <QStringList>
#include <wntrdata.hpp>
#include <wntrling.hpp>
#include <frontend/api.hpp>

namespace Wintermute {
    namespace Graphics {
        Plugin::Plugin() { }

        Plugin::~Plugin() { }

        /// @todo Register its component to the Frontend component.
        void Plugin::initialize () const {
            Core::start(const_cast<Plugin*>(this));
            Frontend::Framework::instance()->addBackend(Core::backend());
        }

        /// @todo Unregister its component from the Frontend component.
        void Plugin::deinitialize () const {
            Frontend::Framework::instance()->removeBackend(Core::backend());
            Core::stop();
        }

        QObject* Plugin::instance () {
            return NULL;
        }

    }
}

Q_EXPORT_PLUGIN2(WntrGui, Wintermute::Graphics::Plugin)
// kate: indent-mode cstyle; space-indent on; indent-width 4;
