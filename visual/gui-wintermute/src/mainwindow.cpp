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
#include <frontend/aboutdialog.hpp>
#include <wntrling.hpp>
#include <wntrntwk.hpp>
#include <aboutdialog.hpp>
#include <QtDebug>
#include <QString>
#include <QFile>
#include <QMenu>
#include <QKeySequence>
#include <QMessageBox>
#include <QInputDialog>

using Wintermute::Frontend::AboutDialog;

namespace Wintermute {
    namespace Graphics {
        MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
            ui->setupUi(this);
            ui->coreWidget->setLayout (ui->centralLayout);
            QMenu* l_aMenu = new QMenu(ui->btnOptions);
            l_aMenu->addAction (QIcon::fromTheme ("preferences"),"&Preferences",this,SLOT(on_actnPreferences_triggered()),QKeySequence::Preferences);
            l_aMenu->addAction (QIcon::fromTheme ("view-fullscreen"),"Toggle &Fullscreen",this,SLOT(on_actnFullscreen_clicked()),QKeySequence("F11"));
            l_aMenu->addAction (QIcon::fromTheme ("text-speak"),"&Talk to Wintermute...",this,SLOT(on_actnReply_clicked()),QKeySequence("Shift+Enter"));
            l_aMenu->addSeparator ();
            l_aMenu->addAction (QIcon::fromTheme ("help-about"),"&About",this,SLOT(on_actnAbout_clicked()),QKeySequence::HelpContents);
            l_aMenu->addAction ("About Qt",QApplication::instance (),SLOT(aboutQt()));
            l_aMenu->addAction (QIcon::fromTheme ("application-ext"),"&Quit",this,SLOT(on_atcnClose_clicked()),QKeySequence::Quit);
            ui->btnOptions->setMenu(l_aMenu);
            connect(Network::System::instance(),SIGNAL(messageRecieved(Message)),this,SLOT(messageRecieved(const Message&)));
        }

        void MainWindow::messageRecieved(const Message& p_msg){
            ui->lblStatus->setText(p_msg.toString ());
        }

        MainWindow::~MainWindow() {
            delete ui;
        }


        void MainWindow::on_actnPreferences_triggered(){
            ConfigurationDialog* cuiDialog = new ConfigurationDialog(this);
            cuiDialog->show ();
        }

        void MainWindow::on_actnAbout_clicked()
        {
            AboutDialog* aDialog = new AboutDialog(this);
            aDialog->show ();
        }

        void MainWindow::on_actnFullscreen_clicked()
        {
            if (!this->isFullScreen ())
                this->showFullScreen ();
            else
                this->showNormal ();
        }

        void MainWindow::on_actnReply_clicked()
        {
            const QString l_txt = QInputDialog::getText (this,"Response?", "Say something to Wintermute.");
            if (!l_txt.isEmpty ()){
                Wintermute::Linguistics::Parser l_prsr;
                ui->lblResponse->setText ("<span style='color: #bbb'>You entered</span>: " + l_txt);
                QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
                l_prsr.parse (l_txt);
                QApplication::restoreOverrideCursor();
            }
        }

        void MainWindow::on_atcnClose_clicked() {
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            Core::stop();
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
