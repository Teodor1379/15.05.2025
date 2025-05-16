#ifndef _STRING_HEADER_INCLUDED_
#define _STRING_HEADER_INCLUDED_



#include <fstream>

#include <cstring>

#include <exception>
#include <stdexcept>



class TeoString {
public:
                TeoString(                  )               ;
    explicit    TeoString(const char*       )               ;
                TeoString(const TeoString&  )               ;
                TeoString(TeoString&&       )   noexcept    ;

    ~TeoString() noexcept;



public:
    TeoString& operator=(const char*        )               ;
    TeoString& operator=(const TeoString&   )               ;
    TeoString& operator=(TeoString&&        )   noexcept    ;



public:
    inline unsigned int getSize    ()   const noexcept { return this->size;    }
    inline unsigned int getLength  ()   const noexcept { return this->size;    }
    inline unsigned int getMaxSize ()   const noexcept { return -1;            }

    inline const char* c_str   ()   const noexcept { return this->string;  }
    inline const char* data    ()   const noexcept { return this->string;  }



public:
    inline bool empty()    const noexcept { return this->size == 0;   }



public:
    inline          char&   operator[](unsigned int index)          noexcept    { return this->string[index];   }
    inline const    char&   operator[](unsigned int index)  const   noexcept    { return this->string[index];   }

    inline          char&   at(unsigned int index)          { if (index >= this->size)  { throw std::out_of_range("Out of Range Error");    }   return this->string[index]; }
    inline const    char&   at(unsigned int index)  const   { if (index >= this->size)  { throw std::out_of_range("Out of Range Error");    }   return this->string[index]; }



public:
    inline          char&   front()         noexcept    { return this->string[0];   }
    inline  const   char&   front() const   noexcept    { return this->string[0];   }

    inline          char&   back()        noexcept  { return this->string[this->size - 1];  }
    inline  const   char&   back()  const noexcept  { return this->string[this->size - 1];  }



public:
    void pushBack(char  );
    void  popBack(      );



public:
    int compare(const char*     )   const           ;
    int compare(const TeoString&)   const           ;



private:
    char*     allocateMemory(const char*    );
    void    deallocateMemory(               );
    void          moveMemory(TeoString&&    );


private:
    static const unsigned int NPOS = -1;

    unsigned int    size    ;
    char*           string  ;
};



inline void swap(TeoString& x, TeoString& y) noexcept {
    TeoString z;

    z = std::move(x);
    x = std::move(y);
    y = std::move(z);
}



inline bool operator==  (const TeoString& string1, const TeoString& string2)    { return string1.compare(string2) == 0; }
inline bool operator!=  (const TeoString& string1, const TeoString& string2)    { return string1.compare(string2) != 0; }
inline bool operator<   (const TeoString& string1, const TeoString& string2)    { return string1.compare(string2) <  0; }
inline bool operator>   (const TeoString& string1, const TeoString& string2)    { return string1.compare(string2) >  0; }
inline bool operator<=  (const TeoString& string1, const TeoString& string2)    { return string1.compare(string2) <= 0; }
inline bool operator>=  (const TeoString& string1, const TeoString& string2)    { return string1.compare(string2) >= 0; }

inline bool operator==  (const TeoString& string1, const char* string2)         { return string1.compare(string2) == 0; }
inline bool operator!=  (const TeoString& string1, const char* string2)         { return string1.compare(string2) != 0; }
inline bool operator<   (const TeoString& string1, const char* string2)         { return string1.compare(string2) <  0; }
inline bool operator>   (const TeoString& string1, const char* string2)         { return string1.compare(string2) >  0; }
inline bool operator<=  (const TeoString& string1, const char* string2)         { return string1.compare(string2) <= 0; }
inline bool operator>=  (const TeoString& string1, const char* string2)         { return string1.compare(string2) >= 0; }

inline bool operator==  (const char* string1, const TeoString& string2)         { return string2.compare(string1) == 0; }
inline bool operator!=  (const char* string1, const TeoString& string2)         { return string2.compare(string1) != 0; }
inline bool operator<   (const char* string1, const TeoString& string2)         { return string2.compare(string1) >  0; }
inline bool operator>   (const char* string1, const TeoString& string2)         { return string2.compare(string1) <  0; }
inline bool operator<=  (const char* string1, const TeoString& string2)         { return string2.compare(string1) >= 0; }
inline bool operator>=  (const char* string1, const TeoString& string2)         { return string2.compare(string1) <= 0; }



inline std::ostream& operator<< (std::ostream& stream, const TeoString& string) { stream << string.data(); return stream; }



#endif
