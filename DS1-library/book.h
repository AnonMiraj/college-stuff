#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
public:
  // Constructors
  Book();
  Book(const int ind,const std::string &title, const std::string &author,
       const std::string &ISBN, const std::string &genre,const std::string &desc, bool available);

  // Getters and Setters
  int getInd() const;
  void setInd(const int ind);
  std::string getTitle() const;
  void setTitle(const std::string &title);

  std::string getAuthor() const;
  void setAuthor(const std::string &author);

  std::string getISBN() const;
  void setISBN(const std::string &ISBN);

  std::string getGenre() const;
  void setGenre(const std::string &genre);

  std::string getDesc() const;
  void setDesc(const std::string& desc);


  bool isAvailable() const;
  bool toggleAvailable();

  friend std::istream &operator>>(std::istream &in, Book &book);
  friend std::ostream &operator<<(std::ostream &out, const Book &book);

private:
  int ind;
  std::string title;
  std::string author;
  std::string ISBN;
  std::string genre;
  std::string desc;
  bool available;
};

#endif // BOOK_H
