struct Party{
    struct Player player1;
    struct Player player2;
    struct Grid grid;
};

struct Party initParty(){
    struct Player player1; 
    struct Player player2;
    player1 = initPlayer("Joueur 1", 'x');
    player2 = initPlayer("Joueur 2", 'o');
    struct Grid grid;
    grid = initGrid(7,6);
    struct Party party;
    party.player1 = player1;
    party.player2 = player2;
    party.grid = grid;
    return party;
};

void startParty(){
        printf("Party is starting\n\n");
}

void endParty(){
        printf("Party is ending\n\n");
}