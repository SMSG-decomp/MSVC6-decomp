void __cdecl response_file_read(char *path)

{
  FILE *f;
  char *line;
  long pos;
  char *got;
  size_t len;
  char *got_2;
  char *got_3;
  char **v;
  int argc;
  size_t n;
  
  g_response_depth = g_response_depth + 1;
  n = 0x400;
  if (0xd < g_response_depth) {
    cl_error(0x7f3,path);
  }
  f = fopen(path,"r");
  if (f == (FILE *)0x0) {
    cl_error(0x7e6,path);
  }
  line = xmalloc(0x400);
  pos = ftell(f);
  got = fgets(line,0x400,f);
  do {
    if (got == (char *)0x0) {
      if ((f->_flag & 0x10) == 0) {
        cl_error(0x7f2,path);
      }
      fclose(f);
      xfree(line);
      g_response_depth = g_response_depth + -1;
      return;
    }
    while( true ) {
      len = strlen(line);
      if ((len != n - 1) || (line[len - 1] == '\n')) break;
      fseek(f,pos,0);
      n = n * 2;
      if ((int)n < 1) {
        cl_error(0x7f2,path);
      }
      xfree(line);
      line = xmalloc(n);
      got_2 = fgets(line,n,f);
      if (got_2 == (char *)0x0) {
        cl_error(0x7f2,path);
      }
    }
    if (line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }
    if (g_nologo == 0) {
      got_3 = "cl ";
      if (g_response_first_line == 0) {
        got_3 = "   ";
      }
      msg_write(2,got_3);
      msg_write(2,"%s\n",line);
      g_response_first_line = 0;
      g_echoed_response = 1;
    }
    v = cmdline_split(line,1);
    if (v != (char **)0x0) {
      argc = argv_count(v);
      options_parse_argv(v,argc);
      xfree(*v);
      xfree(v);
    }
    pos = ftell(f);
    got = fgets(line,n,f);
  } while( true );
}

