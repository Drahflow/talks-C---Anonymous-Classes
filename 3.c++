#include <iostream>
#include <vector>

class Thing {
  public:
    virtual std::string draw() const = 0;
};

static Thing *createThing(const std::string &str) {
  return new (struct _: public Thing {
      const std::string str;
      _(const std::string &str): str(str) { }
      std::string draw() const { return "createThing: " + str; }
    })(str);
}

static Thing *decorThing(const Thing *t) {
  return new (struct _: public Thing {
      const Thing *t;
      _(const Thing *t): t(t) { }
      std::string draw() const { return "[" + t->draw() + "]"; }
    })(t);
}

int main(int, char **) {
  std::vector<Thing *> things;

  things.push_back(createThing("Test"));
  things.push_back(decorThing(createThing("Test")));

  for(auto i = things.begin(); i != things.end(); ++i) {
    std::cout << (*i)->draw() << std::endl;
  }
}
