/**
 * plugin.hpp
 * This file is part of Wintermute's sample plugin.
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

#include <wntr/plugins.hpp>
#include <QtPlugin>

namespace Wintermute {
    namespace Voice {
        struct Plugin;

        using Wintermute::Plugins::AbstractPlugin;

        class Plugin : public AbstractPlugin {
            Q_OBJECT
            public:
                Plugin() : AbstractPlugin() { }
                virtual ~Plugin() { }
                Plugin(Plugin const &k) : AbstractPlugin(k) { }

                virtual void start() const;
                virtual void stop() const;
        };
    }
}
