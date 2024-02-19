#ifndef LEMP_NGINXVHOST_H
#define LEMP_NGINXVHOST_H

#include "string"

using namespace std;

class NginxVhost
{
    public:
        NginxVhost() {}
        void setFolder(string value)
        {
            this->folder = value;
        }

        string getFolder()
        {
            return this->folder;
        }

        void setServerName(string value)
        {
            this->serverName = value;
        }

        string getServerName()
        {
            return this->serverName;
        }

        void setHttps(bool value)
        {
            this->https = value;
        }

        bool getHttps()
        {
            return this->https;
        }

        void setProjectType(string value)
        {
            this->projectType = value;
        }

        string getProjectType()
        {
            return this->projectType;
        }

        void setVarnish(string value)
        {
            this->varnish = value;
        }

        string getVarnish()
        {
            return this->varnish;
        }

        void setVarnishPort(string value)
        {
            this->varnishPort = value;
        }

        string getVarnishPort()
        {
            return this->varnishPort;
        }

        void setProxy(string value)
        {
            this->proxy = value;
        }

        string getProxy()
        {
            return this->proxy;
        }

        void setProxyPort(string value)
        {
            this->proxyPort = value;
        }

        string getProxyPort()
        {
            return this->proxyPort;
        }
    private:
        string folder;
        string serverName;
        bool https;
        string varnish;
        string varnishPort;
        string projectType;
        string proxy;
        string proxyPort;
};

#endif //LEMP_NGINXVHOST_H
