#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <limits>
using namespace std;

int PubId = 1, BookId = 1, LibId = 1;

enum BookType
{
    SCIENTIFIC,
    CRIME,
    FANTASY,
    HORROR,
    CLASSICS
};

class Publisher
{
private:
    int id;
    string name;
    string location;

public:
    void PubSet(string name)
    {
        this->name = name;
        this->location = location;
    }
    Publisher(string name, string location)
    {
        this->name = name;
        this->location = location;
        id = PubId;
        PubId++;
    }
    Publisher()
    {
        id = PubId;
        PubId++;
    }
    bool operator==(Publisher publisher)
    {
        if (publisher.name == this->name && publisher.location == this->location)
        {
            return true;
        }
        return false;
    }
};

class Book
{
private:
    int id;
    string name;
    BookType type;
    Publisher publisher;
    bool borrowed = false;

public:
    Book(string name, Publisher publisher, BookType type)
    {
        this->name = name;
        this->publisher = publisher;
        this->type = type;
        this->id = BookId;
        BookId++;
    }
    Book()
    {
        this->id = BookId;
        BookId++;
    }
    void BookSetter(string name, Publisher publisher, BookType type)
    {
        this->name = name;
        this->publisher = publisher;
        this->type = type;
    }
    void showInfo()
    {
        cout << id << ". " << name << "\n";
    }
    string RetunInfo()
    {
        return (id + ". name\n");
    }
    string NameOfBook()
    {
        return name;
    }
    bool IsBorrowed()
    {
        return borrowed;
    }
    void BorrowBook()
    {
        borrowed = true;
    }
    bool operator==(Book book)
    {
        if (book.name == this->name && book.publisher == this->publisher && book.type == this->type)
        {
            return true;
        }
        return false;
    }
    BookType TypeOfBook()
    {
        return type;
    }
};

class Library
{
private:
    int id;
    int position;
    string name;
    vector<Book> books;

public:
    Library(string name, int position)
    {
        this->position = position;
        this->name = name;
        id = LibId;
        LibId++;
    }
    Library()
    {
        id = LibId;
        LibId++;
    }
    void Libset(string name, int position)
    {
        this->position = position;
        this->name = name;
    }
    vector<Book> &BookReturn()
    {
        return books;
    }
    void DeleteBook(int index)
    {
        books.erase(books.begin() + index);
    }
    void DeleteBook(Book book)
    {
        for (int i = 0; i < books.size(); i++)
        {
            try
            {
                if (book == books[i])
                {
                    books.erase(books.begin() + i);
                }
                else
                {
                    throw 0;
                }
            }
            catch (int a)
            {
                cout << "Not found!\n";
            }
        }
    }
    void SearchBook(string BookName)
    {
        for (int i = 0; i < books.size(); i++)
        {
            try
            {
                if (books[i].NameOfBook() == BookName)
                {
                    cout << "Available index of book is :" << i;
                }
                else
                {
                    throw 0;
                }
            }
            catch (int a)
            {
                cout << "Unfortunately not found!";
            }
        }
    }
    void AvailableBooks()
    {
        for (int i = 0; i < books.size(); i++)
        {
            books[i].showInfo();
        }
    }

    void AddBook(Book book)
    {
        books.push_back(book);
    }
    void BooksByType(BookType type)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].TypeOfBook() == type)
            {
                books[i].showInfo();
            }
        }
    }
    int PositionOfLibrary()
    {
        return position;
    }
    string NameOfLibrary()
    {
        return name;
    }
    int IdOfLibrary()
    {
        return this->id;
    }
    int SearchByName(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].NameOfBook())
            {
                return i;
            }
        }
    }
    Book BookReturnByName(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].NameOfBook())
            {
                return books[i];
            }
        }
    }
    int PosReturn()
    {
        return position;
    }
    int BookCount()
    {
        return books.size();
    }
    bool IsAvailableBook(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].NameOfBook())
            {
                return true;
            }
        }
        return false;
    }
};
class Member
{
private:
    string id;
    string name;
    vector<Book> books;
    Library lib;
    vector<Book> LibBooks = lib.BookReturn();

public:
    Member(string id, string name)
    {
        this->id = id;
        this->name = name;
    }
    bool operator==(Member member)
    {
        if (member.name == this->name && member.id == this->id)
        {
            return true;
        }
        return false;
    }
    void AddBook(Book book)
    {
        books.push_back(book);
    }
    int BorrowedBookCount()
    {
        return books.size();
    }
    string IdReturner()
    {
        return id;
    }
    Book BookReturnByName(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].NameOfBook())
            {
                return books[i];
            }
        }
    }
    void DeleteBookByName(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].NameOfBook())
            {
                books.erase(books.begin() + i);
            }
        }
    }
};



class LibrariesHandler
{
private:
    vector<Library> libraries;
    vector<Member> members;

public:
    void creatLibrary(string name, int position)
    {
        bool IsExist = false;
        Library library(name, position);
        for (int i = 0; libraries.size(); i++)
        {
            try
            {
                if (libraries[i].PositionOfLibrary() == position)
                {
                    IsExist = true;
                    throw 1;
                }
                else if (libraries[i].NameOfLibrary() == name)
                {
                    IsExist = true;
                    throw 2;
                }
            }
            catch (int a)
            {
                if (a == 1)
                {
                    cout << "There is now a library in this place\n";
                }
                else
                {
                    cout << "A library with this name already exists\n";
                }
            }
        }
        if (!IsExist)
        {
            libraries.push_back(library);
            cout << "Successfully added!";
        }
    }
    void addBook(int libId, string name, Publisher publisher, BookType type)
    {
        Book book(name, publisher, type);
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].IdOfLibrary())
            {
                libraries[i].AddBook(book);
            }
        }
    }
    void addBook(int libId, Book book)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].IdOfLibrary())
            {
                libraries[i].AddBook(book);
            }
        }
    }
    void addMember(string name, string id)
    {
        Member member(name, id);
        bool IsDuplicate = false;
        for (int i = 0; i < members.size(); i++)
        {
            try
            {
                if (members[i] == member)
                {
                    IsDuplicate = true;
                    throw 0;
                }
            }
            catch (int a)
            {
                cout << "You've been recorded!";
            }
        }
        if (!IsDuplicate)
        {
            members.push_back(member);
        }
    }
    vector<Book> getAllBooks(int libId)
    {
        if (libId > LibId)
        {
            cout << "[]\n";
        }
        else
        {
            return libraries[libId].BookReturn();
        }
    }
    string getAllBooksInfo(int libId)
    {
        if (libId > LibId)
        {
            return "";
        }
        else
        {
            string str;
            vector<Book> books;
            books = libraries[libId].BookReturn();
            for (int i = 0; i < books.size(); i++)
            {
                str += books[i].RetunInfo();
            }
            return str;
        }
    }
    vector<Book> filterByType(int libId, BookType type)
    {
        if (libId > LibId)
        {
            throw "you can't";
        }
        else
        {
            vector<Book> books;
            vector<Book> LibBooks = libraries[libId].BookReturn();
            for (int i = 0; i < LibBooks.size(); i++)
            {
                if (type == LibBooks[i].TypeOfBook())
                {
                    books.push_back(LibBooks[i]);
                }
            }
            return books;
        }
    }
    string filterByTypeAndShowInfo(int libId, BookType type)
    {
        if (libId > LibId)
        {
            return "";
        }
        else
        {
            vector<Book> books = filterByType(libId, type);
            string str;
            for (int i = 0; i < books.size(); i++)
            {
                str = books[i].RetunInfo();
            }
            return str;
        }
    }
    bool borrow(string memberId, int libraryId, string name)
    {
        bool IsAvailable = false;
        int MemberIndex;
        if (libraryId > LibId)
        {
            return false;
        }
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i].IdReturner() == memberId)
            {
                MemberIndex = i;
            }
        }
        vector<Book> books;
        books = libraries[libraryId].BookReturn();
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].NameOfBook() == name)
            {
                IsAvailable = true;
            }
        }
        if (members[MemberIndex].BorrowedBookCount() >= 5)
        {
            return false;
        }
        else
        {
            if (IsAvailable)
            {
                int index;
                index = libraries[libraryId].SearchByName(name);
                members[MemberIndex].AddBook(libraries[libraryId].BookReturnByName(name));
                libraries[libraryId].DeleteBook(index);
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    bool returnBook(string memberId, int libraryId, string name)
    {
        bool IsAvailable = false;
        int MemberIndex;
        if (libraryId > LibId)
        {
            return false;
        }
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i].IdReturner() == memberId)
            {
                MemberIndex = i;
                IsAvailable = true;
            }
        }
        if (IsAvailable)
        {
            Book book;
            book = members[MemberIndex].BookReturnByName(name);
            libraries[libraryId].AddBook(book);
            members[MemberIndex].DeleteBookByName(name);
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return libraries.size();
    }
    Library findNearestLibraryByPosition(string name, int position)
    {
        bool IsAvailable = false;
        int MinDistance = numeric_limits<int>::max(), distance;
        Library library, bestlib;
        for (int i = 0; i < libraries.size(); i++)
        {
            library = libraries[i];
            for (int j = 0; j < library.BookCount(); j++)
            {
                if (library.IsAvailableBook(name))
                {
                    distance = position - library.PositionOfLibrary();
                    if (distance < 0)
                    {
                        distance *= -1;
                    }
                    if (distance < MinDistance)
                    {
                        MinDistance = distance;
                        bestlib = library;
                    }
                }
            }
        }
        try
        {
            if (IsAvailable)
            {
                return bestlib;
            }
            else
            {
                throw 0;
            }
        }
        catch (int a)
        {
            cout << "Not found!";
        }
    }
    void Swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void Swap(Library *a, Library *b)
    {
        Library temp;
        *a = *b;
        *b = temp;
    }
    string findLibraryHaveBook(string name, int position)
    {
        vector<int> distances;
        vector<Library> libraries;
        int distance;
        string str;
        for (int i = 0; i = this->libraries.size(); i++)
        {
            if (this->libraries[i].IsAvailableBook(name))
            {
                libraries.push_back(this->libraries[i]);
                distance = position - this->libraries[i].PositionOfLibrary();
                if (distance < 0)
                {
                    distance *= -1;
                }
                distances.push_back(distance);
            }
        }
        for (int i = 0; i < libraries.size(); i++)
        {

            if (distance < 0)
            {
                distance *= -1;
            }
            distances.push_back(distance);
        }
        for (int j = 0; j < distances.size() - 1; j++)
        {
            if (distances[j] > distances[j + 1])
            {
                Swap(&distances[j], &distances[j + 1]);
                Swap(&libraries[j], &libraries[j + 1]);
            }
        }
        for (int i = 0; i < libraries.size(); i++)
        {
            string str,str1,str2;
            str1 = to_string(i+1);
            str2 = to_string(distances[i]);
            str += str1 + ". " + libraries[i].NameOfLibrary() + " " + str2 + "\n";
        }
        return str;
    }
};
