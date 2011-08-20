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
    namespace Sample {
        struct Plugin;

        using Wintermute::Plugins::PluginBase;

        class Plugin : public PluginBase {
            public:
                Plugin() : PluginBase() { }
                ~Plugin() { }
                Plugin(Plugin const &k) : PluginBase(k) { }

                virtual const double version() const;
                virtual const double compatVersion() const;
                virtual const QString uuid() const;
                virtual const QString name() const;
                virtual const QString author() const;
                virtual const QString vendorName() const;
                virtual const QString description() const;
                virtual const QString webPage() const;
                virtual const QString dependencies() const;
                virtual void initialize();
                virtual void deinitialize();
                virtual QObject* instance();
        };
    }
}
