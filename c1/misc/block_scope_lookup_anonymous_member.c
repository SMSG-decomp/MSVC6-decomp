void __thiscall
block_scope_lookup_anonymous_member(c1_scope_object *block_scope,void *name,int *out)

{
  int *piVar1;
  c1_symbol *pcVar2;
  int iVar3;
  
  for (piVar1 = ((block_scope->entries).list)->first; piVar1 != (int *)0x0;
      piVar1 = (int *)piVar1[1]) {
    if ((((*(byte *)(piVar1 + -2) & 0x1f) == 4) && ((*(ushort *)piVar1[3] & 0x200) != 0)) &&
       (pcVar2 = sym_chain_find_name((c1_symbol *)(*(int *)(piVar1[0xb] + 4) + -8),name),
       pcVar2 != (c1_symbol *)0x0)) {
      if (*out != 0) {
        iVar3 = asm_operand_description_id();
        diag_error(0x19a,name,iVar3);
      }
      g_symbol_scope_level = block_scope->level;
      *out = (int)pcVar2;
    }
  }
  return;
}

