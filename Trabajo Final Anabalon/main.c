#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct Jugador{
    char nombre[20];
    double DNI;
    int puntos;
    int puntosHistorico;
    };

struct Respuesta{
    int numRespuesta;
    char respuestas[50];
    int numPreguntaAsociada;
    int correcta;
};

struct Pregunta{
    int numPregunta;
    char pregunta[100];
    struct Respuesta respuestas[4];
};

struct Puntos{
    int actuales;
    int puntosTotal;
};

///Elegir cantidad de Jugadores (2 o 4)
int elegircantidadjugadores();
///Cargar un jugadore de la struct Jugador
struct Jugador cargarJugador();
///Muestra un jugadore de la struct Jugadores
void mostrarJugador(struct Jugador j);
///Cargar los jugadores (2 o 4) que contenga el vector de la struct Jugadores
void cargarJugadores(struct Jugador j[], int t);
///Muestra los jugadores (2 o 4) que contenga el vector de la struct Jugadores
void mostrarJugadores(struct Jugador j[], int t);

/////////Cargar, mostrar preguntas y respuestas Generales//////////////////////////////
///Funcion cargar Preguntas
struct Pregunta cargarPreguntaParametro(int nPre,char pre[100],int posRes,int nRes,char res[100],int nPreRef,int c);
///Funcion que cargar Respuestas
struct Respuesta cargarRespuestaParametro(int nRes, char res[100],int nPreRef,int c);
///Procediemto para cargar Arrays de Preguntas y respuestas
void cargarPreguntasporParametro(struct Pregunta p[],int  posicionArrays, int nPre,char pre[100],int posRes,int nRes,char res[100],int nPreRef,int c);
///Procediemto para cargar Arrays de Respuestas
void cargarRespuestasporParametro(struct Respuesta r[],int posicionArrays,int nRes, char res[100],int nPre,int c);
//Mostrar Respues
void mostrarRespuesta(struct Respuesta r);
//Mostrar Pregunta
void mostrarPregunta(struct Pregunta p);
///Muestra el arrays de Respuestas
void mostrarArraysRespuestas(struct Respuesta r[], int t);
///Muestra el arrays de Preguntas
void mostrarArraysPreguntas(struct Pregunta p[], int t);
///Procedimiento para hacer la pregunta
void hacerpreguntas(struct Pregunta p[], int tam, struct Jugador j[],int cantJug);
///Leyenda de Inicio y Reglas
void reglasLeyenda();
///Consultar PuntajeHistorico
void consultarPuntajeHistorico(struct Jugador p[], int cant);
///Pregunta desempate
void preguntaDesenpate(struct Jugador p[], int cant);


int main()
{
    srand(time(NULL));
    int reini;
    do{
    system ("CLS");
    reglasLeyenda();
    int tampre = 4;
    int cant = elegircantidadjugadores();
    struct Jugador jugadores[cant];
    cargarJugadores(jugadores, cant);
    mostrarJugadores(jugadores, cant);
    struct Pregunta preguntasUno[tampre];

    //carga y muestra las preguntas
    cargarPreguntasporParametro(preguntasUno, 0, 1, "!Que seleccion salio campeon del mundo en 2022?", 0, 1, "Turquia", 1, 0);
    cargarPreguntasporParametro(preguntasUno, 0, 1, "!Que seleccion salio campeon del mundo en 2022?", 1, 2, "Francia" , 1, 0);
    cargarPreguntasporParametro(preguntasUno, 0, 1, "!Que seleccion salio campeon del mundo en 2022?", 2, 3, "Brasil", 1, 0);
    cargarPreguntasporParametro(preguntasUno, 0, 1, "!Que seleccion salio campeon del mundo en 2022?", 3, 4, "Argentina"  , 1, 1);

    cargarPreguntasporParametro(preguntasUno, 1, 2, "!Cuanto mide el obelisco?", 0, 1, "20", 2, 0);
    cargarPreguntasporParametro(preguntasUno, 1, 2, "!Cuanto mide el obelisco?", 1, 2, "68", 2, 1);
    cargarPreguntasporParametro(preguntasUno, 1, 2, "!Cuanto mide el obelisco?", 2, 3, "100", 2, 0);
    cargarPreguntasporParametro(preguntasUno, 1, 2, "!Cuanto mide el obelisco?", 3, 4, "35", 2, 0);

    cargarPreguntasporParametro(preguntasUno, 2, 3, "!Cual es la avenida mas ancha del mundo?", 0, 1, "av. Alen", 3, 0);
    cargarPreguntasporParametro(preguntasUno, 2, 3, "!Cual es la avenida mas ancha del mundo?", 1, 2, "9 de Julio", 3, 1);
    cargarPreguntasporParametro(preguntasUno, 2, 3, "!Cual es la avenida mas ancha del mundo?", 2, 3, "Ing. Huergo", 3, 0);
    cargarPreguntasporParametro(preguntasUno, 2, 3, "!Cual es la avenida mas ancha del mundo?", 3, 4, "av. Constitucion", 3, 0);

    cargarPreguntasporParametro(preguntasUno, 3, 4, "!Que anio fue la revolucion de Mayo?", 0, 1, "1780", 4, 0);
    cargarPreguntasporParametro(preguntasUno, 3, 4, "!Que anio fue la revolucion de Mayo?", 1, 2, "1880", 4, 0);
    cargarPreguntasporParametro(preguntasUno, 3, 4, "!Que anio fue la revolucion de Mayo?", 2, 3, "1810", 4, 1);
    cargarPreguntasporParametro(preguntasUno, 3, 4, "!Que anio fue la revolucion de Mayo?", 3, 4, "1812", 4, 0);
    printf("\n******  EN 3 SEGUNDOS EMPIEZA EL JUEGO  ******\n");
    sleep (3);
    system ("CLS");
    //hace las preguntas
    hacerpreguntas(preguntasUno, tampre, jugadores, cant);

    preguntaDesenpate(jugadores, cant);

    //printf("\nPuntaje Historicos: %d \n", jugadores[0].puntosHistorico);

    //printf("\nPuntaje Historicos: %d \n", jugadores[1].puntosHistorico);
    consultarPuntajeHistorico(jugadores, cant);

    printf("\nSi quieren volver a jugar? escriba 1 para reiniciar, 0 para terminar.\n");
    scanf("%d",& reini);
    }while(reini==1);

    return 0;

}
///Elegir cantidad de Jugadores (2 o 4)
int elegircantidadjugadores(){
    int  cant;
    do{
        printf("\n--|| ELIJA LA CANTIDAD DE JUGADORES, PUEDE SER 2 o 4 ||--  ");
        scanf("%d", &cant);
    if(cant != 2 && cant != 4){printf("\n**** CANTIDAD INVALIDA DE JUGADORES, ELIJA 2 o 4 ****\n");};
    }while (cant != 2 && cant != 4 );

    return cant;
}
///Cargar un jugadore de la struct Jugador
struct Jugador cargarJugador(){

    struct Jugador j;
    printf("\n------ Cargar jugador -----\n");

    printf("Ingrese el nombre:\n");
    fflush(stdin);
    gets(j.nombre);

    printf("Ingrese su DNI:\n");
    scanf("%lf", &j.DNI);

    return j;
};
///Muestra un jugadore de la struct Jugadores
void mostrarJugador(struct Jugador j){

    printf("\n------ Jugador -----");
    printf("\nNOMBRE: %s", j.nombre );
    printf("\nDNI: %.0lf\n", j.DNI );

};
///Cargar los jugadores (2 o 4) que contenga el vector de la struct Jugadores
void cargarJugadores(struct Jugador j[], int t){

    for ( int i = 0 ; i<t; i++){

        j[i] = cargarJugador();}
};
///Muestra los jugadores (2 o 4) que contenga el vector de la struct Jugadores
void mostrarJugadores(struct Jugador j[], int t){

    for ( int i = 0 ; i<t; i++){

        mostrarJugador(j[i]);}
};

/////////Cargar preguntas y respuestas Generales//////////////////////////////
///Funcion cargar Preguntas
struct Pregunta cargarPreguntaParametro(int nPre,char pre[100],int posRes,int nRes,char res[100],int nPreRef,int c){

    struct Pregunta p;

    p.numPregunta = nPre;
    strcpy(p.pregunta, pre);
    cargarRespuestasporParametro(p.respuestas, posRes, nRes, res, nPreRef, c);

    return p;
};
///Funcion que cargar Respuestas
struct Respuesta cargarRespuestaParametro(int nRes, char res[100],int nPreRef,int c){

    struct Respuesta x;

    x.numRespuesta = nRes;
    strcpy(x.respuestas, res);
    x.numPreguntaAsociada = nPreRef;
    x.correcta = c;


    return x;
};
///Procediemto para cargar Arrays de Preguntas y respuestas
void cargarPreguntasporParametro(struct Pregunta p[],int  posicionArrays, int nPre,char pre[100],int posRes,int nRes,char res[100],int nPreRef,int c){

    p[posicionArrays] = cargarPreguntaParametro(nPre, pre, posRes, nRes, res, nPreRef, c);
}
///Procediemto para cargar Arrays de Respuestas
void cargarRespuestasporParametro(struct Respuesta r[],int posicionArrays,int nRes, char res[100],int nPre,int c){

    r[posicionArrays]= cargarRespuestaParametro(nRes, res, nPre, c);
}

///Mostrar Respuesta
void mostrarRespuesta(struct Respuesta r){
    printf("------------------------------------------------");
    printf("\n  Num de respuesta: * %d *\n",r.numRespuesta);
    printf("\n  Respuesta: *** %s ***\n",r.respuestas);
    //printf("\n  Num de pregunta asociada: * %d *\n",r.numPreguntaAsociada);
    //printf("\n  Correcta? (0=No, 1=SI): %d\n",r.correcta);
}
//Mostrar Pregunta
void mostrarPregunta(struct Pregunta p){
    printf("\n************************************************\n");
    //printf("\n  Num de Pregunta: * %d *\n",p.numPregunta);
    printf("\n  Pregunta: *** %s ***\n\n",p.pregunta);
    mostrarArraysRespuestas(p.respuestas , 4);
    printf("\n************************************************\n");
}
///Muestra el arrays de Respuestas
void mostrarArraysRespuestas(struct Respuesta r[], int t){

    for ( int i = 0 ; i<t; i++){
        mostrarRespuesta(r[i]);}
};
///Muestra el arrays de Preguntas
void mostrarArraysPreguntas(struct Pregunta p[], int t){

    for ( int i = 0 ; i<t; i++){
        mostrarPregunta(p[i]);}
};
///Procedimiento para hacer la pregunta
void hacerpreguntas(struct Pregunta p[], int tam, struct Jugador j[],int cantJug){

    int res = 0;
    int rescorrecta = 0;
    int x = 0;
    int tru = 0;
    int numj = 0;
    int alea=0;
    int aleaDos=1;
    time_t a,b;
    int seg;

    do{
        do{alea = 0+rand()%(tam);}while(aleaDos == alea);

        mostrarPregunta(p[alea]);
        printf("\nJugador [[ %s ]] su turno, ingrese una repuesta (TIENE 15 SEGUNDOS): ", j[numj].nombre);
        time(&a);
        scanf("%d", & res);
        time(&b);
        seg=difftime(b, a);
        printf("\n segundos %d\n", seg);
        x = p[alea].respuestas[res-1].correcta;
        printf("\nUsted contesto num de respuesta: %d \n",res);
        for(int j=0; j<4; j++){
            if (x == 1){
                if (x == p[alea].respuestas[j].correcta){
                rescorrecta = p[alea].respuestas[j].numRespuesta;
                    if (res == rescorrecta){tru=1;}
                    else {tru=0;}}}}
        if (tru == 1){
            if (seg<=15){
            j[numj].puntos = j[numj].puntos + (20-seg);}
            else{j[numj].puntos = j[numj].puntos + (1);}
            printf("\nLa respuesta es correcta, puntos acomulados [%d] , sigue su turno\n", j[numj].puntos);
            aleaDos = alea;
            }
        else{
            j[numj].puntosHistorico = j[numj].puntosHistorico + j[numj].puntos;
            printf("\nPuntaje historico %d\n",j[numj].puntosHistorico);
            printf("\nLa respuesta es incorrecta, continua otro jugador\n");
            numj = numj + 1;
            }

        sleep (3);
        system ("CLS");
        tru=0;


    }while(numj<cantJug);
}

void reglasLeyenda(){
    printf("\n||||||||||||||||||||||||||||-----------------------------------||||||||||||||||||||||||||||"
           "\n||||||||||||||||||||||||||||--- !!!RESPONDE SI SABES....??? ---||||||||||||||||||||||||||||"
           "\n||||||||||||||||||||||||||||-----------------------------------||||||||||||||||||||||||||||\n");
    printf("\nReglas principales:\n-Responde el jugador continuamente hasta que la respuesta es incorrecta, entonces sigue el turno del otro jugador.");
    printf("\n-El juego se termina cuando todos respondieron incorrectamente.");
    printf("\n-Tienen 15 segundos para responder, el puntaje varia de acuerdo al tiempo que se tarda.");
    printf("\n-Respuestas dentro del tiempo vale (20 puntos - segundos), pasado los 15 segundos solo vale 1 punto la respuesta correcta.");
    printf("\n-Cuando los puntos sean iguales, se hace una pregunta desempate\n");
}
/*
int main() {

    time_t a , b;
    int res = 0;
    int seg = 0;
        time(&a);
        res = (scanf("%d", &res));
        time(&b);
        seg = difftime(b, a);
        printf("CANTIDAD DE SEGUNDOS %d\n", seg);
    }
*/

void consultarPuntajeHistorico(struct Jugador p[], int cant){

    int consul;
    printf("\nPara consultar Historial de puntos presiones 1, si desea seguir cualquier caracter: ");
    scanf("%d",& consul);
    if(consul == 1){
        for(int i=0; i < cant; i++){
           printf("\n\n");
           printf("\nJugador nombre: %s", p[i].nombre);
           printf("\nPuntaje Historicos: %d \n", p[i].puntosHistorico);

        }
    }
}

void preguntaDesenpate(struct Jugador p[], int cant){

    for(int i=0; i<(cant-1); i++){
        for(int j=(i+1); j<(cant); j++){

            int a= rand() % 90 + 10;
            int b= rand() % 90 + 10;
            float numReferencia = (a+b)/2;
            int resUno=0;
            int resDos=0;

            if(p[i].puntos == p[j].puntos){
                printf("\nPregunta desempate entre jugador %s y %s,  la SUMA de A + B DIVIDIDO 2 por aproximacion",p[i].nombre,p[j].nombre);

                printf("\nNumero A = %d", a);
                printf("\nNumero B = %d", b);

                printf("\n¡Cual es el resultado?");

                printf("\nTurno de %s: ",p[i].nombre);
                scanf("%d", & resUno);

                printf("\nTurno de %s: ",p[j].nombre);
                scanf("%d", & resDos);


            int diferenciaUno = abs(resUno - numReferencia);
            int diferenciaDos = abs(resDos - numReferencia);

                if (diferenciaUno < diferenciaDos) {
                    printf("\nGANO!!! [ %s ] esta mas cerca del resultado correcto.\n", p[i].nombre);

                    p[i].puntos = p[i].puntos + 10;
                } else if (diferenciaDos < diferenciaUno) {
                    printf("\nGANO!!! [ %s ] esta mas cerca del resultado correcto.\n", p[j].nombre);
                    p[j].puntos = p[j].puntos + 10;
                } else {
                    printf("\nAmbos jugadores estan a la misma distancia del resultado correcto. Es un empate, de nuevo la pregunta\n");
                    preguntaDesenpate(p ,cant);
                }

                }
            }
        }
}

