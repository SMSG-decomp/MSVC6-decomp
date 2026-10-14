char * __cdecl decorate_rtti_locator_name(c1_symbol *vftable_sym)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = g_decorated_name + 5;
  g_decorate_output_base = g_decorated_name;
  pcVar3 = vftable_sym->name->text + 4;
  builtin_strncpy(g_decorated_name,"??_R4",5);
  cVar2 = *pcVar3;
  while (cVar2 != '\0') {
    *pcVar4 = cVar2;
    pcVar1 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
    pcVar3 = pcVar3 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar4 = '\0';
  return g_decorated_name;
}

