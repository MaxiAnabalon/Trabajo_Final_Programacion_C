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

/////////cargar preguntas y respuestas desde archivos////////
void cargarPreguntasDesdeArchivo(struct Pregunta p[]);
void cargarRespuestasDesdeArchivo(struct Respuesta r[]);
struct Pregunta cargarRespuestasDesdeArchivoPrueba(struct Pregunta p);
void asociarPreguntasRespuesatas(struct Pregunta p[], int tam, struct Respuesta r[], int tamRes);
int contarReglonesArchivo(char nombreArchivo[]);


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
void preguntaDesenpate(struct Jugador p[], int cant, int pMax);
///Indice de Quien gano
int quienGano(struct Jugador p[], int cant);
///Mostrar quien gano y los puntos de todos
void mostrarPuntosyGanador(struct Jugador p[], int cant);


int main()
{
    srand(time(NULL));
    int reini;
    do{
    system ("CLS");
    reglasLeyenda();
    int tampre = 10;
    tampre=contarReglonesArchivo("preguntas.txt");
    printf("%d\n",tampre);
    int cant = elegircantidadjugadores();
    struct Jugador jugadores[cant];
    cargarJugadores(jugadores, cant);
    mostrarJugadores(jugadores, cant);
    struct Pregunta preguntasUno[tampre];
    cargarPreguntasDesdeArchivo(preguntasUno);
    mostrarArraysPreguntas(preguntasUno, tampre);
    system("pause");
    printf("\n******  EN 3 SEGUNDOS EMPIEZA EL JUEGO  ******\n");
    sleep (3);
    system ("CLS");
    //hace las preguntas
    hacerpreguntas(preguntasUno, tampre, jugadores, cant);
    //Muestra los ganadores y si hace la pregunta desempate
    mostrarPuntosyGanador(jugadores, cant);
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

    j.puntos=0;

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
        x = p[alea].respuestas[res-1].correcta;
        printf("\nUsted tardo %d segundos, y contesto num de respuesta: %d \n",seg,res);
        sleep(2);
        for(int j=0; j<4; j++){
            if (x == 1){
                if (x == p[alea].respuestas[j].correcta){
                rescorrecta = p[alea].respuestas[j].numRespuesta;
                    if (res == rescorrecta){tru=1;}
                    else {tru=0;}}}}
        if (tru == 1){
            if (seg<=15){j[numj].puntos = j[numj].puntos + (20-seg);
                printf("\nSuma %d puntos\n", (20-seg));
            }
            else{j[numj].puntos = j[numj].puntos + (1);
                printf("\nSuma 1 puntos\n");
            }
            printf("\nLa respuesta es correcta, puntos acomulados [%d] , sigue su turno\n", j[numj].puntos);
            aleaDos = alea;}
        else{
            j[numj].puntosHistorico = j[numj].puntosHistorico + j[numj].puntos;
            printf("\nPuntaje acomulado %d\n",j[numj].puntos);
            ///printf("\nPuntaje historico %d\n",j[numj].puntosHistorico);
            printf("\nLa respuesta es incorrecta, continua otro jugador . . .\n\n");
            numj = numj + 1;
            system("pause");
            }
        sleep (1);
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

void consultarPuntajeHistorico(struct Jugador p[], int cant){

    int consul;
    printf("\nPara consultar Historial de puntos presiones 1, si desea seguir ingrese cualquier otro numero: ");
    scanf("%d",& consul);
    if(consul == 1){
        for(int i=0; i < cant; i++){
           printf("\n\n");
           printf("\nJugador nombre: %s", p[i].nombre);
           printf("\nPuntaje Historicos: %d \n", p[i].puntosHistorico);

        }
    }
}

void preguntaDesenpate(struct Jugador p[], int cant, int pMax){

        for(int i=0; i<cant; i++){
            int a= rand() % 90 + 10;
            int b= rand() % 90 + 10;
            float numReferencia = (a+b)/2;
            int resUno=0;
            int resDos=0;
            if(i != pMax){
            if(p[pMax].puntos == p[i].puntos){
                printf("\nPregunta desempate entre jugador %s y %s,  la SUMA de A + B DIVIDIDO 2 por aproximacion",p[pMax].nombre,p[i].nombre);
                printf("\nNumero A = %d", a);
                printf("\nNumero B = %d", b);
                printf("\n¡Cual es el resultado?");
                printf("\nTurno de %s: ",p[pMax].nombre);
                scanf("%d", & resUno);
                printf("\nTurno de %s: ",p[i].nombre);
                scanf("%d", & resDos);

            int diferenciaUno = abs(resUno - numReferencia);
            int diferenciaDos = abs(resDos - numReferencia);
                if (diferenciaUno < diferenciaDos) {
                    printf("\nGANO!!! [ %s ] esta mas cerca del resultado correcto.\n", p[pMax].nombre);
                    p[pMax].puntos = p[pMax].puntos + 10;
                    p[pMax].puntosHistorico = p[pMax].puntosHistorico + 10;

                } else if (diferenciaDos < diferenciaUno) {
                    printf("\nGANO!!! [ %s ] esta mas cerca del resultado correcto.\n", p[i].nombre);
                    p[i].puntos = p[i].puntos + 10;
                    p[i].puntosHistorico = p[i].puntosHistorico + 10;
                } else {
                    printf("\nAmbos jugadores estan a la misma distancia del resultado correcto. Es un empate, de nuevo la pregunta\n");
                    //preguntaDesenpate(p ,cant, pMax);
                }
}}}}

int quienGano(struct Jugador p[], int cant){

    int maximo = p[0].puntos;
    int pGanador=0;
    for (int i=0; i<cant; i++){
        if (p[i].puntos > maximo){
            maximo = p[i].puntos;
            pGanador = i;
        }
    }
    return pGanador;
}

void mostrarPuntosyGanador(struct Jugador p[], int cant){

    int ganador = quienGano(p, cant);
    preguntaDesenpate(p, cant, ganador);
    ganador = quienGano(p, cant);

    printf("\n\n°°° EL GANADOR ES [[[ %s ]]] FELICITACIONES !!!, con un total de puntos: [%d] °°°\n\n", p[ganador].nombre, p[ganador].puntos);
    for (int i=0; i<cant; i++){
        if(i != ganador){
            printf("\nJugador [%s] acomulo [%d] puntos\n",p[i].nombre, p[i].puntos);
        }}
}



void cargarPreguntasDesdeArchivo(struct Pregunta p[]) {

    FILE *archivo;

    archivo = fopen("preguntas.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;

    while (!feof(archivo)) {

        fscanf(archivo, "%d; \"%99[^\"]\";\n",&p[pos].numPregunta, p[pos].pregunta);
        p[pos] = cargarRespuestasDesdeArchivoPrueba(p[pos]);
        pos++;

        }
    fclose(archivo);
}

void cargarRespuestasDesdeArchivo(struct Respuesta r[]){

    FILE *archivo;

    archivo = fopen("respuestas.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;

    while (!feof(archivo)) {

        fscanf(archivo, "%d;\"%99[^\"]\";%d;%d;\n",&r[pos].numRespuesta, r[pos].respuestas, &r[pos].numPreguntaAsociada, &r[pos].correcta);

        pos++;

        }
    fclose(archivo);

}

void asociarPreguntasRespuesatas(struct Pregunta p[], int tam, struct Respuesta r[], int tamRes){

    ///int pos=0;

    for ( int i = 0; i < tam; i++){
        int pos = 0; // Restablecemos pos a 0 para cada pregunta

        for ( int j = 0; j< tamRes; j++){

            if (p[i].numPregunta == r[j].numPreguntaAsociada){

                p[i].respuestas[pos].numRespuesta = r[j].numRespuesta;
                strcpy( p[i].respuestas[pos].respuestas, r[j].respuestas);
                p[i].respuestas[pos].numPreguntaAsociada = r[j].numPreguntaAsociada;
                p[i].respuestas[pos].correcta = r[j].correcta;

                printf("\n %s \n", r[j].respuestas);

                pos++;
            }

        }
    }
}



struct Pregunta cargarRespuestasDesdeArchivoPrueba(struct Pregunta p){

    struct p;

    FILE *archivo;

    archivo = fopen("respuestas.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;

    while (!feof(archivo)) {

        int numRespue=0;
        char respues[50];
        int numPreguntaAsoc=0;
        int correc=0;


        fscanf(archivo, "%d;\"%99[^\"]\";%d;%d;\n",&numRespue, respues, &numPreguntaAsoc, &correc);

        if (numPreguntaAsoc == p.numPregunta) { ///Si la respuesta pertenece a esa pregunta se acopia

            p.respuestas[pos].numRespuesta = numRespue;
            strcpy( p.respuestas[pos].respuestas, respues);
            p.respuestas[pos].numPreguntaAsociada = numPreguntaAsoc;
            p.respuestas[pos].correcta = correc;

        pos++;
        if (pos>3){pos=0;};
        }
    }
    fclose(archivo);
    return p;
}

int contarReglonesArchivo(char nombreArchivo[]){

    FILE *archivo;
    int contadorLineas = 0;
    char caracter;

    // Abrir el archivo en modo lectura
    archivo = fopen(nombreArchivo, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return -1; // Código de error
    }

    // Contar las líneas en el archivo
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            contadorLineas++;
        }
    }

    // Cerrar el archivo
    fclose(archivo);
    return contadorLineas;
}

