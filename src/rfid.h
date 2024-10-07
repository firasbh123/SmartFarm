#ifndef RFID_H
#define RFID_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class rfid
{
public:
    rfid();
    int connect_arduino(); // permet de connecter le PC à Arduino

        int close_arduino(); // permet de femer la connexion

       //int write_to_arduino ( QString ); // envoyer des données vers arduino QByteArray read_from_arduino(); //recevoir des données de la carte Arduino QSerialPort getserial(); // accesseur
        int write_to_arduino(QByteArray d );

        //QString read_from_arduino();
        QByteArray read_from_arduino();

        QSerialPort* getserial();

        QString getarduino_port_name();
private:
        QSerialPort* serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.) //et des fonctions (envo, lecture de réception,-) sur ce qu'est une voie série pour Arduino.

        static const quint16 arduino_uno_vendor_id=9025;

        static const quint16 arduino_uno_producy_id=67;

        QString arduino_port_name;

        bool arduino_is_available;

        QString SerialBuffer;
        QByteArray SerialData="";

        QByteArray data; // contenant les données lues à partir d'Arduino
};

#endif // RFID_H


