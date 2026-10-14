void __fastcall split_env_command_line(char *flags)

{
  bool bVar1;
  char **ppcVar2;
  char cVar3;
  char *pcVar4;
  
  bVar1 = false;
  if (flags != (char *)0x0) {
    ppcVar2 = argv_snapshot_remaining();
    cVar3 = *flags;
    while (cVar3 != '\0') {
      while (cVar3 == ' ') {
        pcVar4 = flags + 1;
        flags = flags + 1;
        cVar3 = *pcVar4;
      }
      cVar3 = *flags;
      pcVar4 = flags;
      if (cVar3 != '\0') {
        *ppcVar2 = flags;
        ppcVar2 = ppcVar2 + 1;
        g_option_args_left = g_option_args_left + 1;
        do {
          if ((cVar3 == ' ') && (!bVar1)) break;
          if (cVar3 == '\"') {
            if (pcVar4[-1] == '\\') {
              flags[-1] = '\"';
            }
            else {
              bVar1 = !bVar1;
            }
          }
          else {
            *flags = cVar3;
            flags = flags + 1;
          }
          cVar3 = pcVar4[1];
          pcVar4 = pcVar4 + 1;
        } while (cVar3 != '\0');
        if (*pcVar4 != '\0') {
          pcVar4 = pcVar4 + 1;
        }
        *flags = '\0';
      }
      flags = pcVar4;
      cVar3 = *pcVar4;
    }
    *ppcVar2 = (char *)0x0;
  }
  return;
}

