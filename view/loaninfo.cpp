#include <QVBoxLayout>

#include "loaninfo.h"

LoanInfo::LoanInfo(Loan &loan) : loan(loan) {
  widget = new QWidget();

  QVBoxLayout *loanInfo = new QVBoxLayout(widget);
  loanInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  idLabel = new QLabel("Id: " + QString::fromStdString(loan.getCodLoan()));
  loanInfo->addWidget(idLabel);

  startDateLabel = new QLabel(
      "Data inizio: " + QString::fromStdString(toString(loan.getStartDate())));
  loanInfo->addWidget(startDateLabel);

  endDateLabel = new QLabel(
      "Data fine: " + QString::fromStdString(toString(loan.getEndDate())));
  loanInfo->addWidget(endDateLabel);

  userLabel = new QLabel("Numero utente: " +
                         QString::number(loan.getUser()->getNumber()));
  loanInfo->addWidget(userLabel);

  itemLabel = new QLabel("Codice oggetto: " +
                         QString::fromStdString(loan.getItem()->getId()));
  loanInfo->addWidget(itemLabel);
}

QWidget *LoanInfo::getWidget() const { return widget; }
