#include "listwidget.h"
#include "iteminfo.h"
#include "loaninfo.h"
#include "userinfo.h"
#include "..\model\book.h"
#include "..\model\bookSerie.h"
#include "..\model\film.h"
#include "..\model\loan.h"
#include "..\model\user.h"

#include <QVBoxLayout>

ListWidget::ListWidget()
{

    //lista esempio, cancellami

    list.push_front(new ListView(new ItemInfo(*(new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller)))));
    list.push_front(new ListView(new ItemInfo(*(new BookSerie ("111AB6", "Harry Potter", true, "NomeAutore2", 352, Fantasy, 2)))));
    list.push_front(new ListView(new LoanInfo(*(new Loan ("563AB6", 12,5,2012,21,3,2019,
                                                          new User("Mario", "Bianchi", "3458746715"),
                                                          new Book("125576", "Titololibro", true, "NomeAutore", 582, Thriller))))));
    list.push_front(new ListView(new LoanInfo(*(new Loan ("78TYU6", 26,9,2022,3,10,2003,
                                                          new User("Luigi", "Bianchi", "3458586715"),
                                                          new Book("128576", "Titololibro2", true, "NomeAutore2", 582, Thriller))))));
    list.push_front(new ListView(new ItemInfo(*(new Film ("563AB6", "Interstellar", false, "NomeDirettore", 160, Thriller)))));
    list.push_front(new ListView(new UserInfo(*(new User("Mario", "Bianchi", "3458746715")))));


    List<ListView*>::Iterator inizio=list.begin();
    List<ListView*>::Iterator fine=list.end();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    for(inizio=list.begin(), fine=list.end(); inizio!=fine; inizio++){

        layout->addWidget((*inizio)->getWidget());
    }

}
