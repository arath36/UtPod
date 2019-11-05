#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {
      
  private:
   string title;
   string artist;
   int size;

 
  public:
   Song();
   Song(string title, string artist, int size);
    
   void setTitle (string title);
   string getTitle () const;
   void setArtist (string artist);
   string getArtist() const;
   void setSize (int size);
   int getSize() const;
   void swap(Song &s);
   
  

   bool operator ==(Song const &rhs);
   bool operator >(Song const &rhs);
   bool operator <(Song const &rhs);

};



#endif