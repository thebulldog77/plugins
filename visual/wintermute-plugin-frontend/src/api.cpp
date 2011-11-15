/*
 * @file api.cpp
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

#include "api.hpp"

namespace Wintermute {
        namespace Frontend {
                System* System::s_inst = NULL;

                System::System(QObject *p_obj) : QObject(p_obj) { }
                void System::showAbout (){}
                void System::start () { }
                void System::stop () { }
                void System::registerBackend (AbstractBackend &p_bcknd) { }
                void System::unregisterBackend (AbstractBackend &p_bcknd) { }
                System* System::instance () { return s_inst; }
                System::~System () {}

                AbstractBackend::AbstractBackend(QObject *p_obj) : QObject(p_obj) { }
                const bool AbstractBackend::active () const {}
                AbstractBackend::~AbstractBackend () {}

        }
}
