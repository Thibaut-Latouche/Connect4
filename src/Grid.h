struct Grid{
    int width;
    int height;        
    struct Case cases[50][50];
};

struct Grid initGrid(int width,int height){
    struct Grid grid;  
    grid.width=width;
    grid.height=height;
       for(int i=0;i<grid.height;i++){
        for(int j=0;j<grid.width;j++){
                grid.cases[i][j].value='.';
        }        
    }
    return grid;
}

void displayGrid(struct Grid grid){
    printf("\n");
    for(int i=0;i<grid.height;i++){
        for(int j=0;j<grid.width;j++){
                printf(" %c ",grid.cases[i][j].value);
                if(j==(grid.width-1)){
                        printf("\n");
                }
        }        
    }
    printf("\n");
}

struct Grid addTokenInColum(struct Grid grid, struct Player player, int column){    
    int height = (grid.height-1);
    for(int i=height;i>=0;i--){
        if(grid.cases[i][column].value=='.'){
                height = i;
                break;
        }        
    }    
    grid.cases[height][column].value = player.token;    
    return grid;
}


  int cherche4alignes(int oCol, int oLigne, int dCol, int dLigne, struct Grid grid) {
    char couleur = '.';
    int compteur = 0;
    int curCol = oCol;
    int curRow = oLigne;
    while ((curCol >= 0) && (curCol < 7) && (curRow >= 0) && (curRow < 6)) {
      if (grid.cases[curRow][curCol].value != couleur) {
        couleur = grid.cases[curRow][curCol].value;
        compteur = 1;
      } else {
        compteur++;
      }
      if ((couleur != '.') && (compteur == 4)) {
        return 1;
      }
      curCol += dCol;
      curRow += dLigne;
    }
    return 0;
  }


int cherche4(struct Grid grid) {
    for (int ligne = 0; ligne < grid.height; ligne++) {
      if (cherche4alignes(0, ligne, 1, 0,grid)) {
        return 1;
      }
    }
    for (int col = 0; col < grid.width; col++) {
      if (cherche4alignes(col, 0, 0, 1,grid)) {
        return 1;
      }
    }
    for (int col = 0; col < grid.width; col++) {
      if (cherche4alignes(col, 0, 1, 1,grid)) {
        return 1;
      }      
      if (cherche4alignes(col, 0, -1, 1,grid)) {
        return 1;
      }
    }
    for (int ligne = 0; ligne < grid.height; ligne++) {
      if (cherche4alignes(0, ligne, 1, 1,grid)) {
        return 1;
      }      
      if (cherche4alignes(grid.height - 1, ligne, -1, 1,grid)) {
        return 1;
      }
    }
    return 0;
  }
