void __cdecl print_pass_versions(void)

{
  char *s;
  char *s_2;
  size_t len;
  char *s_3;
  size_t len_2;
  cl_pass *pass;
  cl_pass *scan;
  int pad;
  size_t width;
  
  width = 0;
  s = load_message(0x136);
  msg_write(2,s);
  pass = g_passes;
  scan = g_passes;
  do {
    if (scan->program == (char *)0x0) {
      s_2 = program_path();
    }
    else {
      g_driver_ctx_ptr->pass = scan;
      pass_resolve_program(g_driver_ctx_ptr);
      s_2 = scan->program;
    }
    len = strlen(s_2);
    if ((int)width < (int)len) {
      width = len;
    }
    scan = scan + 1;
  } while ((int)scan < 0x40b1c4);
  do {
    s_3 = pass->program;
    if (s_3 == (char *)0x0) {
      s_3 = program_path();
    }
    msg_write(2," %s: ",s_3);
    len_2 = strlen(s_3);
    if ((int)len_2 < (int)width) {
      pad = width - len_2;
      do {
        msg_write(2," ");
        pad = pad + -1;
      } while (pad != 0);
    }
    print_file_version(s_3);
    msg_write(2,"\n");
    pass = pass + 1;
  } while ((int)pass < 0x40b1c4);
  msg_write(2,"\n");
  return;
}

