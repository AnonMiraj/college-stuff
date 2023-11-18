#include "book.h"

// Constructors
Book::Book() :ind(0), title(""), author(""), ISBN(""), genre(""),desc(""), available(true) {}

Book::Book(const int ind,const std::string& title, const std::string& author, const std::string& ISBN, const std::string& genre, const std::string& desc, bool available)
    :ind(ind), title(title), author(author), ISBN(ISBN), genre(genre),desc(desc), available(available) {}

// Getters and Setters
int Book::getInd() const{
    return ind;
}
void Book::setInd(const int ind){
    this->ind=ind;
}

std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

std::string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

std::string Book::getISBN() const {
    return ISBN;
}

void Book::setISBN(const std::string& ISBN) {
    this->ISBN = ISBN;
}

std::string Book::getGenre() const {
    return genre;
}

void Book::setGenre(const std::string& genre) {
    this->genre = genre;
}

bool Book::isAvailable() const {
    return available;
}

bool Book::toggleAvailable() {
    this->available = !this->available;
    return available;
}

std::string Book::getDesc() const {
    return desc;
}

void Book::setDesc(const std::string& desc) {
    this->desc = desc;
}
std::istream& operator>>(std::istream& in, Book& book) {
    // Input format: "Title Author ISBN Genre Availability"
    in >> book.title >> book.author >> book.ISBN >> book.genre >> book.available;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    // Output format: "Title Author ISBN Genre Availability"
    out << book.title << " " << book.author << " " << book.ISBN << " " << book.genre << " " << book.available;
    return out;
}

