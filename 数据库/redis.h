#ifndef REDIS_H
#define REDIS_H
#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include <hiredis/hiredis.h>
using namespace std;
class redis{
  public:
    //  hander reply ptr
    class replyClass{
      public:
      replyClass() { reply = NULL; }
      redisReply *reply = NULL;
      ~replyClass() {
        if(NULL!=reply) { freeReplyObject(reply); }
      }
      private:
    };
    // shared ptr
    typedef shared_ptr<replyClass> replyPtr;
    bool connect(string host="127.0.0.1",int port=6379) {
      _connect = redisConnect(host.c_str(), port);
      if(_connect != NULL && _connect->err) {
         printf("connect error: %s\n", _connect->errstr);
         return false;
      }
      return true;
    }
    // print reply
    void printReply(redisReply *p) {
      if(NULL==p) { return; }
      switch(p->type) {
        case REDIS_REPLY_STATUS: cout<< "status "<<string(p->str)<<"\n"; break;
        case REDIS_REPLY_STRING: cout<< "string "<<string(p->str)<<"\n"; break;
        case REDIS_REPLY_INTEGER: cout<< "integer "<< p->integer<<"\n"; break;
        case REDIS_REPLY_ARRAY: {
          int len = p->elements;
          for(int i=0;i<len;i++){
            printReply(p->element[i]);
          }
          break;
        }
        case REDIS_REPLY_NIL: cout<<"nil\n"; break;
        case REDIS_REPLY_ERROR:cout<<"error "<<string(p->str)<<"\n"; break;
        default : cout<<"default \n"; break;
      }
      return ;
    }
    //return hander--------------------------------------------
    void print(replyPtr p) {
      if(NULL==p || NULL==p->reply) { return; }
      printReply(p->reply);
      return ;
    }
    //string----------------------------------------------------
    //SET key "value"
    void set(string key,string value){
      string cmd = "set " + key +" " + value;
      replyPtr p(new replyClass());
      p->reply = (redisReply *)redisCommand(_connect,cmd.c_str());
      print(p);
      return;
    }
    // get key
    void get(string key) {
      string cmd = "get " + key;
      replyPtr p(new replyClass());
      p->reply = (redisReply *)redisCommand(_connect,cmd.c_str());
      print(p);
      return;
    }
    // strlen key
    void strlen(string key) {
      string cmd = "strlen " + key;
      replyPtr p(new replyClass());
      p->reply = (redisReply *)redisCommand(_connect,cmd.c_str());
      print(p);
      return;
    }
    // mget key1 key2 ...
    void mget(string key1,string key2) {
      string cmd = "mget " + key1 + " " + key2;
      replyPtr p(new replyClass());
      p->reply = (redisReply *)redisCommand(_connect,cmd.c_str());
      print(p);
      return;
    }
  private:
    redisContext* _connect;
};
#endif
