/**
 * @file plugin.cpp
 *
 * Copyright (C) 2011 - Jacky Alcine
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

#include "plugin.hpp"
#include "sphinx.hpp"
#include "config.hpp"
#include <QtPlugin>
#include <QDebug>

namespace Wintermute {
    namespace Voice {
        namespace PocketSphinx {
            Backend::Backend() : AbstractBackend(Plugins::Factory::currentPlugin(),Plugins::Factory::currentPlugin()) {
            }

            const QString Backend::id() const { return WNTR_POCKETSPHINX_UUID; }

            const bool Backend::isActive() const { }

            void Backend::initialize() { }

            void Backend::deinitialize() { }

            Backend::~Backend() { }

            void Plugin::start () const {
                SphinxRecognizer l_sphinx;
                qDebug() << l_sphinx.waitToListen ();
            }

            void Plugin::stop () const { }
        }
    }
}

Q_EXPORT_PLUGIN2(PocketSphinx-Wintermute, Wintermute::Voice::PocketSphinx::Plugin)
