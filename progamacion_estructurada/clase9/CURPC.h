
/*

PI  | RP | PI | RP // PI: Palabra inconveniente RP: Remplazar por
1 BACA BXCA LOCO LXCO
2 BAKA BXKA LOKA LXKA
3 BUEI BXEI LOKO LXKO
4 BUEY BXEY MAME MXME
5 CACA CXCA MAMO MXMO
6 CACO CXCO MEAR MXAR
7 CAGA CXGA MEAS MXAS
8 CAGO CXGO MEON MXON
9 CAKA CXKA MIAR MXAR
0 CAKO CXKO MION MXON
1 COGE CXGE MOCO MXCO
2 COGI CXGI MOKO MXKO
3 COJA CXJA MULA MXLA
4 COJE CXJE MULO MXLO
5 COJI CXJI NACA NXCA
6 COJO CXJO NACO NXCO
7 COLA CXLA PEDA PXDA
8 CULO CXLO PEDO PXDO
9 FALO FXLO PENE PXNE
0 FETO FXTO PIPI PXPI
1 GETA GXTA PITO PXTO
2 GUEI GXEI POPO PXPO
3 GUEY GXEY PUTA PXTA
4 JETA JXTA PUTO PXTO
5 JOTO JXTO QULO QXLO
6 KACA KXCA RATA RXTA
7 KACO KXCO ROBA RXBA
8 KAGA KXGA ROBE RXBE
9 KAGO KXGO ROBO RXBO
0 KAKA KXKA RUIN RXIN
1 KAKO KXKO SENO SXNO
2 KOGE KXGE TETA TXTA
3 KOGI KXGI VACA VXCA
4 KOJA KXJA VAGA VXGA
5 KOJE KXJE VAGO VXGO
6 KOJI KXJI VAKA VXKA
7 KOJO KXJO VUEI VXEI
8 KOLA KXLA VUEY VXEY
9 KULO KXLO WUEI WXEI
0 LILO LXLO WUEY WXEY
1 LOCA LXCA

*/

void cambiarpalabra(char cadena[]){
  
     char palabraProhibida[81][5] = {"BACA",
                                  "BAKA",
                                  "BUEI",
                                  "BUEY",
                                  "CACA",
                                  "CACO",
                                  "CAGA",
                                  "CAGO",
                                  "CAKA",
                                  "CAKO",
                                  "COGE",
                                  "COGI",
                                  "COJA",
                                  "COJE",
                                  "COJI",                              
                                  "COJO",
                                  "COLA",
                                  "CULO",
                                  "FALO",
                                  "FETO",
                                  "GETA",
                                  "GUEI",
                                  "GUEY",
                                  "JETA",
                                  "JOTO",
                                  "KACA",
                                  "KACO",
                                  "KAGA",
                                  "KAGO",
                                  "KAKA",
                                  "KAKO",
                                  "KOGE",
                                  "KOGI",   
                                  "KOJA",
                                  "KOJE",
                                  "KOJI",
                                  "KOJO",
                                  "KOLA",
                                  "KULO",
                                  "LILO",
                                  "LOCA",
                                  "LOCO",
                                  "LOKA",
                                  "LOKO",
                                  "MAME",
                                  "MAMO",
                                  "MEAR",
                                  "MEAS",
                                  "MEON",
                                  "MIAR",
                                  "MION",
                                  "MOCO",
                                  "MOKO",
                                  "MULA",
                                  "MULO",
                                  "NACA",
                                  "NACO",
                                  "PEDA",
                                  "PEDO",
                                  "PENE",
                                  "PIPI",
                                  "PITO",
                                  "POPO",
                                  "PUTA",
                                  "PUTO",
                                  "QULO",
                                  "RATA",
                                  "ROBA",
                                  "ROBE",
                                  "ROBO",
                                  "RUIN",
                                  "SENO",
                                  "TETA",
                                  "VACA",
                                  "VAGA",
                                  "VAGO",
                                  "VAKA",
                                  "VUEI",
                                  "VUEY",
                                  "WUEI",
                                  "WUEY"};
     
     int i;
     int j;
     int k = 0;
     
     for(i = 0; i < 82; i++){
          k = 0;
          for(j = 0; j < 5; j++){
               if(cadena[j] == palabraProhibida[i][j]){
                    k++;
               }
          }
          
          if(k == 4){
               cadena[1] = 'X';
          }
     }
     
}