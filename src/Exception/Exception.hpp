#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception {
    public:
        virtual string what() = 0;
};

/* File Exception */
class UnableToOpenFile : public Exception {
    public:
        string what() {
            return "Tidak dapat membuka file!";
        }
};

/* General Exception */
class InvalidInput : public Exception {
    public:
        string what() {
            return "Input salah, mohon ulangi dengan input yang valid!";
        }
};

class InvalidCommand : public Exception {
    public:
        string what() {
            return "Perintah tidak valid!";
        }
};

/* Inventory Exception */
class InventoryFull : public Exception {
    public:
        string what() {
            return "Inventory sudah penuh!";
        }
};

/* Peternak Exception */




#endif