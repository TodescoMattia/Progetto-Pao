#include "tabdialog.h"
#include <QtWidgets>

TabDialog::TabDialog(QWidget *parent) : QDialog(parent) {

  tabWidget = new QTabWidget;
  tabWidget->addTab(new ArchiveTab, tr("Archive"));
  tabWidget->addTab(new UserTab, tr("User"));
  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok

                                   | QDialogButtonBox::Cancel);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(tabWidget);
  mainLayout->addWidget(buttonBox);
  setLayout(mainLayout);
}

ArchiveTab::ArchiveTab(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *mainLayout = new QVBoxLayout;
  setLayout(mainLayout);
}

UserTab::UserTab(QWidget *parent) : QWidget(parent) {

  QVBoxLayout *mainLayout = new QVBoxLayout;
  setLayout(mainLayout);
}
