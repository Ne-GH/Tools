/*
*    Time: 04/19/22 21:49:57
*    Create By yongheng
*/

#ifndef DOMAIN_H
#define DOMAIN_H

#include "./tool.h"

class Domain{

private:
    vector<string> alias_domain;
    vector<string> official_domain;
    vector<string> ip;

public:
    Domain(){  }
    Domain(string domain){
        struct hostent *hptr;
        hptr = gethostbyname(domain.c_str());
        if (hptr == NULL) {
            printf("gethostbyname error for host: %s: %s\n", domain.c_str(), hstrerror(h_errno));
        }
        //主机的规范名
        official_domain.push_back(hptr->h_name);
     
        //出主机的别名
        char **pptr;
        char str[INET_ADDRSTRLEN];
        for (pptr=hptr->h_aliases; *pptr!=NULL; pptr++) {
            alias_domain.push_back(*pptr);
        }
        //ip地址
        switch (hptr->h_addrtype) {
            case AF_INET:
                pptr = hptr->h_addr_list;
                for (; *pptr!=NULL; pptr++) {
                    ip.push_back(inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
                }
                break;
            default:
                printf("unknown address type\n");
                break;
        }

    }
    vector<string> Name(){ 
        return alias_domain;
    }
    vector<string> Ip(){
        return ip;
    }
    vector<string> Official_Name(){
        return official_domain;
    }

};


#endif

