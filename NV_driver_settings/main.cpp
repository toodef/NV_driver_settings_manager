#include "main.h"

namespace po = boost::program_options;

int main( int arg_c, char ** arg_v )
{
   po::options_description desc("Options");

   string file_name;

   desc.add_options()
                   ("help,h", "")
                   ("load,l", "load settings from file to driver")
                   ("save,s", "save settings from driver to file")
                   ("file,f", po::value<string>(&file_name), "select i/o file")
                   ;

   po::variables_map vm;

   try
   {
      po::store(po::parse_command_line(arg_c, arg_v, desc), vm);

      po::notify(vm);
   }
   catch(po::invalid_command_line_syntax l_syntax)
   {
      cerr << l_syntax.what() << endl;
   }

   if (!vm["help"].empty())
   {
       cout << desc << endl;
       return 1;
   }

   nv_api nv;

   try
   {
      if (!vm["load"].empty())
         nv.load_settings_from_file(file_name);

      if (!vm["save"].empty())
         nv.save_settings_to_file(file_name);
   }
   catch (ifstream::failure ex)
   {
      cerr << "error open or read file: '" << file_name << "'!" << endl;
   }

   if (vm.empty())
      cout << desc << endl;

   return 0;
}