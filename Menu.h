void applyMenuChoice(int menuchoice){
       int remaining = 20;
       int column;      
       struct Party party = initParty();
       switch(menuchoice){
           case 1:                            
               startParty();
               while(remaining > 0 && column!=9){
                displayGrid(party.grid);    
                printf("Joueur 1 - Number of column : \n");
                scanf("%d",&column);
                party.grid = addTokenInColum(party.grid,party.player1,column);
                printf("************Cherche 4*************** : %d  ***************\n",cherche4(party.grid));
                displayGrid(party.grid);                
                remaining--;
                printf("Joueur 2 - Number of column : \n");
                scanf("%d",&column);
                party.grid = addTokenInColum(party.grid,party.player2,column);
                printf("************Cherche 4*************** : %d  ***************\n",cherche4(party.grid)); 
                displayGrid(party.grid);
                remaining--;
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
}

