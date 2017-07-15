/*void applyMenuChoice(int menuchoice){
       int flagEndParty = 0;
       int column;      
       struct Party party = initParty();
       switch(menuchoice){
           case 1:                            
               startParty();
               while(flagEndParty==0 && column!=9){
                displayGrid(party.grid);    
                printf("Joueur 1 - Number of column : \n");
                scanf("%d",&column);
                party.grid = addTokenInColum(party.grid,party.player1,column);
                displayGrid(party.grid);
                if(cherche4(party.grid)){
                        flagEndParty = 1;
                        printf("Joueur 1 gagne la partie\n"); 
                        break;                                 
                }                
                printf("Joueur 2 - Number of column : \n");
                scanf("%d",&column);
                party.grid = addTokenInColum(party.grid,party.player2,column);                
                displayGrid(party.grid);
                if(cherche4(party.grid)){
                        flagEndParty = 1;
                        printf("Joueur 2 gagne la partie\n"); 
                        break;
                }        
              }
              endParty();    
              break;
       }
}


void displayMenu(){
    int menuchoice;
    printf("Tapez 1 - pour commencer une nouvelle party\n");
    scanf("%d",&menuchoice);
    applyMenuChoice(menuchoice);
}*/

