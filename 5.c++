#include <iostream>
#include <vector>

class Thing {
  public:
    virtual std::string draw() const = 0;
};

template<class L> static Thing *createThing(const L &l) {
  return new (struct _: public Thing {
      const L l;
      _(const L &l): l(l) { }
      std::string draw() const { return l(); }
    })(l);
}

int main(int, char **) {
  std::vector<Thing *> things;

  things.push_back(createThing([]{ return "lambda"; }));

  for(auto i = things.begin(); i != things.end(); ++i) {
    std::cout << (*i)->draw() << std::endl;
  }
}
