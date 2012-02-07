#include <iostream>
#include <vector>

class Thing {
  public:
    virtual void draw() = 0;
};

class BlubThing: public Thing {
  public:
    virtual void draw() { std::cout << "BlubThing" << std::endl; }
};

int main(int, char **) {
  std::vector<Thing *> things;

  things.push_back(new BlubThing());

  for(auto i = things.begin(); i != things.end(); ++i) {
    (*i)->draw();
  }
}
