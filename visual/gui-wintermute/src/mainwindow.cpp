/**
 * @file mainwindow.cpp
 * This file is part of Wintermute Graphics.
 *
 * Copyright (C) 2011 - Wintermute Developers <wintermute-devel@lists.launchpad.net>
 *
 * Wintermute Graphics is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Wintermute Graphics is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Wintermute Linguistics; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include "mainwindow.hpp"
#include "configui.hpp"
#include "ui_main.h"
#include "gui.hpp"
#include <visual/aboutdialog.hpp>
#include <wntrling.hpp>
#include <wntrntwk.hpp>
#include <QtDebug>
#include <QString>
#include <QFile>
#include <QMenu>
#include <QKeySequence>
#include <QMessageBox>
#include <QInputDialog>

using Wintermute::Visual::AboutDialog;

namespace Wintermute {
    namespace Graphics {
        MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
            ui->setupUi(this);
            ui->coreWidget->setLayout (ui->centralLayout);
            buildMenu();
        }

        void MainWindow::buildMenu(){
        }

        MainWindow::~MainWindow() {
            delete ui;
        }

        void MainWindow::changeEvent(QEvent *e) {
            QMainWindow::changeEvent(e);

            switch (e->type()) {
            case QEvent::LanguageChange:
                ui->retranslateUi(this);
                break;
            default:
                break;
            }
        }
    }
}
// kate: indent-mode cstyle; space-indent on; indent-width 4;
