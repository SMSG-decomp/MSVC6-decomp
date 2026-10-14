char * __thiscall pp_include_alias_lookup(c1_include_alias **list,char *name,char *angle)

{
  c1_include_alias *pcVar1;
  int iVar2;
  
  pcVar1 = *list;
  while( true ) {
    if (pcVar1 == (c1_include_alias *)0x0) {
      return (char *)0x0;
    }
    iVar2 = _stricmp(pcVar1->from,name);
    if ((iVar2 == 0) && (pcVar1->from_angle == *angle)) break;
    pcVar1 = pcVar1->next;
  }
  *angle = pcVar1->to_angle;
  return pcVar1->to;
}

