#include "Seguridad.h"

string Cabin(string texto){
/*
    Esta funcion recibe una cadena string y retorna su equivalente en binario.
*/
    string bin, textobinario;
    unsigned num;

    for(unsigned long i=0; i<texto.length(); ++i){
        num=texto[i];
        for(int h=0; h<8; ++h){
            bin+=(num%2)+48;
            num/=2;
        }
        bin=reverse(bin);
        textobinario+=bin;
        bin="";
    }

    return textobinario;
}

string Binca(string textobinario){
    string bin, textocaracteres;
    int dec;

    for(unsigned long i=0; i<textobinario.length(); i+=8){
        dec=0;
        bin=textobinario.substr(i,8);
        bin=reverse(bin);
        for(int h=0; h<8; ++h){
            dec+=(int(bin[h])-48)*pow(2,h);
        }
        textocaracteres+=char(dec);
    }

    return textocaracteres;
}

string Codificar1(string textobinario, int semilla){
/*
    Esta funcion recibe un texto en binario y una semilla, toma bloques de bits dependiendo
    de la semilla y retorna el texto que fue ingresado ya codificado.
*/
    string bloque, codificado="";
    long unos=0, ceros=0;

    for(unsigned long i=0; i<textobinario.length(); i+=semilla){
        bloque=textobinario.substr(i,semilla);

        if(unos==ceros){
            codificado+=Invertir(bloque,1);
        }
        else if(ceros>unos){
            codificado+=Invertir(bloque,2);
        }
        else{
            codificado+=Invertir(bloque,3);
        }

        unos=Contar1y0(bloque,'1');
        ceros=Contar1y0(bloque,'0');

    }

    return codificado;
}

string Decodificar1(string codificado, int semilla){
/*
    Esta funcion recibe un texto binario codificado y una semilla, luego se encarga de decodificar
    el texto binario separandolo en bloque del tamaña de semilla.
*/
    string bloque, decodificado="";
    long unos=0, ceros=0;

    for(unsigned long i=0; i<codificado.length(); i+=semilla){
        bloque=codificado.substr(i,semilla);

        if(unos==ceros){
            decodificado+=Invertir(bloque,1);
        }
        else if(ceros>unos){
            decodificado+=Invertir(bloque,2);
        }
        else{
            decodificado+=Invertir(bloque,3);
        }

        unos=Contar1y0(decodificado.substr(i,semilla),'1');
        ceros=Contar1y0(decodificado.substr(i,semilla),'0');

    }

    return decodificado;
}

string Invertir(string binario, int num){
/*
    Esta funcion recibe un texto binario y un numero, el numero indica
    el tipo de codificacion que se le hara al texto binario.
*/
    for(unsigned long i=1; i<=binario.length(); ++i){
        if(i%num==0){
            if(binario[i-1]=='0')
                binario[i-1]='1';
            else
                binario[i-1]='0';
        }
    }

    return binario;
}

long Contar1y0(string binario, char numero){
    long contador=0;
    for(unsigned long i=0; i<binario.length(); ++i){
        if(binario[i]==numero)
            contador++;
    }

    return contador;
}

string Leer(string nombre, int tipo){
/*
    Esta funcion recibe el nombre de un archivo, lo lee y posteriormente
    retorna una cadena string con todo lo que esta en el archivo.
*/
    ifstream archivo;
    string texto, aux;

    archivo.open(nombre);
    if (archivo.is_open()){
        while (!archivo.eof()) {
            getline(archivo,aux);
            if(tipo==1)
                texto+=aux+'\n';
            else
                texto+=aux;
        }
        archivo.close();
    }
    else{
        cout << "Error al abrir el archivo." << endl;
        exit(1);
    }

    return texto;
}

void Escribir(string nombre, string texto){
/*
    Esta funcion recibe un nombre y un texto para luego guardar
    el texto en un archivo con el nombre se le paso a la funcion.
*/
    ofstream archivo;

    archivo.open(nombre, ios::binary);
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << texto;

    archivo.close();
}

string reverse(string cadena){
/*
    Esta funcion recibe una cadena string y la retorna invertida.
*/
    string auxcadena;

    for(long long i=cadena.length()-1; i>=0; --i){
        auxcadena+=cadena[i];
    }

    return  auxcadena;
}
