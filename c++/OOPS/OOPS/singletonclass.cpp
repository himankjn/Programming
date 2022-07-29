#include <iostream>

using namespace std;

class Singleton {
   private:
      static Singleton *instance;
      int data;
   
      // Private constructor so that no objects can be created.
      Singleton() {
         data = 0;
      }

   public:
      static Singleton *getInstance() {
         if (!instance)
         instance = new Singleton();
         return instance;
      }

      int getData() {
         return this -> data;
      }

      void setData(int data) {
         this -> data = data;
      }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = NULL;

int main(){
   Singleton *s = Singleton::getInstance();
   s->setData(100);
   cout << s->getData() << endl;

   Singleton *t= Singleton::getInstance();
   t->setData(200);
   cout<<s->getData()<<endl;
   return 0;
}