/*
 * backend.hpp
 * This file is part of Wintermute Graphical User Interface
 *
 * Copyright (C) 2011 - Wintermute Development
 *
 * Wintermute Graphical User Interface is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Wintermute Graphical User Interface is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __BACKEND_HPP__
#define __BACKEND_HPP__
#include <frontend/api.hpp>
#include <wntr/plugins.hpp>

using Wintermute::Backends::AbstractBackend;
using Wintermute::Plugins::AbstractPlugin;

namespace Wintermute {
    namespace Graphics {
        struct Backend;

        class Backend : public AbstractBackend {
            Q_OBJECT
            Q_DISABLE_COPY(Backend)

            public:
                Backend(AbstractPlugin* );
                virtual ~Backend();
                virtual const QString id() const;
                virtual const bool isActive() const;

            private:
                virtual void initialize();
                virtual void deinitialize();
        };
    }
}

#endif /* __BACKEND_HPP__ */
