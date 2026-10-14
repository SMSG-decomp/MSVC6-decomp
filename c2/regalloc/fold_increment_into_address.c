void __fastcall fold_increment_into_address(c2_tuple *t,c2_symbol *reg)

{
  c2_tuple *t_00;
  c2_operand *sub;
  c2_operand *pcVar1;
  uint32_t uVar2;
  c2_operand *local_4;
  
  t_00 = t->prev;
  if (((((t_00->flags & 1) != 0) && (pcVar1 = t_00->dst, pcVar1 != (c2_operand *)0x0)) &&
      (pcVar1->kind == '\x01')) && ((pcVar1->u18).reg == reg)) {
    uVar2 = t_00->op;
    if (uVar2 == 0x1e) {
      uVar2 = 0xffffffff;
    }
    else if (uVar2 == 0x21) {
      uVar2 = 1;
    }
    else {
      if (uVar2 != 0x2d) {
        return;
      }
      pcVar1 = t_00->src->next;
      if (pcVar1->kind != '\a') {
        return;
      }
      uVar2 = (pcVar1->u18).lo;
    }
    pcVar1 = find_dst_clobbering_reg(t_00,g_reg_symbols + 0x42);
    if (((pcVar1 == (c2_operand *)0x0) || ((1 << (pcVar1->kind & 0x1f) & 6U) == 0)) ||
       (pcVar1->sym->cls != '\x03')) {
      sub = t->src;
      for (pcVar1 = sub; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if (((pcVar1->kind == '\x01') && ((pcVar1->u18).reg == reg)) &&
           ((pcVar1->flags & 0x20) == 0)) {
          return;
        }
      }
      for (; sub != (c2_operand *)0x0; sub = sub->next) {
        if ((sub->kind == '\x01') && ((sub->u18).reg == reg)) {
          pcVar1 = find_mem_operand_using(t,sub,&local_4);
          if ((pcVar1->index == sub) && ((pcVar1->flags & 0xf) != 0)) {
            pcVar1->disp = pcVar1->disp + ((1 << (pcVar1->flags & 0xf)) + -1) * uVar2;
          }
          pcVar1->disp = pcVar1->disp + uVar2;
        }
      }
      tuple_unlink_free(t_00);
    }
  }
  return;
}

