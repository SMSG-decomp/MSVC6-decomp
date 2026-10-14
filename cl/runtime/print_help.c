void __cdecl print_help(void)

{
  int n;
  int n_2;
  char *text;
  int c;
  char *text_2;
  int c_2;
  UINT id;
  int n_3;
  
  n = _isatty(1);
  if (n == 0) {
    n_3 = 0x7fffffff;
  }
  else {
    n_2 = console_height();
    n_3 = n_2 + -1;
  }
  if (n_3 < 1) {
    n_3 = 1;
  }
  id = 0x1f5;
  do {
    if ((id != 0x1f5) && ((int)(id - 0x1f5) % n_3 == 0)) {
      text = load_message(0x139);
      msg_write(1,text);
      do {
        c = getchar();
        if (c == 10) break;
      } while (c != -1);
    }
    text_2 = load_message(id);
    c_2 = strcmp(text_2,"<<<EOH>>>");
    if ((c_2 == 0) || (*text_2 == '\0')) {
      exit(0);
    }
    msg_write(1,text_2);
    id = id + 1;
  } while( true );
}

