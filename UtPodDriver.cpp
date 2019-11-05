/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {

    UtPod t(371);
    
    Song s1("Beatles", "Hey Jude1", 4);
    
    
          
    Song s2("Beatles", "Hey Jude2", 5);
    
       
    Song s3("Beatles", "Hey Jude3", 6);
    
       
    Song s4("Beatles", "Hey Jude4", 7);
    

       
    Song s5("Beatles", "Hey Jude5", 45);


    t.addSong(s5);
    t.addSong(s4);
    t.addSong(s3);
    t.addSong(s2);
    t.addSong(s1);
    t.addSong(s5);
    t.addSong(s4);
    t.addSong(s3);
    t.addSong(s2);
    t.addSong(s1);

    t.showSongList();
    
    t.sortSongList();

    t.showSongList();

    t.shuffle();
   

    t.showSongList();


    cout << "memory = " << t.getRemainingMemory() << endl;

    // second instance of ut pod for testing
    UtPod t2(600);


    Song song1("Train", "Hey Soul Sister", 100);
    t2.addSong(song1);
    Song song2("Migos", "Pure Water", 100);
    t2.addSong(song2);
    Song song3("Frank Sinatra", "Fly me to the Moon", 100);
    t2.addSong(song3);
    Song song4("Some Country Artist", "Wagon Wheel", 100);
    t2.addSong(song4);
    Song song5("Frank Sinatra", "Fly me to the Moon", 100);
    t2.addSong(song5);
    int result2 = t2.addSong(song1);

    cout << "Result = " << result2 << endl;

    t2.showSongList();

    t2.sortSongList();

    t2.showSongList();

    t2.shuffle();

    t2.showSongList();

    t2.removeSong(s1);
    t2.removeSong(song1);
    t2.removeSong(song2);
    t2.removeSong(song3);
    t2.removeSong(song4);
    t2.removeSong(song3); // should remove both songs because they are the same

    cout << "Memory left = " << t2.getRemainingMemory() << endl;

    t2.showSongList();
 

    // third test

    UtPod t3(501);
    Song checkMem("Justin Bieber", "Baby", 20);

    while (t3.addSong(checkMem) != -1) {
        // fills up the ipod
    }

    cout << "Remaining memory =" << t3.getRemainingMemory() << endl;


    t3.clearMemory();
        // tests clear mem functions
    cout << "Remaining memory =" << t3.getRemainingMemory() << endl;


     while (t3.addSong(checkMem) != -1) {
        // fills up the ipod
    }

     cout << "Remaining memory =" << t3.getRemainingMemory() << endl;

     while (t3.removeSong(checkMem) != -2) {

     }

    cout << "Remaining memory =" << t3.getRemainingMemory() << endl;

    
    
    
    

}