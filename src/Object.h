#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "Usable.h"

class Object : public Usable {
private:
    std::string name;
    int type;
    int upgrade;

public:
    // Constructor
    Object(const std::string& name, int type, int upgrade);

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string& name);

    int getType() const;
    void setType(int type);

    int getUpgrade() const;
    void setUpgrade(int upgrade);

    // Usable methods
    void use(int amount) override;
    void use(int amount, int target) override;

    // Overload operator
    Object operator+(const Object& other);
};

#endif
