void __cdecl options_add_include_env(void)

{
  uchar *dir;
  optdesc *idesc;
  uchar *semi;
  char *include_argv [2];
  
  include_argv[0] = "-I";
  include_argv[1] = (char *)0x0;
  if (g_use_include_env != 0) {
    dir = (uchar *)getenv("INCLUDE");
    if (dir != (uchar *)0x0) {
      idesc = option_lookup(include_argv,0);
      while( true ) {
        semi = _mbschr(dir,0x3b);
        if (semi == (uchar *)0x0) break;
        *semi = '\0';
        option_add_include_dir((char *)dir,idesc);
        dir = semi + 1;
        *semi = ';';
      }
      option_add_include_dir((char *)dir,idesc);
    }
  }
  return;
}

