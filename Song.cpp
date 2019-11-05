#include <string>
#include <iostream>
#include "Song.h"

using namespace std;

Song::Song(string artist, string title, int size) {
    this->title = title;
    this->artist = artist;
    this->size = size;
}

Song::Song() {
    title = "";
    artist = "";
    size = 0;
}


string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return size;
}

string Song::getTitle() const {
    return title;
}

void Song::setArtist(string artist) {
    this->artist = artist;
}

void Song::setTitle(string title) {
    this->title = title;
}

void Song::setSize(int size) {
    this->size = size;
}

void Song::swap(Song &s) {
    string tempArtist = s.getArtist();
    string tempTitle = s.getTitle();
    int tempSize = s.getSize();

    s.setArtist(this->getArtist());
    s.setTitle(this->getTitle());
    s.setSize(this->getSize());

    this->setArtist(tempArtist);
    this->setTitle(tempTitle);
    this->setSize(tempSize);
}


bool Song::operator== (Song const &rhs) {
    return (title == rhs.title && artist == rhs.artist && size == rhs.size);
}

bool Song::operator > (Song const &rhs) {
     if (artist == rhs.artist) {
         if (title == rhs.title) {
             if (size == rhs.size) {
                 return false;
             } else {
                 return (size > rhs.size);
             }
         } else {
             return (title > rhs.title);
         }
     } else {
         return (artist > rhs.artist);
     }
}

bool Song::operator < (Song const &rhs) {

    if (*this == rhs) {
        return false;
    } else {
        return (~(*this > rhs));
    }
}





