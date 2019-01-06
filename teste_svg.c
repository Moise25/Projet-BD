#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE 1000
int main(void){
  char delete_racine[TAILLE], entity[TAILLE], attribute1[TAILLE], attribute2[TAILLE], attribute3[TAILLE];
  FILE *file = fopen("resultat_extraction_xml", "r");
  FILE *svg = fopen("fic_version_beta.svg", "a+");

  if(file==NULL) exit(1);

  if(svg==NULL) exit(1);

  rewind(file), rewind(svg);

  fgets (delete_racine, TAILLE, file);

  fgets (entity, TAILLE, file);

  fgets (attribute1, TAILLE, file);
  fgets (attribute2, TAILLE, file);
  fgets (attribute3, TAILLE, file);

  fputs("<?xml version=\"1.0\" standalone=\"no\" ?>\n<!DOCTYPE svg PUBLIC",svg); //Prologue et debut definition DTD public
  fseek(svg,0, SEEK_END);
  fputs(" \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">", svg);

                                        //Corps du schema xml
  fputs("\n<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">",svg);

  fputs("\n<title>MCD</title>", svg);

                                        //Premier entité
  fputs("\n\n<rect x=\"10\" y=\"180\" width=\"100\" height=\"100\" style=\"fill:white; stroke:black;\" /> ", svg);
  fputs("\n<path d=\"M10,200 l100,0\" style=\"stroke:black;\" />", svg);
  fputs("\n<text x=\"30\" y=\"195\" style=\"font-size:18px;\">", svg);
  fputs (entity, svg);
  fputs("\n\t<tspan x=\"20\" dy=\"20\">", svg);
  fputs(attribute1, svg);
  fputs("</tspan>", svg);
  fputs("\n\t<tspan x=\"20\" dy=\"18\">", svg);
  fputs(attribute2, svg);
  fputs("</tspan>", svg);
  fputs("\n\t<tspan x=\"20\" dy=\"18\">", svg);
  fputs(attribute3, svg);
  fputs("</tspan>", svg);
  fputs("\n</text>", svg);

                                        //lien reliant entité1 association et entité2
  fputs("\n<path d=\"M110,230 l90,0\" style=\"stroke:black;\" />", svg);

                                        //Deuxieme entité
  fputs("\n\n<rect x=\"390\" y=\"180\" width=\"100\" height=\"100\" style=\"fill:white; stroke:black;\" />", svg);
  fputs("\n<path d=\"M390,200 l100,0\" style=\"stroke:black;\" />", svg);
  fputs("\n<path d=\"M300,230 l90,0\" style=\"stroke:black;\" />", svg);
  fputs("\n<text x=\"410\" y=\"195\" style=\"font-size:18px;\">", svg);
  fputs (entity, svg);
  fputs("\n\t<tspan x=\"400\" dy=\"20\">", svg);
  fputs(attribute1, svg);
  fputs("</tspan>", svg);
  fputs("\n\t<tspan x=\"400\" dy=\"18\">", svg);
  fputs(attribute2, svg);
  fputs("</tspan>", svg);
  fputs("\n\t<tspan x=\"400\" dy=\"18\">", svg);
  fputs(attribute3, svg);
  fputs("</tspan>", svg);
  fputs("\n</text>", svg);

                                       //Association
  fputs("\n\n<ellipse cx=\"250\" cy=\"230\" rx=\"50\" ry=\"30\" style=\"fill:white; stroke:black;\"/>", svg);
  fputs("\n<text x=\"218\" y=\"235\" style=\"font-size:18px;\">relation</text>", svg);

                                        //Cardinalité
  fputs("\n\n<text x=\"110\" y=\"225\" style=\"font-size:18px;\">(n,n)</text>", svg);

  fputs("\n\n<text x=\"352\" y=\"225\" style=\"font-size:18px;\">(n,n)</text>", svg);

  fputs("\n</svg>", svg);


  fclose(file);
  fclose(svg);

  return 0;
}
