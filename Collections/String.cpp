#include "String.hpp"



TeoString::TeoString() {
    this->size      = 0             ;  
    this->string    = new char[1]   ;

    this->string[this->size] = '\0';
}

TeoString::TeoString(const char* string) {
    this->size      = strlen(string)            ;
    this->string    = new char[this->size + 1]  ;

    strcpy(this->string, string);
    this->string[this->size] = '\0';
}

TeoString::TeoString(const TeoString& instance) {
    this->size      =   instance.size               ;
    this->string    =   new char[instance.size + 1] ;

    strcpy(this->string, instance.string);
    this->string[this->size] = '\0';
}

TeoString::TeoString(TeoString&& instance) noexcept {
    this->moveMemory(std::move(instance));
}

TeoString::~TeoString() noexcept {
    delete[] this->string;

    this->string = nullptr;
}



TeoString& TeoString::operator=(const char* string) {
    if (string == nullptr) {
        throw std::invalid_argument("Invalid Assignment Operation!");
    }

    unsigned int size = strlen(string);

    char* buffer = new char[size + 1];

    strcpy(buffer, string);
    buffer[size] = '\0';

    delete[] this->string;

    this->size      =   size    ;
    this->string    =   buffer  ;

    return *this;
}


TeoString& TeoString::operator=(const TeoString& instance) {
    if (this != &instance) {
        char* buffer = new char[instance.size + 1];

        strcpy(buffer, instance.string);
        buffer[instance.size] = '\0';

        delete[] this->string;

        this->size      =   instance.size   ;
        this->string    =   buffer          ;
    }

    return *this;
}

TeoString& TeoString::operator=(TeoString&& instance) noexcept {
    if (this != &instance) {
        delete[] this->string;

        this->moveMemory(std::move(instance));
    }

    return *this;
}



void TeoString::pushBack(char c) {
    if (c == '\0') {
        throw std::invalid_argument("Invalid Assignment Operation!");
    }

    char* buffer = new char[this->size + 2];

    strcpy(buffer, this->string);

    buffer[this->size + 0] = c      ;
    buffer[this->size + 1] = '\0'   ;

    delete[] this->string;

    this->size      =   this->size + 1  ;
    this->string    =   buffer          ;
}

void TeoString::popBack() {
    if (this->size == 0) {
        throw std::runtime_error("Pop Error!");
    }

    this->string[this->size - 1]    = '\0'          ;
    this->size                      = this->size - 1;
}



int TeoString::compare(const char* string) const {
    if (string == nullptr) {
        throw std::logic_error("Compare String With NULLPTR!");
    }

    return std::strcmp(this->string, string);
}

int TeoString::compare(const TeoString& instance) const noexcept {
    return std::strcmp(this->string, instance.string);
}



char* TeoString::allocateMemory(const char* string) {
    return new char[strlen(string) + 1];
}

void TeoString::deallocateMemory() {
    delete[] this->string;

    this->string = nullptr;
}

void TeoString::moveMemory(TeoString&& instance) {
    this->size      =   instance.size   ;
    this->string    =   instance.string ;

    instance.size   =   0       ;
    instance.string =   nullptr ;
}
