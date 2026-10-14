void ns_check_definition_scope(byte *sym,int scope)

{
  byte bVar1;
  char cVar2;
  c1_symbol *pcVar3;
  int iVar4;
  uint scope_name;
  
  if (*(short *)(sym + 6) == 0) {
    bVar1 = *sym & 0x1f;
    if (bVar1 == 4) {
      scope_name = *(uint *)(scope + 8);
      iVar4 = 0x43;
    }
    else {
      if (((bVar1 == 0x10) || (bVar1 == 0x11)) || (cVar2 = 'D', bVar1 == 0x1b)) {
        cVar2 = 'S';
      }
      iVar4 = (int)cVar2;
      scope_name = *(uint *)(scope + 8);
    }
  }
  else {
    pcVar3 = g_scope_vector->entries[*(short *)(sym + 6)];
    if (pcVar3 == (c1_symbol *)scope) {
      return;
    }
    while (pcVar3 = g_scope_vector->entries[(short)pcVar3->scope_index], pcVar3 != (c1_symbol *)0x0)
    {
      if (pcVar3 == (c1_symbol *)scope) {
        return;
      }
    }
    bVar1 = *sym & 0x1f;
    if (bVar1 == 4) {
      cVar2 = 'C';
    }
    else if (((bVar1 == 0x10) || (bVar1 == 0x11)) || (cVar2 = 'D', bVar1 == 0x1b)) {
      cVar2 = 'S';
    }
    scope_name = *(uint *)(scope + 8);
    iVar4 = (int)cVar2;
  }
  diag_error(0x378,iVar4,sym,scope_name);
  sym[3] = sym[3] | 4;
  return;
}

