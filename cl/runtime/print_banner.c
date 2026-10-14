void __cdecl print_banner(void)

{
  size_t len;
  char *fmt;
  char *fmt_00;
  char *dot;
  bool cut;
  char *version;
  char *dot_restore;
  
  len = strlen(s_cl_version);
  cut = false;
  if (((2 < len) &&
      (dot = (char *)((int)&g_response_first_line + len + 2),
      *(char *)((int)&g_response_first_line + len + 2) == '.')) &&
     (*(char *)((int)&g_response_first_line + len + 3) == '0')) {
    *dot = '\0';
    cut = true;
  }
  version = s_cl_version;
  fmt = load_message(0x132);
  msg_write(2,fmt,version);
  fmt_00 = load_message(0x133);
  msg_write(2,fmt_00);
  if (cut) {
    dot_restore = (char *)((int)&g_response_first_line + len + 2);
    *dot_restore = '.';
  }
  return;
}

