/**
 * @file    ConfigurationDialog.cpp
 * @author  jacky
 * @created 9/24/2011
 *
 * Copyright (C) %YEAR by %USER%
 *
 * This is free software; you can redistribute it and/or modify
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

#include "configui.hpp"
#include "ui_configui.h"
#include <wntrling.hpp>
#include <plugins.hpp>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDir>
#include <QLCDNumber>
#include <QMenu>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QCheckBox>
#include <QProgressDialog>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>

namespace Wintermute {
    namespace Graphics {
        ConfigurationDialog::ConfigurationDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ConfigurationDialog){
            ui->setupUi(this);
            on_tabWidget_currentChanged (0);
            on_tabWidget_currentChanged (1);
            on_tabWidget_currentChanged (2);
            ui->tableWidgetLinks->setVerticalHeaderLabels(QString("Semantic ID,Flag").split (","));

            QMenu* l_aMenu = new QMenu(ui->pushButtonSelect);
            l_aMenu->addAction (QIcon::fromTheme ("edit-select-all"),"&All",ui->treeWidgetDelete,SLOT(selectAll()));
            l_aMenu->addAction("None",ui->treeWidgetDelete,SLOT(clearSelection()));
            ui->pushButtonSelect->setMenu (l_aMenu);

            QMenu * l_aMenu2 = new QMenu(ui->pushButtonDelete);
            l_aMenu2->addAction (QIcon::fromTheme ("edit-select-all"),"&All",this,SLOT(on_pushButtonDelete_all()));
            l_aMenu2->addAction (QIcon::fromTheme("edit-select"),"&Selected",this,SLOT(on_pushButtonDelete_selected()));
            ui->pushButtonDelete->setMenu (l_aMenu2);
        }

        void ConfigurationDialog::on_pushButtonDelete_all() {

        }

        void ConfigurationDialog::on_pushButtonDelete_selected() {

        }

        void ConfigurationDialog::on_btnRefresh_clicked(){
            on_tabWidget_currentChanged (0);
        }

        void ConfigurationDialog::on_pushButtonUpdate_clicked() {
            if (QMessageBox::question (this,"Updating Lexical Information","Are you sure you want to save these changes?<br>This can <b>not</b> be undone.",QMessageBox::Ok | QMessageBox::Close,QMessageBox::Close)){
                const QString l_sym = ui->symbolLineEdit->text ().toLower ();
                const QString l_lcl = ui->localeComboBox->currentText ();
                Data::Linguistics::Lexical::Data l_dt(Data::Linguistics::Lexical::Data::idFromString (l_sym),l_lcl,l_sym);
                Data::Linguistics::Lexical::FlagMapping l_flgs;
                for (int i = 0; i < ui->tableWidgetLinks->rowCount(); i++){
                    const QString l_id = ui->tableWidgetLinks->item(i,0)->text();
                    const QString l_flg = ui->tableWidgetLinks->item(i,1)->text();
                    l_flgs.insert (l_id,l_flg);
                }

                l_dt.setFlags (l_flgs);
                Data::Linguistics::Lexical::Cache::write (l_dt);
            }
        }

        void ConfigurationDialog::on_pushButtonAdd_clicked() {
            ui->tableWidgetLinks->setRowCount(ui->tableWidgetLinks->rowCount() + 1);
            ui->tableWidgetLinks->setItem(ui->tableWidgetLinks->rowCount(),0,(new QTableWidgetItem("-1")));
            ui->tableWidgetLinks->setItem(ui->tableWidgetLinks->rowCount(),1,(new QTableWidgetItem("---")));
        }

        void ConfigurationDialog::on_tabWidget_currentChanged(int index) {
            QApplication::setOverrideCursor (Qt::WaitCursor);
            switch (index){
                case 0: {
                    ui->lcdWord->display(Data::Linguistics::Lexical::Cache::countSymbols());
                    //ui->lcdOnto->display(Data::Ontology::Resource::countConcepts());
                    ui->lcdConc->display(Data::Ontology::Repository::countOntologies());
                    ui->lcdLink->display(Data::Linguistics::Lexical::Cache::countFlags());
                } break;

                case 1: {
                    ui->tabWidget_2->setCurrentIndex (0);
                } break;

                case 2: {
                } break;

                case 3: {
                    ui->listWidgetPlugins->clear();
                    QDBusMessage l_callAll = QDBusMessage::createMethodCall ("org.thesii.Wintermute","/Factory","org.thesii.Wintermute.Factory","allPlugins");
                    QDBusMessage l_callLoaded = QDBusMessage::createMethodCall ("org.thesii.Wintermute","/Factory","org.thesii.Wintermute.Factory","loadedPlugins");
                    QDBusMessage l_replyAll = QDBusConnection::sessionBus ().call(l_callAll,QDBus::BlockWithGui);
                    QDBusMessage l_replyLoaded = QDBusConnection::sessionBus ().call(l_callLoaded,QDBus::BlockWithGui);
                    QStringList l_all, l_loaded;
                    l_all = l_replyAll.arguments().at(0).toStringList();
                    l_loaded = l_replyLoaded.arguments().at(0).toStringList();

                    foreach (const QString& l_uuid, l_all){
                        QListWidgetItem* l_item = new QListWidgetItem();
                        l_item->setText(Wintermute::Plugins::Factory::attribute(l_uuid,"Description/Name").toString());
                        l_item->setData(0,l_uuid);
                        ui->listWidgetPlugins->addItem(l_item);
                    }

                    ui->listWidgetPlugins->sortItems();
                    ui->listWidgetPlugins->setCurrentRow(0);
                }
            }

            QApplication::setOverrideCursor (Qt::ArrowCursor);
        }

        void ConfigurationDialog::on_tabWidget_2_currentChanged(int index){
            QStringList l_comboBoxLingLocaleItems;
            const QStringList l_allLocales = Data::Linguistics::System::locales();
            l_comboBoxLingLocaleItems << "* all *" << l_allLocales;

            switch (index){
                case 0: {
                    on_symbolLineEdit_editingFinished ();
                    ui->localeComboBox->clear ();
                    ui->localeComboBox->addItems (l_allLocales);
                } break;

                case 1: {
                    ui->comboBoxLingDeleteLocale->clear ();
                    ui->comboBoxLingDeleteLocale->addItems (l_comboBoxLingLocaleItems);
                } break;

                case 2: {
                    ui->cmbBxLingSaveLocales->clear ();
                    ui->cmbBxLingSaveLocales->addItems (l_allLocales);
                } break;
            }

        }

        void ConfigurationDialog::loadLocale(const QString& p_lcl){
            const QStringList l_nodes = Lexical::Cache::allNodes(p_lcl);
            QProgressDialog l_prg("Loading nodes...","Cancel",0,l_nodes.length (),this);
            l_prg.setWindowModality(Qt::WindowModal);
            l_prg.setValue (0);

            ui->treeWidgetDelete->setColumnCount(2);
            foreach (const QString l_ndID, l_nodes){
                l_prg.setValue (l_prg.value () + 1);
                Lexical::Data l_dt(l_ndID,p_lcl);
                Lexical::Cache::read (l_dt);
                QTreeWidgetItem* l_item = new QTreeWidgetItem(QString(l_dt.symbol ()).split(","));
                for (Lexical::FlagMapping::ConstIterator l_itr = l_dt.flags ().begin (); l_itr != l_dt.flags ().end (); l_itr++)
                    l_item->addChild ((new QTreeWidgetItem(QString(l_itr.key() + "," + l_itr.value()).split (","))));

                ui->treeWidgetDelete->addTopLevelItem(l_item);
            }
        }

        void ConfigurationDialog::on_comboBoxLingDeleteLocale_activated(const QString& p_lcl){
            ui->treeWidgetDelete->clear ();
            if (p_lcl == "* all *"){
                foreach (const QString l_lcl, Data::Linguistics::System::locales())
                    loadLocale(l_lcl);
            } else {
                loadLocale(p_lcl);
            }
        }

        void ConfigurationDialog::on_symbolLineEdit_editingFinished() {
            const QString l_sym = ui->symbolLineEdit->text ().toLower ();
            const QString l_lcl = ui->localeComboBox->currentText ();
            Data::Linguistics::Lexical::Data l_dt(Data::Linguistics::Lexical::Data::idFromString (l_sym),l_lcl,l_sym);

            if (Data::Linguistics::Lexical::Cache::exists (l_dt)){
                Data::Linguistics::Lexical::Cache::read (l_dt);
                qDebug() << l_dt;
                int i = 0;
                ui->tableWidgetLinks->setRowCount(l_dt.flags ().size ());
                ui->tableWidgetLinks->setColumnCount(2);
                for (Data::Linguistics::Lexical::FlagMapping::ConstIterator l_itr = l_dt.flags ().begin (); l_itr != l_dt.flags ().end (); l_itr ++, i++){
                    ui->tableWidgetLinks->setItem(i,0,(new QTableWidgetItem(l_itr.key ())));
                    ui->tableWidgetLinks->setItem(i,1,(new QTableWidgetItem(l_itr.value ())));
                }
            } else {
                ui->tableWidgetLinks->setRowCount(0);
                ui->tableWidgetLinks->setColumnCount(0);
            }
        }

        /// @todo Allow merging of lexical data.
        /// @todo Make confirmation dialog more verbose.
        void ConfigurationDialog::on_btnLingSerialDo_clicked(){
            const QString l_fileStr = ui->uriLineEdit->text();
            const QString l_lcl = ui->cmbBxLingSaveLocales->currentText ();
            const QStringList l_ndLst = Lexical::Cache::allNodes (l_lcl);
            QFile l_file(l_fileStr);
            QDomDocument* l_dom = new QDomDocument("Archive");

            if (ui->radioButtonSaving->isChecked ()){
                if (!l_file.open (QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
                    QMessageBox::information (this,"Failed to Create Archive","Failed to open" + l_file.fileName () + "for writing.",QMessageBox::Ok);
                    return;
                }

                QTextStream l_outFile(&l_file);
                QDomElement l_rootElem = l_dom->createElement ("Archive");
                l_rootElem.setAttribute ("locale",l_lcl);
                l_dom->appendChild (l_rootElem);

                QProgressDialog l_prg("Saving lexical information..","Cancel",0,l_ndLst.length (),this);
                l_prg.setValue (1);
                foreach(const QString l_nd, l_ndLst){
                    QDomElement l_newEle = l_dom->createElement ("Data");
                    Lexical::Data l_dt(l_nd,l_lcl);
                    Lexical::Cache::read (l_dt);
                    l_prg.setLabelText ("Saving symbol '" + l_dt.symbol () + "'..." );
                    qDebug() << "(gui) [ConfigUi] Saving" << l_dt.symbol() << "...";

                    Lexical::DomSaveModel l_svMdl(&l_newEle);
                    l_svMdl.saveFrom (l_dt);
                    l_rootElem.appendChild (l_newEle);
                    l_prg.setValue (l_prg.value () + 1);
                }

                l_dom->save (l_outFile,4);
            } else if (ui->radioButtonLoading->isChecked ()){
                if (!l_file.exists ()){
                    QMessageBox::information (this,"Archive not Found","Failed to find" + l_file.fileName () + "for reading.",QMessageBox::Ok);
                    return;
                }

                if (!l_dom->setContent (&l_file)){
                    QMessageBox::information (this,"Unable to Save Archive","Failed to parse" + l_file.fileName() + "for transversing.",QMessageBox::Ok);
                }

                QDomNodeList l_elemLst = l_dom->documentElement ().elementsByTagName ("Data");
                QProgressDialog l_prg("Loading lexical information...","Cancel",0,l_elemLst.length (),this);
                for (int i = 0; i < l_elemLst.length (); i++){
                    QDomElement l_elem = l_elemLst.at (i).toElement ();
                    Lexical::Data l_dt;
                    Lexical::DomLoadModel l_ldMdl(&l_elem);
                    l_ldMdl.loadTo (l_dt);
                    qDebug() << "(gui) [ConfigUi] Loading" << l_dt.symbol() << "...";
                    l_prg.setLabelText ("Loading symbol '" + l_dt.symbol () + "'..." );

                    if (Lexical::Cache::exists (l_dt)){
                        QMessageBox l_ques(QMessageBox::Question,"Node Exists",("Do you want to overwrite, merge or skip the external data for locally found symbol '" + l_dt.symbol () + "'?"));
                        l_ques.setInformativeText ("The symbol '" + l_dt.symbol () + "' already has information stored locally.");
                        l_ques.addButton("Overwrite",QMessageBox::DestructiveRole);
                        l_ques.addButton("Merge",QMessageBox::ActionRole);
                        l_ques.addButton("Skip",QMessageBox::RejectRole);

                        if (l_ques.exec ())
                            Lexical::Cache::write (l_dt);
                    }

                    l_prg.setValue (i + 1);
                }
            }
        }

        void ConfigurationDialog::on_btnLingSaveURI_clicked() {
            QFileDialog l_dlg(this,"Location of archive");
            l_dlg.setFileMode (QFileDialog::AnyFile);
            l_dlg.setDefaultSuffix (".xml");
            if (l_dlg.exec ())
                ui->uriLineEdit->setText(l_dlg.selectedFiles ().at (0));
            else
                ui->uriLineEdit->clear ();
        }

        void ConfigurationDialog::on_checkBoxEnabled_clicked(){
            const QString& l_uuid = ui->listWidgetPlugins->item(ui->listWidgetPlugins->currentRow())->data(0).toString();
            const bool l_val = (ui->checkBoxEnabled->checkState() == Qt::Checked);
            Plugins::Factory::setAttribute(l_uuid,"Version/Enabled",l_val);
            qDebug() << Plugins::Factory::attribute(l_uuid,"Version/Enabled") << l_val;
        }

        void ConfigurationDialog::on_checkBoxAutoStart_clicked(){
            const QString& l_uuid = ui->listWidgetPlugins->item(ui->listWidgetPlugins->currentRow())->data(0).toString();
            QSettings* l_settings = new QSettings("Synthetic Intellect Institute","Wintermute");
            QStringList l_plgnLst = l_settings->value("Plugins/AutoStart").toStringList();

            if (ui->checkBoxAutoStart->checkState() == Qt::Checked)
                l_plgnLst << l_uuid;
            else
                l_plgnLst.removeAll(l_uuid);

            qDebug() << "(gui) [ConfigurationDialog] Removed" << l_plgnLst.removeDuplicates() << "duplicates.";
            l_settings->setValue("Plugins/AutoStart",l_plgnLst);
            qDebug() << l_plgnLst;
        }


        void ConfigurationDialog::on_listWidgetPlugins_itemSelectionChanged() {
            QSettings* l_settings = new QSettings("Synthetic Intellect Institute","Wintermute");
            const QStringList l_plgnLst = l_settings->value("Plugins/AutoStart").toStringList();

            const QString& l_uuid = ui->listWidgetPlugins->item(ui->listWidgetPlugins->currentRow())->data(0).toString();
            ui->lblVersion->setText(Plugins::Factory::attribute(l_uuid,"Version/Plugin").toString());
            ui->lblName->setText(Plugins::Factory::attribute(l_uuid,"Description/Name").toString());
            ui->lblVendor->setText(Plugins::Factory::attribute(l_uuid,"Description/Vendor").toString());
            ui->lblAuthor->setText(Plugins::Factory::attribute(l_uuid,"Description/Author").toString());
            ui->lblWebPage->setText(Plugins::Factory::attribute(l_uuid,"Description/WebPage").toString());
            ui->txtDescription->setText(Plugins::Factory::attribute(l_uuid,"Description/Blurb").toString());

            if (Plugins::Factory::attribute(l_uuid,"Plugin/Type") == "Backend")
                ui->checkBoxAutoStart->setEnabled(false);
            else
                ui->checkBoxAutoStart->setEnabled(true);

            ui->checkBoxAutoStart->setChecked(l_plgnLst.contains(l_uuid));
            ui->checkBoxEnabled->setChecked(Plugins::Factory::attribute(l_uuid,"Plugin/Enabled").toBool());
        }

        void ConfigurationDialog::on_pushButtonPlgnActn_clicked() {
            const QString& l_str = ui->comboBoxAction->currentText();
            const QString& l_uuid = ui->listWidgetPlugins->item(ui->listWidgetPlugins->currentRow())->data(0).toString();

            if (l_str == "Start"){
                QDBusMessage l_callStart = QDBusMessage::createMethodCall ("org.thesii.Wintermute","/Factory","org.thesii.Wintermute.Factory","loadPlugin");
                l_callStart << l_uuid;
                QDBusConnection::sessionBus ().call(l_callStart,QDBus::BlockWithGui);
            } else if (l_str == "Stop"){
                QDBusMessage l_callStop = QDBusMessage::createMethodCall ("org.thesii.Wintermute","/Factory","org.thesii.Wintermute.Factory","unloadPlugin");
                l_callStop << l_uuid;
                QDBusConnection::sessionBus ().call(l_callStop,QDBus::BlockWithGui);
            } else if (l_str == "Restart") {
                QDBusMessage l_callStart = QDBusMessage::createMethodCall ("org.thesii.Wintermute","/Factory","org.thesii.Wintermute.Factory","loadPlugin");
                QDBusMessage l_callStop = QDBusMessage::createMethodCall ("org.thesii.Wintermute","/Factory","org.thesii.Wintermute.Factory","unloadPlugin");
                l_callStart << l_uuid;
                l_callStop << l_uuid;
                QDBusConnection::sessionBus ().call(l_callStop,QDBus::BlockWithGui);
                QDBusConnection::sessionBus ().call(l_callStart,QDBus::BlockWithGui);
            }

            on_tabWidget_currentChanged(3);
        }

        ConfigurationDialog::~ConfigurationDialog(){
            delete ui;
        }

        void ConfigurationDialog::changeEvent(QEvent *e){
            QDialog::changeEvent(e);
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
