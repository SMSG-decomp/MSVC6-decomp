uint32_t __fastcall
has_intervening_base_definition(c2_symbol *base_sym,c2_tuple *def,c2_tuple *end,c2_live_range *lr)

{
  c2_tuple *pcVar1;
  c2_symbol *sym;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  uint32_t local_8;
  
  local_8 = 1;
  if (def != end) {
    sym = base_sym->storage;
    for (pcVar1 = end->prev; pcVar1 != def; pcVar1 = pcVar1->prev) {
      if ((pcVar1->flags & 1) == 0) {
        if ((pcVar1->kind == '\x19') && ((pcVar1->u14).block != (c2_block *)0x0)) {
          local_8 = bitset_test(((pcVar1->u14).block)->prev->live_out,lr->id);
        }
      }
      else if (local_8 == 0) {
        for (pcVar3 = pcVar1->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if ((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == (c2_symbol *)lr)) {
            local_8 = 1;
          }
        }
      }
      else {
        for (pcVar3 = pcVar1->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          switch(pcVar3->kind) {
          case '\x01':
            if ((pcVar3->u18).reg != (c2_symbol *)lr) goto switchD_10722116_caseD_2;
            local_8 = 0;
            break;
          case '\x02':
switchD_10722116_caseD_2:
            pcVar2 = pcVar3->sym;
            if (sym == pcVar2->storage) {
              if (base_sym == pcVar2) {
                return 1;
              }
              if ((base_sym->offset < pcVar2->size + pcVar2->offset) &&
                 (pcVar2->offset < base_sym->size + base_sym->offset)) {
                return 1;
              }
            }
            break;
          case '\x06':
            iVar4 = symbol_in_alias_class(sym,pcVar3->tag);
            goto joined_r0x10722161;
          case '\v':
            iVar4 = symbol_in_alias_class(sym,(uint32_t)pcVar3->sym);
joined_r0x10722161:
            if (iVar4 != 0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

