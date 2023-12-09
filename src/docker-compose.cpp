#include <cstdlib>
#include <string>

int main(int argc, char **argv) {
   std::string main_command = "docker compose";
   std::string result_command;
   result_command += main_command;
   for (int i = 1; i < argc; i++) {
      result_command += " ";
      result_command += argv[i];
   }
   std::system(result_command.c_str());
}
