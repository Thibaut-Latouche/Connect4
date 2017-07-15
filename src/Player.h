struct Player{
        char nickname[50];        
        char token;
};

struct Player initPlayer(char nickname[50], char token){
        struct Player player;
        for(int i=0;i<50;i++){
            player.nickname[i]=nickname[i];    
        }        
        player.token=token;
        return player;
}