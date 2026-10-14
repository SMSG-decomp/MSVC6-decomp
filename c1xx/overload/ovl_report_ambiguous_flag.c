int ovl_report_ambiguous_flag(char *flag)

{
  if (flag != (char *)0x0) {
    *flag = '\x01';
  }
  return 0;
}

