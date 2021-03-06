#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <string>
#include <unordered_map>
#include <queue>

#include "epoll_wrapper.h"
#include "thread_pool.h"

class HttpServer
{
private:
    int m_port;
    std::string m_dir_path;

    int m_server_fd = -1;

    EPollWrapper* m_epoll = nullptr;
    ThreadPool*   m_thread_pool = nullptr;

public:
    HttpServer(int port, std::string dir_path);
    ~HttpServer();

    void init_socket();
    void start();

    int accept_new_connection();
    void handle_client_request(int client_fd);
};

#endif //HTTP_SERVER_H
