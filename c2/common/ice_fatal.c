void __fastcall ice_fatal(char *file,int line)

{
  g_error_count = g_error_count + 1;
  fatal_error(1,file,line);
}

