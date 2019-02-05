#include <iostream>
#include <fstream>

using namespace std;

int main () {

    fstream ficheroMp3;
    char marca[3];

    ficheroMp3.open ("test.mp3", ios::in | ios::binary);
    // Compruebo si he podido abrir

    if (ficheroMp3.is_open()) {
        // Me coloco donde empieza el ID3 TAG
        ficheroMp3.seekg(-128, ios::end);
        // Leo 3 bytes

        ficheroMp3.read(marca, 3);
        // Digo si day datos o no
        if ((marca[0] != 'T') || (marca[1] != 'A') || (marca[2] != 'G'))

            cout << "Sin datos de artista" << endl;
        else
            cout << "Parece un MP3 con ID3 TAG" << endl;
        // Finalmente, cierro

        ficheroMp3.close();
    }
    // Si no he podido abrir, aviso
    else cout << "Fichero inexistente" << endl;
    return 0;

}
