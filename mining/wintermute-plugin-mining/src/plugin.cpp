/**
 * @file    plugin.cpp
 * @author  Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
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
    namespace Data {
	namespace Mining {
            void Plugin::start() const {}
            void Plugin::stop () const {}
    	}
    }
}

Q_EXPORT_PLUGIN2(WPlugin-Mining, Wintermute::Data::Mining::Plugin)
