#ifndef PLANNINGMODEL_H
#define PLANNINGMODEL_H

#include "orga.h"

#include "../include/precompiled.h"
#include <QStringListModel>

class PlanningModel : public QObject
{
    Q_OBJECT
public:
    PlanningModel();
    void addOrga(Orga orga, bool update = false);
    void removeOrga(Orga orga);
    list_orga getOrgasByName(const QString& search = QString());
list_categorie getCategories();
signals:
    void orgaRefresh();
private:
    list_orga orgas;
    list_categorie categories;

};

#endif // PLANNINGMODEL_H
