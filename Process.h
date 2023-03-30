#pragma once
#include "Passenger.h"
#include "Flight.h"
#include "Airplane.h"

using namespace std;

bool LoadAirplane(ListAir &listAir);
bool SaveFlight(PNodeFli First);

bool LoadAirplane(ListAir &listAir) {
    ifstream filein("DSMB.TXT", ios_base::in);

    if (!filein.is_open())
        return false;

    while (!filein.eof())
    {
        PAirplane pAir = new Airplane;
        char str[1000];
        filein.getline(pAir->idAir, sizeof(pAir->idAir), ';');
        filein.getline(pAir->typeAir, sizeof(pAir->typeAir), ';');
        filein.getline(str, sizeof(str), ';');
        pAir->col = atoi(str);
        filein.getline(str, sizeof(str), '\n');
        pAir->row = atoi(str);

        listAir.nodes[listAir.size++] = pAir;
    }
    filein.close();
    return true;
}

bool SaveAirplane(ListAir &listAir)
{
    ofstream file("DSMB.TXT", ios_base::out);

    if (!file.is_open())
        return false;

    for (int i = 0; i < listAir.size; i++)
    {
        file << listAir.nodes[i]->idAir << ";"
             << listAir.nodes[i]->typeAir << ";"
             << listAir.nodes[i]->col << ";"
             << listAir.nodes[i]->row;
        if (i != listAir.size - 1)
            file << endl;
    }
    file.close();
    return true;
}

bool LoadFlight(PNodeFli &First)
{
    ifstream file("DSCB.TXT", ios_base::in);

    if (!file.is_open())
        return false;

    while (!file.eof())
    {
        PNodeFli pNodeFli = new NodeFli;
        char str[1000];
        file.getline(pNodeFli->data.idFlight, sizeof(pNodeFli->data.idFlight), ';');
        file.getline(pNodeFli->data.arrivalAir, sizeof(pNodeFli->data.arrivalAir), ';');
        file.getline(pNodeFli->data.idAir, sizeof(pNodeFli->data.idAir), ';');
        file.getline(str, sizeof(str), '/');
        pNodeFli->data.date.day = atoi(str);
        file.getline(str, sizeof(str), '/');
        pNodeFli->data.date.month = atoi(str);
        file.getline(str, sizeof(str), ',');
        pNodeFli->data.date.year = atoi(str);
        file.getline(str, sizeof(str), ':');
        pNodeFli->data.date.second = atoi(str);
        file.getline(str, sizeof(str), ':');
        pNodeFli->data.date.minute = atoi(str);
        file.getline(str, sizeof(str), ';');
        pNodeFli->data.date.hour = atoi(str);
        file.getline(str, sizeof(str), ';');
        pNodeFli->data.status = atoi(str);

        file.getline(str, sizeof(str), ';');
        pNodeFli->data.ticketList.size = atoi(str);
        for (int i = 0; i < pNodeFli->data.ticketList.size; i++)
        {
            PTicket pTicket = new Ticket;

            file.getline(pTicket->idPass, sizeof(pTicket->idPass), ';');
            file.getline(str, sizeof(str), ';');
            pTicket->col = atoi(str);
            file.getline(str, sizeof(str), ';');
            pTicket->col = atoi(str);
            if (i == pNodeFli->data.ticketList.size - 1)
            {
                file.getline(str, sizeof(str));
            }
            else
            {
                file.getline(str, sizeof(str), ';');
            }
            pTicket->statusTicket = atoi(str);

            pNodeFli->data.ticketList.DSV[pNodeFli->data.ticketList.size++] = pTicket;
        }
        InsertFlight(First, pNodeFli->data);
    }
    file.close();
    return true;
}

bool SaveFlight(PNodeFli First)
{
    ofstream file("DSCB.TXT", ios_base::out);

    if (!file.is_open())
        return false;

    while (First != NULL)
    {
        file << First->data.idFlight << ";"
             << First->data.arrivalAir << ";"
             << First->data.idAir << ";"
             << First->data.date.day << "/"
             << First->data.date.month << "/"
             << First->data.date.year << ","
             << First->data.date.second << ":"
             << First->data.date.minute << ":"
             << First->data.date.hour << ";"
             << First->data.status << ";";
        for (int i = 0; i < First->data.ticketList.size; i++)
        {
            file << First->data.ticketList.DSV[i]->idPass << ";"
                 << First->data.ticketList.DSV[i]->col << ";"
                 << First->data.ticketList.DSV[i]->row << ";"
                 << First->data.ticketList.DSV[i]->statusTicket;
            if (i == First->data.ticketList.size - 1)
            {
                file << endl;
            }
            else
            {
                file << ";";
            }
        }
        First = First->pNext;
    }

    file.close();
    return true;
}

bool LoadPass(TreePass &treePass)
{
    ofstream file("DSHK.TXT", ios_base::out);

    if (!file.is_open())
        return false;

    file.close();
    return true;
}

bool SavePass(TreePass treePass)
{
    ofstream file("DSHK.TXT", ios_base::out);

    if (!file.is_open())
        return false;

    file.close();
    return true;
}
