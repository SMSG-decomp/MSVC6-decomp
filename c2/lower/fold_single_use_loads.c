void __fastcall fold_single_use_loads(c2_tuple *t)

{
  c2_operand *opnd;
  c2_tuple *pcVar1;
  uint32_t uVar2;
  int iVar3;
  
  if (t->src != (c2_operand *)0x0) {
    uVar2 = can_fold_source_load(t,t->src);
    if (uVar2 != 0) {
      pcVar1 = t->src->sym->def;
      uVar2 = is_simple_load(pcVar1);
      if (uVar2 != 0) {
        iVar3 = range_writes_alias(pcVar1,&t->next,(c2_operand *)0x0);
        if (iVar3 == 0) {
          iVar3 = operand_fits_instruction(t,1,pcVar1->src);
          if (iVar3 != 0) {
            iVar3 = try_substitute_operand(t,t->src,pcVar1->src,tuple_replace_src);
            if (iVar3 != 0) {
              tuple_unlink_free(pcVar1);
            }
          }
        }
      }
    }
    opnd = t->src->next;
    if (opnd != (c2_operand *)0x0) {
      uVar2 = can_fold_source_load(t,opnd);
      if (uVar2 != 0) {
        pcVar1 = t->src->next->sym->def;
        uVar2 = is_simple_load(pcVar1);
        if (uVar2 != 0) {
          iVar3 = range_writes_alias(pcVar1,&t->next,(c2_operand *)0x0);
          if (iVar3 == 0) {
            iVar3 = operand_fits_instruction(t,2,pcVar1->src);
            if (iVar3 != 0) {
              iVar3 = try_substitute_operand(t,t->src->next,pcVar1->src,tuple_replace_src);
              if (iVar3 != 0) {
                tuple_unlink_free(pcVar1);
              }
            }
          }
        }
      }
    }
  }
  return;
}

