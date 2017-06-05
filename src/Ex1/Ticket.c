
#include <stdlib.h>
#include "Ticket.h"

Ticket* createTicket(int id, int lineCartCapacity){
    Ticket* result = malloc(sizeof(Ticket));

    result->id=id;
    result->lineTicketCapacity=lineCartCapacity;
    result->lineTicketAmount=0;

    result->lineTickets= malloc(sizeof(LineTicket*)*result->lineTicketCapacity);

    return result;
}

static void grow(Ticket* ticket){
    int capacity = (ticket->lineTicketCapacity)*2;
    ticket->lineTickets = realloc(ticket->lineTickets, sizeof(LineTicket*)*capacity);
    ticket->lineTicketCapacity=capacity;
}

void addLine(Ticket* ticket, LineTicket* lineTicket){
    if(ticket->lineTicketCapacity==ticket->lineTicketAmount)
        grow(ticket);
    ticket->lineTickets[ticket->lineTicketAmount]=lineTicket;
    ticket->lineTicketAmount++;
}

void freeTicket(Ticket* ticket){
    for(int i=0; ticket->lineTicketAmount; i++){
        freeLineTicket(ticket->lineTickets[i]);
    }
    free(ticket);
}