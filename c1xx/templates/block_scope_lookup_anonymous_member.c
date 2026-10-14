void __thiscall block_scope_lookup_anonymous_member(c1xx_block_scope *scope,void *name,int *found)

{
  c1_sym_link *pcVar1;
  c1_symbol *pcVar2;
  int iVar3;
  
  for (pcVar1 = scope->symbols->head; pcVar1 != (c1_sym_link *)0x0; pcVar1 = pcVar1->next) {
    if ((((pcVar1[-1].position & 0x1f) == 4) && ((((pcVar1->type).type)->code & 0x200) != 0)) &&
       (pcVar2 = sym_chain_find_name((c1_symbol *)((pcVar1[2].name)->text + -8),name),
       pcVar2 != (c1_symbol *)0x0)) {
      if (*found != 0) {
        iVar3 = asm_operand_description_id();
        diag_error(0x19a,name,iVar3);
      }
      g_symbol_scope_level = scope->kind;
      *found = (int)pcVar2;
    }
  }
  return;
}

