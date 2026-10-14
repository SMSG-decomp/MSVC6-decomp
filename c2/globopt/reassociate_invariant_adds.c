void __fastcall reassociate_invariant_adds(c2_function *fn)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  c2_operand *op;
  c2_tuple *pos;
  c2_tuple *t;
  c2_tuple *t_00;
  int iVar6;
  c2_operand *local_4;
  
  if (fn->loops != (c2_loop *)0x0) {
    pcVar2 = fn->cfg->last->end;
    pcVar3 = fn->cfg->first->head->next;
joined_r0x10748e1e:
    t = pcVar3;
    if (t != pcVar2) {
      pcVar3 = t->next;
      if ((((t->op == 0x16d) && (t->flags13 != '\x11')) && ((1 << (t->dst->kind & 0x1f) & 6U) != 0))
         && ((t->dst->sym->def != (c2_tuple *)0x0 &&
             (t_00 = find_next_use_of_dst(t,&local_4), t_00->op == 0x16d)))) {
        iVar6 = operand_compare(t->dst,t_00->src);
        if (iVar6 != 0) {
          tuple_swap_first_srcs(t_00);
        }
        iVar6 = operand_compare(t->dst,t_00->src);
        if (iVar6 == 0) {
          pcVar4 = t->src;
          pcVar5 = pcVar4->next;
          op = t_00->src->next;
          if ((op->flags11 & 0x80) != 0) {
            if ((char)pcVar4->flags11 < '\0') {
              if ((char)pcVar5->flags11 < '\0') goto joined_r0x10748e1e;
              uVar1 = pcVar5->kind;
              pcVar4 = pcVar5;
            }
            else {
              if (-1 < (char)pcVar5->flags11) goto joined_r0x10748e1e;
              uVar1 = pcVar4->kind;
            }
            if (uVar1 == '\x02') {
              tuple_detach_src((c2_node *)t,pcVar4);
              tuple_detach_src((c2_node *)t_00,op);
              tuple_append_src(t,op);
              tuple_append_src(t_00,pcVar4);
              t->dst->flags11 = t->dst->flags11 | 0x80;
              t_00->src->flags11 = t_00->src->flags11 | 0x80;
              pcVar3 = t->next;
              pos = pcVar3;
              while ((pos != t_00 &&
                     ((pcVar4 = pos->dst, pcVar4 == (c2_operand *)0x0 ||
                      (((1 << (pcVar4->kind & 0x1f) & 6U) != 0 &&
                       (pcVar4->sym->def != (c2_tuple *)0x0))))))) {
                pos = pos->next;
              }
              tuple_move_before(pos,t);
            }
          }
        }
      }
      goto joined_r0x10748e1e;
    }
  }
  return;
}

