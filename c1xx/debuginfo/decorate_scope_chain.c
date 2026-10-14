char * __cdecl decorate_scope_chain(char *out,byte *sym)

{
  c1_symbol *pcVar1;
  byte bVar2;
  char *pcVar3;
  
  bVar2 = *sym & 0x1f;
  if ((bVar2 == 4) || (bVar2 == 0x19)) {
    out = decorate_name_with_backreference(out,*(int *)(sym + 8),0);
    if (*(short *)(sym + 6) != 0) {
      pcVar1 = g_scope_vector->entries[*(short *)(sym + 6)];
      bVar2 = pcVar1->kind & 0x1f;
      if (((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) {
        pcVar3 = decorate_scope_chain(out,&pcVar1->kind);
        return pcVar3;
      }
      *out = '?';
      pcVar3 = decorate_number(out + 1,(uint)*(ushort *)(*(int *)(sym + 0x24) + 0x38));
      *pcVar3 = '?';
      pcVar3 = decorate_name_body(pcVar3 + 1,pcVar1,(c1_symbol *)0x0);
      return pcVar3;
    }
  }
  else {
    if ((sym[1] & 4) != 0) {
      pcVar3 = decorate_scope_chain(out,&g_scope_vector->entries[*(short *)(sym + 6)]->kind);
      return pcVar3;
    }
    if ((((sym[0x20] & 7) == 3) && (bVar2 == 10)) && (*(short *)(sym + 0x28) != 0)) {
      *out = '?';
      pcVar3 = decorate_number(out + 1,(uint)*(ushort *)(sym + 0x28));
      *pcVar3 = '?';
      pcVar3 = decorate_name_body(pcVar3 + 1,g_current_function,(c1_symbol *)0x0);
      return pcVar3;
    }
    if (*(short *)(sym + 6) != 0) {
      pcVar1 = g_scope_vector->entries[*(short *)(sym + 6)];
      bVar2 = pcVar1->kind & 0x1f;
      if (bVar2 == 0x19) {
        pcVar3 = decorate_scope_chain(out,&pcVar1->kind);
        return pcVar3;
      }
      if ((bVar2 == 7) || (bVar2 == 8)) {
        pcVar3 = decorate_name_body(out,pcVar1,(c1_symbol *)0x0);
        return pcVar3;
      }
    }
  }
  return out;
}

