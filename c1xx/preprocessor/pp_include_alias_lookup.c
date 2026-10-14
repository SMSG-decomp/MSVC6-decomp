char * __thiscall pp_include_alias_lookup(void *list,char *name,char *angle)

{
  int iVar1;
  uint *alias;
  
  alias = *(uint **)list;
  while( true ) {
    if (alias == (uint *)0x0) {
      return (char *)0x0;
    }
    iVar1 = _stricmp((char *)alias[1],name);
    if ((iVar1 == 0) && ((char)alias[3] == *angle)) break;
    alias = (uint *)*alias;
  }
  *angle = *(char *)((int)alias + 0xd);
  return (char *)alias[2];
}

