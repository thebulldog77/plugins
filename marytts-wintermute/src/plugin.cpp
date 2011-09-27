/**
 * plugin.cpp
 * This file is part of Wintermute Graphics.
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
#include <iostream>
#include <QtPlugin>

using namespace std;

using std::cout;
using std::endl;

namespace Wintermute {
    namespace Voice {
        namespace MaryTTS {
            void Plugin::initialize () const {
                cout << "Hello World!" << endl;
                Wintermute::Plugins::Factory::unloadPlugin (this->uuid());
            }

            void Plugin::deinitialize () const {
                cout << "Goodbye World!" << endl;
            }

            QObject* Plugin::instance () const { return NULL; }
        }
    }
}

Q_EXPORT_PLUGIN2(WntrGui, Wintermute::Voice::MaryTTS::Plugin)
