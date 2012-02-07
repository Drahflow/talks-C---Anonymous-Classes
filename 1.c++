#include <iostream>
#include <vector>

class Thing {
  public:
    virtual void draw() = 0;
};

int main(int, char **) {
  std::vector<Thing *> things;

  things.push_back(new (class: public Thing {
      public: virtual void draw() { std::cout << "Anonymous class" << std::endl; }
    })());

  for(auto i = things.begin(); i != things.end(); ++i) {
    (*i)->draw();
  }
}
