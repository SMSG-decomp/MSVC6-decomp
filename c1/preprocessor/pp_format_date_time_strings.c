char * __cdecl pp_format_date_time_strings(uint time)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  time = time & 0x7fffffff;
  pcVar1 = ctime((time_t *)&time);
  if (pcVar1 != (char *)0x0) {
    pcVar3 = pcVar1;
    pcVar4 = g_pp_ctime_text;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar4 = pcVar4 + 4;
    }
    *pcVar4 = *pcVar3;
    if (g_pp_ctime_text[8] == '0') {
      g_pp_ctime_text[8] = ' ';
    }
    g_pp_ctime_text._11_4_ = *(undefined4 *)(pcVar1 + 0x14);
    g_pp_ctime_text._16_4_ = *(undefined4 *)(pcVar1 + 0xb);
    g_pp_ctime_text._20_4_ = *(undefined4 *)(pcVar1 + 0xf);
  }
  return g_pp_ctime_text;
}

