
#include <stdlib.h>
#include "Administrator.h"

Administrator* createAdministrator(char* administratorName, char* administratorLastName, int administratorID, char** movies, int capacity){
    Administrator* result = malloc(sizeof(Administrator));

    result->administratorName=administratorName;
    result->administratorLastName=administratorLastName;
    result->administratorID=administratorID;

    result->clientAmount=0;
    result->rentalAmount=0;
    result->rMAmount=0;
    result->clientCapacity=capacity;
    result->rentalCapacity=capacity;
    result->rMCapacity=capacity;

    result->movies=malloc(sizeof(movies));
    result->movieAmount= sizeof(movies);
    result->movieCapacity= sizeof(movies)*2;
    result->movies=movies;

    return result;
}

void registeredClient(Administrator* administrator, Client* client){
    administrator->clients[administrator->clientAmount]=client;
    administrator->clientAmount++;
}

Rental* rentalMovie(Administrator* administrator, Client* client, char* movieName, char* rentalDate, char* returnDate){
    Rental* result = createRental(movieName, client->clientID,rentalDate, returnDate);
    administrator->rentedMovies[administrator->rMAmount]= movieName;
    administrator->rMAmount++;
    return result;
}
void getMovieBack(Administrator* administrator, Rental* rental){
    for(int i = 0; i < administrator->rMAmount; i++){
        if(administrator->rentedMovies[i]==rental->movieName){
            free(administrator->rentedMovies[i]);
            for(; i < administrator->rMAmount-1; i++){
                administrator->rentedMovies[i] = administrator->rentedMovies[i+1];
            }
            administrator->rMAmount--;
            break;
        }
    }
}

int checkMovieAvailability(Administrator* administrator, char* movieName){
    for(int i = 0; i < administrator->rMAmount; i++){
        if(administrator->rentedMovies[i]==movieName){
            return 1;
        }
    }
    return 0;
}

void freeAdministrator(Administrator* administrator){
    for(int i=0; i< administrator->clientAmount; i++){
        free(administrator->clients[i]);
    }
    for(int i=0; i< administrator->rMAmount; i++){
        free(administrator->rentedMovies[i]);
    }
    for(int i=0; i< administrator->rentalAmount; i++){
        free(administrator->rentals[i]);
    }
    for(int i=0; i< administrator->movieAmount; i++){
        free(administrator->movies[i]);
    }
    free(administrator->administratorName);
    free(administrator->administratorLastName);
    free(administrator);
}