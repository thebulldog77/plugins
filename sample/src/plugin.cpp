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
    namespace Sample {
        void Plugin::initialize () {
            cout << "Hello World!" << endl;
        }
        void Plugin::deinitialize () {
            cout << "Goodbye World!" << endl;
        }

        QObject* Plugin::instance () { return NULL; }

        const double Plugin::version () const {
            return 0.01;
        }

        const double Plugin::compatVersion () const {
            return 0.01;
        }

        const QString Plugin::uuid () const {
            return "00000000-0000-0000-0000-000000000000";
        }

        const QString Plugin::name() const {
            return "Sample Plugin";
        }

        const QString Plugin::author() const {
            return "John Doe <john.doe@woah.org>";
        }

        const QString Plugin::vendorName() const {
            return "John Doe <john.doe@woah.org>";
        }

        const QString Plugin::description() const {
            return "Sample plugin.";
        }

        const QString Plugin::webPage() const {
            return "http://website";
        }

        const QString Plugin::dependencies () const {
            return QString::null;
        }

    }
}

Q_EXPORT_PLUGIN2(WntrGui, Wintermute::Sample::Plugin)


