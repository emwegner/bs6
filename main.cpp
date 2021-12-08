#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <queue>
using namespace std;


int main() {
    cout << "Hello, World!" << endl;
    queue<string> my_queue;
    return 0;
}

//erstellen des thread
template < class Function, class ... Args > explicit thread (Function && f, Args &&... args);


void readFileToQueue() {
    
}


/*
  thread mit terminate() beenden am ende der funktion;
  in C++-11 kann zum Warten auf einen Thread die Methode join() auf dem betreffenden Thread aufgerufen werden.

 In C++-11 wird ein Mutex per Konstruktor std::mutex erzeugt.
 In C++-11 wird ein Mutex per Methode lock() gesperrt und per unlock() wieder frei gegeben.
 In C++-11 wird der Mutex per Destruktor gelöscht. Achtung: Bei auf dem Stack angelegten Variablen
wird dieser aufgerufen, wenn die Variable aus dem Gültigkeitsbereich herausfällt

 In C++-11 kann eine Bedingungsvariable per std::condition_variable() erzeugt werden. Eine
solche Variable ist nicht kopierbar.


 In C++-11
• kann auf eine Bedingungsvariable vom Typ condition_variable per Methode wait()
gewartet werden, die einen Booleschen Wert zurückgibt (true, wenn Bedingung erfüllt).
• Mit notify_one() kann ein Thread, der auf die Bedingung wartet, deblockiert werden.
• Mit notify_all() werden alle wartenden Prozesse deblockiert.
 */