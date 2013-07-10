#include "main.h"

namespace po = boost::program_options;

int main( int arg_c, char ** arg_v )
{
   po::options_description desc("options");

   string file_name;

   desc.add_options()
                   ("help,h", "")
                   ("load,l", po::value<string>(&file_name), "load settings from file to driver")
                   ("save,s", po::value<string>(&file_name), "save settings from driver to file")
                   ;

   po::variables_map vm;

   try
   {
      po::store(po::parse_command_line(arg_c, arg_v, desc), vm);

      po::notify(vm);
   }
   catch(po::invalid_command_line_syntax const & l_syntax)
   {
      cerr << l_syntax.what() << endl;
      cout << desc << endl;
      return 1;
   }
   catch(po::error_with_option_name const & opt_name)
   {
      cerr << opt_name.what() << endl;
      cout << desc << endl;
      return 1;
   }

   if (vm.empty() || !vm["help"].empty())
   {
       cout << desc << endl;
       return 0;
   }

   try
   {
      nv_api nv;

      if (!vm["load"].empty())
         nv.load_settings_from_file(file_name);
      else if (!vm["save"].empty())
         nv.save_settings_to_file(file_name);
   }
   catch (std::exception const & e)
   {
      cerr << e.what();
      return 1;
   }

   return 0;
}