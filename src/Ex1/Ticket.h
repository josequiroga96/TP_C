
#ifndef TP_C_TICKET_H
#define TP_C_TICKET_H

#include "LineTicket.h"

typedef struct ticket Ticket;

struct ticket{
    int id;

    LineTicket** lineTickets;
    int lineTicketCapacity;
    int lineTicketAmount;
};

Ticket* createTicket(int id, int lineCartCapacity);
void addLine(Ticket* ticket, LineTicket* lineTicket);
void freeTicket(Ticket* ticket);

#endif //TP_C_TICKET_H
