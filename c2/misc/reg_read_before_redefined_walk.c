int __fastcall reg_read_before_redefined_walk(c2_tuple *t,c2_symbol *reg)

{
  c2_tuple *t_00;
  c2_operand *pcVar1;
  uint32_t uVar2;
  int iVar3;
  
  do {
    if (t->kind == '\x18') {
      return 0;
    }
    if ((t->flags & 1) != 0) {
      pcVar1 = find_src_overlapping_reg(t,reg);
      if (pcVar1 != (c2_operand *)0x0) {
        return 1;
      }
      pcVar1 = find_dst_clobbering_reg(t,reg);
      if (pcVar1 != (c2_operand *)0x0) {
        return 0;
      }
      if (t->kind == '\x0f') {
        return 0;
      }
      if (t->kind == '\x11') {
        if (t->src->kind != '\x04') {
          return 1;
        }
        t_00 = *(c2_tuple **)&(t->src->sym->u30).globopt.marks;
        if (t_00 == (c2_tuple *)0x0) {
          return 1;
        }
        if (((t->u20).cond_cells == (c2_cond_cell *)0x0) && (t->op != 0x18b)) {
          uVar2 = reg_read_before_redefined_loop(t_00,reg);
          return uVar2;
        }
        iVar3 = reg_read_before_redefined_walk(t_00,reg);
        if (iVar3 != 0) {
          iVar3 = reg_read_before_redefined_true();
          return iVar3;
        }
      }
    }
    if (t->kind == '\x1a') {
      if ((t->u20).cond_cells == (c2_cond_cell *)g_tuple_visit_stamp) {
        return 0;
      }
      (t->u20).visit_stamp = g_tuple_visit_stamp;
    }
    t = t->next;
  } while( true );
}

