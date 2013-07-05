#include "main.h"

namespace po = boost::program_options;

int main( int arg_c, char ** arg_v )
{
   po::options_description desc("Options");

   string file_name;

   desc.add_options()
                   ("help,h", "")
                   ("load,l", "Load settings from file to driver")
                   ("save,s", "Save settings from driver to file")
                   ("file,f", po::value<string>(&file_name), "Select i/o file")
                   ;

   try
   {
      po::variables_map vm;

      po::store(po::parse_command_line(arg_c, arg_v, desc), vm);

      po::notify(vm);

      if (vm.count("help"))
      {
          cout << desc << endl;
          return 1;
      }

      bool file_is_spec = false;

      if (vm.count("file"))
         file_is_spec = true;

      nv_api nv;

      if (vm.count("load"))
      {
         if (file_is_spec)
            nv.load_settings_from_file(file_name);
         else
            cerr << "Need to specify file name! Use [-f <file_name>] or [-file <file_name>]" << endl;
         return 1;
      }

      if (vm.count("save"))
      {
         if (file_is_spec)
            nv.save_settings_to_file(file_name);
         else
            cerr << "Need to specify file name! Use [-f <file_name>] or [-file <file_name>]" << endl;
         return 1;
      }
   }
   catch(...)
   {
      cerr << "Enter file name!" << endl;
      return 1;
   }

   return 0;
}