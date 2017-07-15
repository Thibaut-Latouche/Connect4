struct Party{
    struct Player player1;
    struct Player player2;
    struct Grid grid;
};

struct Party initParty();

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

int saveParty(struct Party party){
    FILE* fichier = NULL; 
    fichier = fopen("backup/party.txt", "w"); 
    if (fichier != NULL){
        for(int i=0;i<party.grid.height;i++){
            for(int j=0;j < party.grid.width; j++){
                fputc(party.grid.cases[i][j].value, fichier);            
            }            
        }
        fclose(fichier);
    }
    return 0;
}

struct Party loadParty(){
    Party party = initParty();
    FILE* fichier = NULL; 
    fichier = fopen("backup/party.txt", "r");    
    if (fichier != NULL){
        for(int i=0;i<party.grid.height;i++){
            for(int j=0;j < party.grid.width; j++){               
                char caractereActuel = fgetc(fichier); // On lit le caractère
                printf("%c", caractereActuel); // On l'affiche            
                party.grid.cases[i][j].value = caractereActuel;  
            }            
        }
        fclose(fichier);
    } 
    return party;
}