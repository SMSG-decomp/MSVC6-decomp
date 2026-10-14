char * __cdecl decorate_vftable_for_list(char *out,c1_symbol *sym)

{
  c1_u32 rec;
  ushort *puVar1;
  char *pcVar2;
  short sVar3;
  
  rec = (sym->tail).data.value_lo;
  if (rec != 0) {
    puVar1 = vftable_base_path_list(rec);
    for (sVar3 = 0; (puVar1 != (ushort *)0x0 && ((int)sVar3 < (int)(uint)*puVar1));
        sVar3 = sVar3 + 1) {
      pcVar2 = decorate_scope_chain(out,*(byte **)(*(int *)(puVar1 + 4) + sVar3 * 4));
      *pcVar2 = '@';
      out = pcVar2 + 1;
    }
  }
  return out;
}

