#include "main.h"

int main()
{
   ifstream f_in("settings.yaml");
   Parser pars(f_in);

   Node doc;

   pars.GetNextDocument(doc);

   nv_api nv;

   nv.change_settings(doc);

   return 0;
}