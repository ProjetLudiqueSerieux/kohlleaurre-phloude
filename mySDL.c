/**
*\file mySDL.c
*\author Rémi Faure-Gignoux
*\date 02/05/2017
*\brief desrciption de mySDL.c
*/

#include <SDL/SDL.h>
#include "grille.h"
#include "tache.h"
#include <time.h>

/*
 compilation soous Linux : gcc -o mySDL mySDL.c -lSDL
 compilation sur Mac : gcc -o mySDL -I/Library/Frameworks/SDL.framework/Headers  mySDL.c SDLmain.m -framework SDL -framework Cocoa
*/

int autoDraw=0;
/**
*\fn drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b)
*\brief dessine un rectangle avec les dimension et la couleur souhaitées
*\param ecran
*\param px abscisse du point en haut à gauche du carré à dessiner 
*\param py ordonnée du point en haut à gauche du carré à dessiner 
*\param size côté du carré à dessiner
*\param r pour le rouge
*\param g pour le vert
*\param b pour le bleu
*\return void
*/
// px, py coordonnées haut, gauche du pixel
void drawRectangle(SDL_Surface *ecran, int px, int py, int size, int r, int g, int b) {
    SDL_Rect rect;
    rect.x=px;
    rect.y=py;
    rect.h=rect.w=size;
    SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, r, g, b));
    SDL_Flip(ecran);
}




/**
*\fn color_rect(SDL_Surface *ecran, int taille, int i, int j, int c)
*\brief on colorie le rectangle de la couleur choisie
*\param ecran
*\param taille la taille du carré à colorier
*\param i défini position
*\param j défini position
*\param c couleur
*\return void
*/
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
  int res = 1;
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




/***************************************
 *****************MAIN******************
 ***************************************/



int main() {
  srand(time(NULL));
	int continuer = 1;
	SDL_Surface *ecran = NULL;
	SDL_Event event;
    const SDL_VideoInfo* info = NULL;
    SDL_Surface *ima=NULL;

    int n;
    printf("Choisissez la taille du tableau (un entier) : ");
    n = demande_int();
    int taille = 250/n;

    int taille_reelle_tab = taille * n;
    int taille_case_bas = taille_reelle_tab / 6 -2;

    int**tab = creer_grille(n);
    alea_init(tab, n);
    int** tache = init_tache(tab,n);
    int taille_tache = cher_taille_tache(tache);







    int test1,test2,test3;
    
			for (test1=0;test1<n;test1++)
			  {
			    for (test2=0;test2<n;test2++)
			      fprintf(stderr, "%d ", tab[test2][test1]);
			    fprintf(stderr,"\n");
			  }
			


			
			fprintf(stderr,"taille tache : %d\n", taille_tache);

			
			for(test3=0;test3<taille_tache; test3++)
			  {
			    fprintf(stderr,"(%d , %d) ", tache[test3][0], tache[test3][1]);
			  }
			fprintf(stderr,"\n");
			





    
    
    
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
                    fprintf(stderr,"%d %d -> %d %d %d\n",y, x, p[2], p[1], p[0]);
		    int i, j;
		    				   
		    if (p[0] || p[1] || p[2])
		      {
			if(p[0]==200)
			  {
			    chang_coul(tab, tache, taille_tache, 3);
			    fprintf(stderr, "ça marche\n");
			    maj_tache(tab, taille, tache, &taille_tache, 3);
			    fprintf(stderr, "ça marche\n");
			    //chang_coul(tab, tache, taille_tache, 3);
			  }
			else if (p[1]==125)
			  {
			    chang_coul(tab, tache, taille_tache, 5);
			    fprintf(stderr, "ça marche\n");
			    maj_tache(tab, taille, tache, &taille_tache, 5);
			    fprintf(stderr, "ça marche\n");
			    //chang_coul(tab, tache, taille_tache, 5);
			  }
			else if (p[2]==0)
			  {
			    chang_coul(tab, tache, taille_tache, 1);
			    fprintf(stderr, "ça marche\n");
			    maj_tache(tab, taille, tache, &taille_tache, 1);
			    fprintf(stderr, "ça marche\n");
			    //chang_coul(tab, tache, taille_tache, 1);
			  }
			else if (p[1]==255)
			  {
			    chang_coul(tab, tache, taille_tache, 4);
			    fprintf(stderr, "ça marche\n");
			    maj_tache(tab, taille, tache, &taille_tache, 4);
			    fprintf(stderr, "ça marche\n");
			    //chang_coul(tab, tache, taille_tache, 4);
			  }
			else if (p[0]==255)
			  {
			    chang_coul(tab, tache, taille_tache, 2);
			    fprintf(stderr, "ça marche\n");
			    maj_tache(tab, taille, tache, &taille_tache, 2);
			    fprintf(stderr, "ça marche\n");
			    //chang_coul(tab, tache, taille_tache, 2);
			  }
			else
			  {
			    chang_coul(tab, tache, taille_tache, 0);
			    fprintf(stderr, "ça marche\n");
			    maj_tache(tab, taille, tache, &taille_tache, 0);
			    fprintf(stderr, "ça marche\n");
			    //chang_coul(tab, tache, taille_tache, 0);
			    }






			

			for (test1=0;test1<n;test1++)
			  {
			    for (test2=0;test2<n;test2++)
			      fprintf(stderr, "%d ", tab[test2][test1]);
			    fprintf(stderr,"\n");
			  }
			


			
			fprintf(stderr,"taille tache : %d\n", taille_tache);

			
			for(test3=0;test3<taille_tache; test3++)
			  {
			    fprintf(stderr,"(%d , %d) ", tache[test3][0], tache[test3][1]);
			  }
			fprintf(stderr,"\n");






			
			
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
                    drawRectangle(ecran, event.button.x, event.button.y, 260, 0, 255, 0);
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
