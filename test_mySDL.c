#include <SDL/SDL.h>
#include "tache.c"
#include "grille.c"

/*
 compilation soous Linux : gcc -o exSDL exSDL.c -lSDL
 compilation sur Mac : gcc -o exSDL -I/Library/Frameworks/SDL.framework/Headers  exSDL.c SDLmain.m -framework SDL -framework Cocoa
*/

int autoDraw=0;

// px, py coordonnées haut, gauche du pixel
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b) {
    SDL_Rect rect;
    rect.x=px;
    rect.y=py;
    rect.h=rect.w=size;
    SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}

void color_rect(SDL_Surface *ecran, int taille, int i, int j, int c)
{
  if(c==0) drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1 , 255, 0, 0);
  else if (c==1) drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1 , 0, 255, 0);
  else if (c==2) drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1 , 255, 0, 255);
  else if (c==3) drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1 , 0, 125, 200);
  else if (c==4) drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1 , 255, 255, 0);
  else if (c==5) drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1 , 255, 125, 0);
}

void fillScreen(SDL_Surface *ecran, int r, int g, int b) {
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}



void purger()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}


int demande_int()
{
  int res = 0;
  int verif = 'n';
  while(verif == 'n')
    {
      scanf("%i",&res);
      purger();
      printf("Vous avez entré %i. n pour recommencer, o sinon.\n",res);
      verif = getchar();
      purger();
    }
  return res;
}


int main() {
	int continuer = 1;
	SDL_Surface *ecran = NULL;
	SDL_Event event;
    const SDL_VideoInfo* info = NULL;
    SDL_Surface *ima=NULL;

    int n=0;
    printf("Choisissez la taille du tableau (un entier) : ");
    n = demande_int();
    int taille = 250/n;

    int taille_reelle_tab = taille * n;
    int taille_case_bas = taille_reelle_tab / 6 -2;

    int**tab = creer_grille(n);
    alea_init(tab, n);
    int** tache = init_tache(tab,n);
    int taille_tache = cher_taille_tache(tache);
    
    
    // initialisation de la fenêtre d'affichage
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        /* Failed, exit. */
        fprintf( stderr, "Video initialization failed: %s\n", SDL_GetError( ) );
        SDL_Quit( );
    }
    info = SDL_GetVideoInfo( );
    if( !info ) {
        /* This should probably never happen. */
        fprintf( stderr, "Video query failed: %s\n", SDL_GetError( ) );
        SDL_Quit( );
    }
    ecran=SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("exemple SDL", NULL);
    
    fillScreen(ecran, 0,0,0);
    
    while (continuer) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN: // gestion des évènements clavier
            	switch (event.key.keysym.sym) {
            		case SDLK_d:
                        drawRectangle(ecran, 3, 300, taille_case_bas, 255, 0, 0);
                        drawRectangle(ecran, 6 + taille_case_bas, 300, taille_case_bas, 0, 255, 0);
                        drawRectangle(ecran, 9 + 2*taille_case_bas, 300, taille_case_bas, 255, 0, 255);
			drawRectangle(ecran, 12 + 3*taille_case_bas, 300, taille_case_bas, 0, 125, 200);
			drawRectangle(ecran, 15 + 4*taille_case_bas, 300, taille_case_bas, 255, 255, 0);
			drawRectangle(ecran, 18 + 5*taille_case_bas, 300, taille_case_bas, 255, 125, 0);
			
			int abs, ord;
			for (abs=0;abs<n;abs++)
			  {
			    for (ord=0;ord<n;ord++)
			      {
			        color_rect(ecran, taille, abs, ord, tab[abs][ord]);
				  }    
			  }
                        
                        break;
            		case SDLK_e:
                        fillScreen(ecran, 255,0,255);
						break;
                    case SDLK_r:
                        fillScreen(ecran, 0,0,0);
                        
                        break;
            		case SDLK_ESCAPE:
						continuer=0; break;
            	}
            	break;
                
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x,y;
                    x = event.button.x ;
                    y = event.button.y ;
                    int bpp = ecran->format->BytesPerPixel;
                    /* Here p is the address to the pixel we want to retrieve */
                    Uint8 *p = (Uint8 *)ecran->pixels + y*ecran->pitch + x*bpp;
                    fprintf(stderr,"%d %d -> %d %d %d\n",y, x, p[0], p[1], p[2]);
		    int i, j;
		    				   
		    //should be &&
		    if (p[0] || p[1] || p[2])
		      {
			if(p[2]==200) maj_tache(tab, taille, tache, taille_tache, 3);
			else if (p[1]==125) maj_tache(tab, taille, tache, taille_tache, 5);
			else if (p[0]==0) maj_tache(tab, taille, tache, taille_tache, 1);
			else if (p[1]==255) maj_tache(tab, taille, tache, taille_tache, 4);
			else if (p[2]==255) maj_tache(tab, taille, tache, taille_tache, 2);
			else maj_tache(tab, taille, tache, taille_tache, 0);
			 
			for(i=0;i<n;i++)
			  {
			    for(j=0;j<n;j++)
			      {
				if (app_tache(i, j, tache, taille_tache))
				    drawRectangle(ecran, 3 + taille*i, 3 + taille*j, taille-1, p[2], p[1], p[0]);
			      }
			  }
		      }

                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    autoDraw=1;
                    drawRectangle(ecran, event.button.x, event.button.y, 3, 0, 255, 0);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                autoDraw=0;
                if (event.button.button == SDL_BUTTON_LEFT) {
                    //drawRectangle(ecran, event.button.x, event.button.y, 3, 255, 0, 0);
                }
                break;

            case SDL_MOUSEMOTION:
                if (autoDraw)
                    drawRectangle(ecran, event.button.x, event.button.y, 1, 0, 0, 255);
                break;
        }
    }
	SDL_Quit();
    
	return 0;
}
    
