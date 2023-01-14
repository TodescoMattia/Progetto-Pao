#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QTabWidget;
QT_END_NAMESPACE

class UserTab : public QWidget {
  Q_OBJECT

public:
  explicit UserTab(QWidget *parent = nullptr);
};

class ArchiveTab : public QWidget {
  Q_OBJECT

public:
  explicit ArchiveTab(QWidget *parent = nullptr);
};

class TabDialog : public QDialog {
  Q_OBJECT

public:
  explicit TabDialog(QWidget *parent = nullptr);

private:
  QTabWidget *tabWidget;
  QDialogButtonBox *buttonBox;
};

#endif
