void __fastcall apply_warning_state_list(short *list)

{
  short *psVar1;
  short warning;
  
  if (list != (short *)0x0) {
    warning = *list;
    g_warning_state_count = 0;
    while (warning != -1) {
      push_warning_state(warning,list[1]);
      psVar1 = list + 2;
      list = list + 2;
      warning = *psVar1;
    }
  }
  return;
}

