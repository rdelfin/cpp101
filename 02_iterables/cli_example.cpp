#include "CLI/CLI11.hpp"

int main(int argc, char* argv[]) {
    CLI::App app{"An example CLI tool"};

    std::string name;
    std::string greeting;
    bool exclamation;

    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_option("-n,--name", name, "Your name")->default_val("World");
    app.add_option("-g,--greeting", greeting, "Greeting to use")
        ->default_val("Hello");
    app.add_flag("-e,--exclamation", exclamation,
                 "Add this flag in if you want an exclamation mark");
    CLI11_PARSE(app, argc, argv);

    std::string exclamation_str = "";
    if (exclamation) exclamation_str = "!";
    std::cout << greeting << ", " << name << exclamation_str << std::endl;
}
