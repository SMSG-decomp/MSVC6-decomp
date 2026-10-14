char * __cdecl decorate_name_with_backreference(char *out,int name,int first_char_flag)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  
  iVar3 = 0;
  if (0 < g_decorate_name_backref_count) {
    piVar5 = &g_decorate_name_backrefs;
    do {
      if (*piVar5 == name) {
        *out = (char)iVar3 + '0';
        return out + 1;
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < g_decorate_name_backref_count);
  }
  if (g_decorate_name_backref_count < 10) {
    (&g_decorate_name_backrefs)[g_decorate_name_backref_count] = name;
    g_decorate_name_backref_count = g_decorate_name_backref_count + 1;
  }
  pcVar4 = *(char **)(name + 4);
  pcVar2 = out;
  if (first_char_flag != 0) {
    cVar1 = *pcVar4;
    *out = cVar1;
    pcVar4 = pcVar4 + 1;
    pcVar2 = out + 1;
    if (cVar1 == '.') {
      *out = '@';
    }
  }
  cVar1 = *pcVar4;
  *pcVar2 = cVar1;
  while (cVar1 != '\0') {
    cVar1 = pcVar4[1];
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
    *pcVar2 = cVar1;
  }
  *pcVar2 = '@';
  pcVar2 = pcVar2 + 1;
  if (0x7ff < (int)pcVar2 - (int)g_decorate_output_base) {
    pcVar2 = g_decorate_output_base + 0x800;
  }
  return pcVar2;
}

