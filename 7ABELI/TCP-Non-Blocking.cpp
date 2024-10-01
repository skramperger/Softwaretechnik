// General wenn man nicht weiß, welcher Typ daherkommt, nimmt man void als Datentyp (const void *something)

#include "mbed.h"
#include "platform/mbed_thread.h"
#include <iostream>
#include <new>
#define HOST_IP 172.64.195.16
#define HOST_PORT 80
// #inlcude "EthernetInterface.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS    500

NetworkInterface *net;  // Zeiger auf das net-Objekt
TCPSocket sok;
SocketAddress a;

const char s_buffer[] = "GET / HTTP/1.1\r\nHost: ifconfig.io\r\nConnection: close\r\n\r\n";

char *r_buffer =  new char[2000];
char *p = r_buffer;     // Zeiger auf den Empfangsbuffer
int remaining_buffer = 2000;

nsapi_size_or_error_t senden(TCPSocket *socket) {
    return socket->send(s_buffer, sizeof(s_buffer));
}

nsapi_size_or_error_t empfangen(TCPSocket *socket) {
    nsapi_size_or_error_t result;
    while(remaining_buffer > 0 ){
        result = socket->recv(p, remaining_buffer);
        if (result > 0){
            
        } else {
            std::cout << "Fehler beim Empfangen: " << result << std::endl;
        }
    }
    return result;
}

// Statusmaschine für unseren TCP-Stack
void handle_sock_sigio(EventFlags *evt, TCPSocket *socket){
    static enum {       // static sorgt dafür, dass der Wert zwischen den Aufrufen erhalten bleibt
        CONNECTING,
        SEND,
        RECEIVE,
        CLOSE
    } next_state = CONNECTING;

    nsapi_size_or_error_t result = 0;   // Hilfsvariable für die ganzen Aufrufe


    std::cout << "Aktueller Zustand: " << next_state << std::endl;

    switch(next_state) {
        case CONNECTING:
            net = NetworkInterface::get_default_instance();
            net->connect();
            // TBD: socket open, ip-adr und port setzen, socket->connect aufrufen und Ergebnis in result speichern

            sok.open(&net);

            // Ende

            if(result == NSAPI_ERROR_OK) {
                std::cout << "Mit Server verbunden." << std::endl;
                next_state = SEND;
            }
        break;
        case SEND:
            if(senden(socket) > 0) {
                next_state = RECEIVE;
            } else {
                std::cout << "Fehler beim Senden." << std::endl;
                next_state = CLOSE;
            }
        break;
        case RECEIVE:
            if (empfangen(socket) == NSAPI_ERROR_WOULD_BLOCK) {     // es gibt noch nix zum Empfangen oder noch nicht fertig
                std::cout << "Warte auf Empfang, aber blockiert nicht..." << std::endl;
                break;
            }
            std::cout << "Empfangen: " << r_buffer << std::endl;
            next_state = CLOSE;
        case CLOSE:
            socket->close();
            evt->set(1);        // Wir senden unserem Hauptprogramm die Nachricht, dass wir fertig sind (LSB setzen)
        break;
    }   // Switch Ende
}


int main()
{
    EventQueue *eq = mbed_event_queue();    // Zeiger auf eine FIFO-Ereignisschlange
    EventFlags completed;                   // Ereignisanzeige (wird vom Handler benötigt)

    Event<void()> handler = eq->event(handle_sock_sigio, &completed, &sok);     // Definition und Init unseres Handlers
                                                                                // Der Handler befüllt unsere EventQueue und diese wird bei jedem Event in unsere Callback Funktion hüpfen
    
    sok.set_blocking(false);                // Non-blocking mode TCP 
    sok.sigio(handler);                     // Bei Statusänderungen am Socket (am Stack) wird der Handler aufgerufen

    handler();                              // Aufruf der void-Funktion: Zustandsmaschine läuft ab jetzt


    DigitalOut led(LED1);

    while (true) {
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
        if(completed.get() != 0) {
            std::cout << "Empfang fertig. \nFlags: " << completed.get() << std::endl;
            completed.clear();          // Event Flag zurücksetzen
        }
    }
}
