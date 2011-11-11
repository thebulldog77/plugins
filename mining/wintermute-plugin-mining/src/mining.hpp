/*
 * @file mining.hpp
 * This file is part of Wintermute Mining API 
 *
 * Copyright (C) 2011 - Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * Wintermute Mining API is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * Wintermute Mining API is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * @todo Outline the foundational code for a data miner.
 * @todo Outline the foundational code for a data source.
 */
 
 #include <QObject>
 #include <QList>
 #include <QMap>
 
namespace Wintermute {
    namespace Data {
        namespace Mining {
            struct AbstractMiner;
            struct AbstractSource;
            
            typedef QList<AbstractSource*> SourceList;
            typedef QList<AbstractMiner*> MinerList;
            typedef QMap<const QString, AbstractSource*> SourceMap;
            typedef QMap<const QString, AbstractMiner*> MinerMap;
                        
            class AbstractMiner : public QObject {
                Q_OBJECT
                
            };
            
            class AbstractSource : public QObject {
                Q_OBJECT            
            
            };
        }
    }
}
