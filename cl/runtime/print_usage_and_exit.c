void __cdecl print_usage_and_exit(void)

{
  char *fmt;
  
  print_banner();
  fmt = load_message(0x131);
  msg_write(1,fmt);
  exit(0);
}

