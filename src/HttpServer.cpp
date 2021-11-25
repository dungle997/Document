/******************************************************************************** 
Copyright (C) 2008-2009, SmartHome Co., Ltd. All rights reserved.
Product: AICAM
Module: 
Version: 1.0
Author: 
Created: 
Modified: 
    <Name>
    <Date>
    <Change>
Released: 
Description: 
Note: <Note>
********************************************************************************/
#include "HttpServer.hpp"
#include <regex>

// std::string do_replace( std::string const & in, std::string const & from, std::string const & to )
// {
//   return std::regex_replace( in, std::regex(from), to);
// }
/*-------------------------------------------------------------------------------
Function: 
Purpose:  
Parameters: 
Return: 
Comments: 
Modified:
    <Modified by>
    <Date>
    <Change>
-------------------------------------------------------------------------------*/
HttpServer::HttpServer()
{
    // this->monitorManager = monitorManager;
    this->base = NULL;
    this->server = NULL;
    // this->first_reboot = false;

    // if (pr.contains("enable")       && pr["enable"].is_boolean()    && pr.contains("monitor_id")    && pr["monitor_id"].is_number() && 
    //     pr.contains("record")       && pr["record"].is_boolean()    && pr.contains("regions")       && pr["regions"].is_array()     &&
    //     pr.contains("sleep")        && pr["sleep"].is_number()      && pr.contains("type")          && pr["type"].is_string())
    // {
    //     this->process_restore   = pr;
    //     this->first_reboot      = true;
    // }
}
HttpServer::~HttpServer()
{
    if (this->server != NULL)
    {
        evhttp_free(this->server);
    }
    if (this->base != NULL)
    {
        event_base_free(this->base);
    }
}
/*-------------------------------------------------------------------------------
Function: 
Purpose:  
Parameters: 
Return: 
Comments: 
Modified:
    <Modified by>
    <Date>
    <Change>
-------------------------------------------------------------------------------*/
void HttpServer::loop()
{
    if (this->base == NULL)
    {
        this->base = event_base_new();
    }
    else if (this->server == NULL)
    {
        this->server = evhttp_new(this->base);
        evhttp_set_allowed_methods(this->server, EVHTTP_REQ_GET | EVHTTP_REQ_POST | EVHTTP_REQ_PUT | EVHTTP_REQ_DELETE);
        evhttp_set_gencb(this->server, callback, this);
        if (evhttp_bind_socket(this->server, "0.0.0.0", PORT_SERVER) != 0)
        {
            std::cerr << "Failed to bind to 0.0.0.0:" << PORT_SERVER << std::endl;
        }
        else
        {
            std::cout << "HTTP Server Listening on 0.0.0.0:" << PORT_SERVER << std::endl;
        }
        // if (this->first_reboot == true)
        // {
        //     //PRINT_LOG("Bkav [BUG]", "%s %s()", __FILE__, __func__);
        //     Http_Post post;
        //     char url[50];
        //     sprintf(url, "0.0.0.0:%d/api/monitor", PORT_SERVER);
        //     post.post_json(this->process_restore.dump(), (char*)url);
        //     // this->first_reboot = false;
        // }
    }
    else
    {
        event_base_loop(this->base, EVLOOP_NONBLOCK);
    }
}
// bool HttpServer::standard_check()
// {
//     return true;  // check template json request
// }
/*-------------------------------------------------------------------------------
Function: 
Purpose:  
Parameters: 
Return: 
Comments: 
Modified:
    <Modified by>
    <Date>
    <Change>
-------------------------------------------------------------------------------*/
// bool equal(const char *src, const char *dst)
// {
//     return strcmp(src, dst) == 0;
// }
/*-------------------------------------------------------------------------------
Function: 
Purpose:  
Parameters: 
Return: 
Comments: 
Modified:
    <Modified by>
    <Date>
    <Change>
-------------------------------------------------------------------------------*/
bool startWith(const char **src, const char *dst)
{
    const char *str = *src;
    size_t len = strlen(dst);
    if (strncmp(str, dst, len) == 0)
    {
        *src = str + len;
        return true;
    }
    else
    {
        return false;
    }
}
bool nextInt(const char **src, int *out)
{
    int number = 0;
    bool found = false;
    const char *str = *src;
    while (*str)
    {
        char c = *str;
        if ((c >= '0') && (c <= '9'))
        {
            found = true;
            number = number * 10 + c - '0';
        }
        else if (c == '/')
        {
            break;
        }
        else
        {
            return false;
        }
        str++;
    }

    if (found)
    {
        *src = str + 1;
        *out = number;
        return true;
    }
    else
    {
        return false;
    }
}
void HttpServer::callback(struct evhttp_request *request, void *param)
{
    auto server = static_cast<HttpServer*>(param);
    const char *urisz = evhttp_request_get_uri(request);
    struct evhttp_uri *uri = NULL;
    uri = evhttp_uri_parse(urisz);
    if (uri != NULL) 
    {
        const char *path = evhttp_uri_get_path(uri);
        // PRINT_LOG(TAG, "IP: %s | method: %s | Path: %s", readIpClient(request).c_str(), readHeader(request).c_str(), path);
        if (startWith(&path, "/api/monitor")) 
        {
            std::cout << "Funtion Callback " << std::endl;
            sendError(request, 200, "ok");
        }
        else {
            std::cout << "Not Support"<< std::endl;
            sendError(request, 400, "Error");
        }
    
    evhttp_uri_free(uri);
    }
}
void HttpServer::sendError(struct evhttp_request *request, int status, const std::string &message)
{
    json j;
    j["error"] = true;
    j["reason"] = message;
    sendJson(request, status, j);
}
void HttpServer::sendJson(struct evhttp_request *request, int status, const json &j)
{
    struct evbuffer *buffer;
    std::string content;
    content = j.dump();
    buffer = evbuffer_new();
    evhttp_add_header(request->output_headers, "Content-Type", "application/json");
    evhttp_add_header(request->output_headers, "Content-Length", std::to_string(content.size()).c_str());
    evbuffer_add(buffer, content.data(), content.size());
    evhttp_send_reply(request, status, NULL, buffer);
    evbuffer_free(buffer);
}
void HttpServer::sendText(struct evhttp_request *request, int status, const std::string &text)
{
    struct evbuffer *buffer;
    std::string header;
    buffer = evbuffer_new();
    evbuffer_add(buffer, text.data(), text.size());
    evhttp_add_header(request->output_headers, "Content-Type", "text/plain; charset=us-ascii");
    evhttp_add_header(request->output_headers, "Content-Length", std::to_string(text.size()).c_str());
    evhttp_send_reply(request, status, NULL, buffer);
    evbuffer_free(buffer);
}