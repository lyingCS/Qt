#include "modelex.h"

ModelEx::ModelEx()
{
    armyMap[1]="air force";
    armyMap[2]="navy";
    armyMap[3]="army";
    armyMap[4]="marines";
    weaponTypeMap[1]="bomber";
    weaponTypeMap[2]="warcraft";
    weaponTypeMap[3]="aircraft carrier";
    weaponTypeMap[4]="destroyer";
    weaponTypeMap[5]="helicopter";
    weaponTypeMap[6]="tank";
    weaponTypeMap[7]="amphibious assault ships";
    weaponTypeMap[8]="amphibious tanks";
    populationModel();
}

void ModelEx::populationModel()
{
    header<<"army"<<"weaponType"<<"weapon";
    army<<1<<2<<3<<4<<2<<4<<3<<1;
    weaponType<<1<<3<<5<<7<<4<<8<<6<<2;
    weapon<<"B-2"<<"Nimitz"<<"Apache"<<"Hornets"<<"Ali Parker"<<"AAAV"<<"M1A1"<<"F-22";
}

int ModelEx::columnCount(const QModelIndex &parent) const
{
    return 3;
}

int ModelEx::rowCount(const QModelIndex &parent) const
{
    return army.size();
}

QVariant ModelEx::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(role==Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0:
            return armyMap[army[index.row()]];
            break;
        case 1:
            return weaponTypeMap[weaponType[index.row()]];
            break;
        case 2:
            return weapon[index.row()];
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant ModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole&&orientation==Qt::Horizontal)
        return header[section];
    return QAbstractTableModel::headerData(section,orientation,role);
}































