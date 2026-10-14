char * __cdecl decorate_name(c1_symbol *sym,ushort scope_number)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  
  g_decorated_name_start = g_decorated_name;
  pcVar4 = sym->name->text;
  g_decorated_name[0] = '?';
  pcVar2 = g_decorated_name;
  cVar3 = *pcVar4;
  while (pcVar2 = pcVar2 + 1, cVar3 != '\0') {
    *pcVar2 = cVar3;
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
    cVar3 = *pcVar1;
  }
  *pcVar2 = '@';
  pcVar2[1] = '?';
  pcVar2 = decorate_number(pcVar2 + 2,(uint)scope_number);
  *pcVar2 = '?';
  pcVar2[1] = '?';
  pcVar4 = pcVar2 + 2;
  if (sym->name == g_current_function->name) {
    *pcVar4 = '0';
    pcVar4 = pcVar2 + 3;
  }
  else {
    pcVar2 = g_current_function->name->text;
    cVar3 = *pcVar2;
    while (cVar3 != '\0') {
      *pcVar4 = cVar3;
      pcVar1 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
      pcVar2 = pcVar2 + 1;
      cVar3 = *pcVar1;
    }
  }
  cVar3 = '@';
  pcVar2 = "@@9@9";
  do {
    *pcVar4 = cVar3;
    cVar3 = pcVar2[1];
    pcVar4 = pcVar4 + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar3 != '\0');
  *pcVar4 = '\0';
  return g_decorated_name;
}

