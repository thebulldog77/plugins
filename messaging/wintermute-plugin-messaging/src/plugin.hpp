/**
 * @file plugins.hpp
 * This file is part of Wintermute Messaging.
 *
 * Copyright (C) 2011 - Jacky Alcine <jacky.alcine@thesii.org>
 *
 * Wintermute Messaging is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wintermute Messaging is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute Messaging; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifndef _PLUGIN_HPP_
#define _PLUGIN_HPP_

#include <wntr/plugins.hpp>
#include "config.hpp"

using Wintermute::Plugins::AbstractPlugin;

/// See plugin.cpp for more information.
namespace Wintermute {
    namespace Messaging {
        struct Plugin;
        
        /**
        * @brief
        * @class Plugin plugin.hpp "src/plugin.hpp"
        */
        class Plugin : public Wintermute::Plugins::AbstractPlugin {
            Q_OBJECT

            public:
                Plugin();
                virtual ~Plugin();
                virtual void start() const;
                virtual void stop() const;
        };
    }
}

#endif /** _PLUGIN_HPP */
// kate: indent-mode cstyle; space-indent on; indent-width 4;
