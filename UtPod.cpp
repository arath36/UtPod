#include <string>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

UtPod::UtPod() {
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size) {
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    songs = NULL;
    tail = NULL;
    if (size > MAX_MEMORY || size < 0) {
        memSize = MAX_MEMORY;
    } else {
        memSize = size;
    }
}

// FUNCTION gets num songs

int UtPod::numSongs() {
    int count = 0;
    SongNode *p = songs;

    while (p != NULL) {
        count = count + 1;
        p = p->next;

    }

    return count;
    
}

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms -

       output parms -
      */

int UtPod::addSong(Song const &s) {

    SongNode* node = songs;


    if (s.getSize() > this->getRemainingMemory()) {
        return NO_MEMORY; 
    }



    if (songs == NULL) {
        SongNode *head = new SongNode;
        head->s.setTitle(s.getTitle());
        head->s.setArtist(s.getArtist());
        head->s.setSize(s.getSize());
        head->next = NULL;
        
        songs = head;

        return SUCCESS;


    } 

    while (node->next != NULL) {
        node = node->next;
    }

    SongNode* newNode = new SongNode;
     newNode->s.setTitle(s.getTitle());
     newNode->s.setArtist(s.getArtist());
     newNode->s.setSize(s.getSize());
     newNode->next = NULL;

     node->next = newNode;







    return SUCCESS;
}


      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed


         input parms -

         output parms -
      */

int UtPod::removeSong(Song const &s) {
    SongNode* node = songs;
    SongNode* previous = NULL;

    while (node != NULL) {
        if (node->s == s) {
            if (previous != NULL) {
                previous->next = node->next;
            } else {
                songs = node->next;
            }

            delete node;
            
            return SUCCESS;
        }

        previous = node;
        node = node->next;

    }

    return NOT_FOUND;
}

      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

void UtPod::shuffle() {



    

    int songCount = numSongs();

    SongNode *ptr1 = songs;
    SongNode *ptr2 = songs -> next;




    for (int i = 0; i < 10*songCount; i++) {

        long rand1 = rand()%songCount;


        for (int j = 0; j < rand1; j++) {
            ptr1 = ptr1 -> next;
        }

        long rand2 = rand()%songCount;
        

        for (int k = 0; k < rand2; k++) {
            ptr2 = ptr2 -> next;
        }

        ptr1->s.swap(ptr2->s);
        ptr1 = ptr2 = songs;

    }

    



}


      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

void UtPod::showSongList() {
    SongNode* node = songs;
    SongNode* next;

    while (node != NULL) {
        cout << "Title: " << node->s.getTitle() << " Artist: " << node->s.getArtist() << " Size: " << node->s.getSize() << endl;
        node = node->next;
            
    }

    

}


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

void UtPod::sortSongList() {
        SongNode *p1 = songs;
        
        while (p1 != NULL) {
            SongNode *smallest = p1;
            SongNode *p2 = p1->next;

            while (p2 != NULL) {
                if (smallest->s > p2->s) {
                    smallest = p2;
                }
                p2 = p2->next;

            }

            p1->s.swap(smallest->s);

            p1 = p1->next;


        }

    }

            /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */
void UtPod::clearMemory() {
     
        SongNode* node = songs;
        SongNode* next = NULL; 

        if (node == NULL) {
            return;
        } else {
            next = node->next;
        }

        while (next != NULL) {
            delete (node);
            node = next;
            next = next->next;


        }

        delete(node);

        songs = NULL;

        



      }


      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */


      int UtPod::getRemainingMemory() {

        SongNode* node = songs;
        SongNode* next;
        int totalUsedMem = 0;
        while (node != NULL) {
            totalUsedMem =  totalUsedMem + node->s.getSize();
            node = node->next;
        }

          return (getTotalMemory() - totalUsedMem);
      }

      UtPod::~UtPod() {
          clearMemory();
      }