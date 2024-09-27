#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Person{
    int id;
    int speed;
    struct Person* next;
}Person;

Person updatePerson(int id, int speed){
    Person newPerson = {id, speed, NULL};
    return newPerson;
}

void addPerson(Person** start, Person* new) {
    
    if (*start == NULL) {
        *start = new;
        new->next = *start;
    } else {
        Person* current = *start;

        for(; current->next != *start ; current = current->next);
        
        current->next = new;
        new->next = *start;
    }

}


// Returns the winner
Person* play(Person* start) {
    Person* current = start;
    Person* win = start;

    while(current->next != start){
        current = current->next;
    }

    current->next = start;

    while(win != win->next){
        current = win;

        //duck duck
        for(int n=0 ; n<win->id ; n++){
            current = current->next;

            if(win == current){
                current = current->next;
            }

            printf("%d duck %d\n", win->id,current->id);
        }
        
        //goose
        Person* g = current->next;
        if(g == win){
            g = win->next;
        }
        printf("%d goose! %d\n", win->id, g->id);

        //checking speeds
        if(win->speed < g->speed){
            current = win;
            while(current->next != win){
                current = current->next;
            }
            current->next = win->next;
            free(win);
            win = g;
        }else{ 
            while(current->next != g){
                current = current->next;
            }
            current->next = g->next;
            free(g);
        }
    }

    printf("winner! %d\n", win->id);
    return win->next;
}

// int main(){
//     int p, s;

//     // List of people
//     Person* lop = NULL;

//     // Read in participants
//     while (scanf("%d %d", &p, &s) == 2){
//         Person* np = (Person*)malloc(sizeof(Person));
//         *np = updatePerson(p, s);
//         addPerson(&lop, np);
//     }

//     Person* winner = play(lop);
//     free(winner);
// }