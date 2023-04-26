#include <iostream>
#include <memory>
#include <string>

// A node in a linked list
class Node {
   public:
    Node(const std::string& value, std::shared_ptr<Node> next = nullptr)
        : value_(value), next_(next) {}

    ~Node() { std::cout << "Calling destructor for " << value_ << std::endl; }

    std::string get() { return value_; }

    // This copies the shared pointer but NOT the data
    std::shared_ptr<Node> next() { return next_; }

    void set_next(std::shared_ptr<Node> n) { next_ = n; }

    void print_all() {
        std::cout << value_;
        if (next_ != nullptr) {
            std::cout << ", ";
            next_->print_all();
        }
    }

   private:
    std::string value_;
    std::shared_ptr<Node> next_;
};

int main() {
    // We're gonna construct two "linked lists":
    // a -> b -> c
    //           ^
    // d -------/
    std::cout << "Setting up linked list that should look as follows: "
              << std::endl
              << "a -> b -> c\n          ^\nd -------/" << std::endl;

    std::shared_ptr<Node> d = std::make_shared<Node>("d");

    // Scope ensures A get deleted when no longer needed
    {
        std::shared_ptr<Node> a = std::make_shared<Node>("a");
        // Scope ensures B and D get deleted when no longer needed
        {
            std::shared_ptr<Node> b = std::make_shared<Node>("b");
            std::shared_ptr<Node> c = std::make_shared<Node>("c");

            b->set_next(c);
            a->set_next(b);
            d->set_next(c);

            std::cout << "Finished setting up nodes" << std::endl;
            // B and D go out of scope, but are NOT deleted since other d and b
            // still reference them directly or indirectly
        }

        // Should print a, b, c
        std::cout << std::endl << "NODES FROM A:" << std::endl;
        a->print_all();
        std::cout << std::endl;
        std::cout << "A is about to go out of scope" << std::endl;
        // A is deleted at this point, together with B as nothing references it
        // anymore
    }
    // Should print d, c
    std::cout << std::endl << "NODES FROM D:" << std::endl;
    d->print_all();
    std::cout << std::endl;
}
