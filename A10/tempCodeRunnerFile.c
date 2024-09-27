int main(){
    int p, s;

    // List of people
    Person* lop = NULL;

    // Read in participants
    while (scanf("%d %d", &p, &s) == 2){
        Person* np = (Person*)malloc(sizeof(Person));
        *np = updatePerson(p, s);
        addPerson(&lop, np);
    }

    Person* winner = play(lop);
    free(winner);
}