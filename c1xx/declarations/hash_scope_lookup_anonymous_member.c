void __thiscall
hash_scope_lookup_anonymous_member(c1xx_hash_scope *scope,void *name,c1_symbol **result)

{
  c1_sym_link *pcVar1;
  c1_symbol *pcVar2;
  int iVar3;
  uint uStack_4;
  
  uStack_4 = 0;
  if (scope->mask != 0xffffffff) {
    do {
      for (pcVar1 = scope->buckets[uStack_4]; pcVar1 != (c1_sym_link *)0x0; pcVar1 = pcVar1->next) {
        if (((((pcVar1[-1].position & 0x1f) == 4) && ((((pcVar1->type).type)->code & 0x200) != 0))
            && (pcVar1[2].name != (fe_name *)0x0)) &&
           (pcVar2 = sym_chain_find_name((c1_symbol *)((pcVar1[2].name)->text + -8),name),
           pcVar2 != (c1_symbol *)0x0)) {
          if ((pcVar2 != *result) && (*result != (c1_symbol *)0x0)) {
            iVar3 = asm_operand_description_id();
            diag_error(0x19a,name,iVar3);
          }
          g_symbol_scope_level = scope->kind;
          *result = pcVar2;
        }
      }
      uStack_4 = uStack_4 + 1;
    } while (uStack_4 < scope->mask + 1);
  }
  return;
}

