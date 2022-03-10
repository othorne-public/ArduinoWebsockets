#pragma once

#include <tiny_websockets/internals/ws_common.hpp>

namespace websockets { namespace network {
    static int StaticClientID = 0;

    struct TcpSocket {
    private:
        int id = ++StaticClientID;
    public:
        virtual bool available() = 0;
        virtual void close() = 0;
        virtual ~TcpSocket() {}
        int getID() { return this->id; }
    protected:
        virtual int getSocket() const = 0;
    };
}} // websockets::network