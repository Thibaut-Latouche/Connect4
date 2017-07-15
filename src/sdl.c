#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "Cases.h"
#include "Player.h"
#include "Grid.h"
#include "Party.h"
#include "Menu.h"

void refreshWindow(struct Party party,SDL_Rect position, SDL_Surface *rectangle, SDL_Surface *ecran);
 
int main(int argc, char *argv[])
{    
    SDL_Surface *ecran = NULL;
    SDL_Surface *rectangle = NULL;
    SDL_Rect position;
    SDL_Event event; 
    Party party;
    int continuer = 1;
    int partyEnding = 0;
    
    party = initParty();    
    
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL 
    ecran = SDL_SetVideoMode(590, 380, 32, SDL_HWSURFACE);
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 70, 40, 32, 0, 0, 0, 0);    
    SDL_WM_SetCaption("Puissance 4", NULL);    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 44, 15, 189));

    
    //Initialisation de la grille
    refreshWindow(party,position,rectangle,ecran);
    Player playerActif = party.player1;
    
    //Jouer au clavier
    while(continuer){
        SDL_WaitEvent(&event);
        
        if(partyEnding==0){
        switch(event.type)
        {
            case SDL_KEYDOWN: /* Si appui sur une touche */                         
                switch(event.key.keysym.sym){
                    case SDLK_a:
                        party.grid = addTokenInColum(party.grid,playerActif,0);
                        break;
                    case SDLK_z:                        
                        party.grid = addTokenInColum(party.grid,playerActif,1);
                        break;
                    case SDLK_e:
                        party.grid = addTokenInColum(party.grid,playerActif,2);
                        break;
                    case SDLK_r:
                        party.grid = addTokenInColum(party.grid,playerActif,3);
                        break;
                    case SDLK_t:
                        party.grid = addTokenInColum(party.grid,playerActif,4);
                        break;
                    case SDLK_y:
                        party.grid = addTokenInColum(party.grid,playerActif,5);
                        break;
                    case SDLK_u:
                        party.grid = addTokenInColum(party.grid,playerActif,6);
                        break;                    
                    case SDLK_s:
                        saveParty(party);
                        continuer=0;
                        break;                    
                    case SDLK_l:
                        party = loadParty();
                        displayGrid(party.grid);
                        break;
                } 
                
                if(cherche4(party.grid)){
                        partyEnding = 1;
                        printf("%s gagne la partie\n", playerActif.nickname); 
                 }                
                 if(playerActif.token==party.player2.token){
                    playerActif=party.player1;
                }else{        
                    playerActif=party.player2;

                }                
                
            refreshWindow(party,position,rectangle,ecran);                
            
            break;
            
            case SDL_QUIT:
                continuer = 0;
                break;
            
        }
        
        }else{//Fin de la partie
            switch(event.type){
            case SDL_KEYDOWN: /* Si appui sur une touche */                         
                switch(event.key.keysym.sym){
                    case SDLK_n:                        
                        party = initParty();
                        partyEnding = 0;
                        break;
                }                            
                refreshWindow(party,position,rectangle,ecran);                            
            break;
            
            case SDL_QUIT:
                continuer = 0;
                break;
        }
                
        }
        
        
    }       
    SDL_Quit(); 
    return EXIT_SUCCESS; 
}

void refreshWindow(struct Party party,SDL_Rect position, SDL_Surface *rectangle, SDL_Surface *ecran){
    for(int i=0;i<party.grid.height;i++){
        for(int j=0;j < party.grid.width; j++){
            position.x = 10 + ((70 + 10) * j); 
            position.y = 10 + ((40 + 10) * i); 
            switch(party.grid.cases[i][j].value){
                case 'x':
                    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 189, 15, 15)); 
                    break;
                case 'o':
                    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 0)); 
                    break;
                default:
                    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); 
            }
            SDL_BlitSurface(rectangle, NULL, ecran, &position); 
        }
    }        
    SDL_Flip(ecran);
}