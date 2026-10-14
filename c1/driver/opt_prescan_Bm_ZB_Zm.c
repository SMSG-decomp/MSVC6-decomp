int __cdecl opt_prescan_Bm_ZB_Zm(char *word,int pending)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  pcVar2 = word;
  do {
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
    switch(pending) {
    case 0:
      iVar1 = 3;
      bVar4 = true;
      pcVar2 = word;
      pcVar3 = "-Bm";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        word = word + 3;
        pending = 1;
      }
      else {
        iVar1 = 3;
        bVar4 = true;
        pcVar2 = word;
        pcVar3 = "-ZB";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar4 = *pcVar2 == *pcVar3;
          pcVar2 = pcVar2 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar4);
        if (bVar4) {
          word = word + 3;
          pending = 2;
        }
        else {
          iVar1 = 3;
          bVar4 = true;
          pcVar2 = word;
          pcVar3 = "-Zm";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar4 = *pcVar2 == *pcVar3;
            pcVar2 = pcVar2 + 1;
            pcVar3 = pcVar3 + 1;
          } while (bVar4);
          if (!bVar4) {
            return 0;
          }
          word = word + 3;
          pending = 3;
        }
      }
      break;
    case 1:
      g_opt_Bm = atoi(word);
      return 0;
    case 2:
      g_integral_max_bytes = atoi(word);
      return 0;
    case 3:
      g_zm_percent = atoi(word);
      if (g_zm_percent != 0) {
        return 0;
      }
      g_zm_percent = 100;
      return 0;
    }
    pcVar2 = (char *)pending;
    if (*word == '\0') {
      return (int)(char *)pending;
    }
  } while( true );
}

