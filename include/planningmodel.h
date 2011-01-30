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

signals:
    void orgaRefresh();
private:
    list_orga orgas;

};

#endif // PLANNINGMODEL_H
