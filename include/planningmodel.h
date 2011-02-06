#ifndef PLANNINGMODEL_H
#define PLANNINGMODEL_H

#include "orga.h"
#include "lieu.h"

#include "../include/precompiled.h"
#include <QStringListModel>

class PlanningModel : public QObject
{
    Q_OBJECT
public:
    PlanningModel();
    void addOrga(Orga orga, bool update = false);
    void removeOrga(Orga orga);

    void addCategorie(Categorie categorie, bool update = false);
    void removeCategorie(Categorie categorie);

    void addEquipe(Equipe equipe, bool update = false);
    void removeEquipe(Equipe equipe);

    void addLieu(Lieu lieu, bool update = false);
    void removeLieu(Lieu lieu);

    list_orga getOrgasByName(const QString& search = QString());
list_categorie getCategories();
list_equipe getEquipes();
list_lieu getLieux();

signals:
    void refresh();
private:
    list_orga orgas;
    list_categorie categories;
    list_equipe equipes;
    list_lieu lieux;

};

#endif // PLANNINGMODEL_H
