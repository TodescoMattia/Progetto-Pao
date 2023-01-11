#include "deleteview.h"
#include <QWidget>
#include <Qlabel>
#include <QHBoxLayout>

DeleteView::DeleteView()
{
    QWidget* deleteW= new QWidget();

    QHBoxLayout* deleteBox = new QHBoxLayout(deleteW);

    QLabel* label = new QLabel("Eliminato");
    deleteBox->addWidget(label);

    deleteW->show();




}
