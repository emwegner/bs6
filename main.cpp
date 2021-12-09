#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <fstream>
#include <regex>

//https://github.com/kshru9/Web-Crawler

using namespace std;

queue<string> urlQueue;
int besichtigteSeiten;
int aktuelleThreads;

bool checkIfValidURL(string adress) {
    // mit regex checken ob es richtigem format entspricht
    const regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    if (adress.empty()) {
        return false;
    }
    if(regex_match(adress, pattern)) {
        return true;
    }
    else {
        return false;
    }
}



void reader() {
    fstream file;
    string adress;
    file.open("file.txt");
    if(file.is_open()) {
        while(getline(file, adress)) {
            if(checkIfValidURL(adress)) {
                urlQueue.push(adress);
            }
        }
    } else {
        cout << "Fehler beim Öffnen der Datei" << endl;
    }

    terminate();
}

void createThread() {
    if(!urlQueue.empty()) {
    //    string seite = urlQueue.pop();
        aktuelleThreads++;
        besichtigteSeiten++;

        // create thread
   //    thread *th = new thread(childThread, seite, besichtigteSeiten.value());
   //     (*th).detach();
    }
}


void getHTML() {
    //get website html and put it in file
    //filename : <i>_<j>_<server host>.html gespeichert werden (für Threads mit Index 1 ≤ i ≤ n
    //und Dateien mit Index 1 ≤ j ≤ m).

    ofstream outfile ("test.txt");

    outfile << "my text here!" << endl;

    outfile.close();

}

void childThread(string adress, int threadnr) {

}




int main(int argc, char* argv[]) {

    cout << "Hello, World!" << endl;
    thread t1(reader);

    t1.join();


    return 0;
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
