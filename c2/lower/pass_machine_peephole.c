void __fastcall pass_machine_peephole(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  int iVar7;
  uint uVar8;
  c2_tuple *pcVar9;
  c2_tuple *t;
  c2_tuple *local_c;
  
  pcVar2 = fn->cfg->last->end;
  t = fn->cfg->first->head->next;
  while (t != pcVar2) {
    uVar1 = t->line;
    local_c = t->next;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    if ((t->flags & 1) != 0) {
      fold_single_use_loads(t);
      switch(t->op) {
      case 0x2b:
        pcVar6 = t->src;
        if (((((pcVar6->kind == '\x01') && (pcVar6->sym->cls == '\x03')) &&
             ((pcVar9 = pcVar6->sym->def, pcVar9 != (c2_tuple *)0x0 && (pcVar6->next->kind == '\a'))
             )) && ((pcVar9->op == 0x2e ||
                    (((pcVar9->op == 1 && (pcVar9->src->kind == '\x01')) &&
                     ((pcVar3 = pcVar9->src->sym, pcVar3->cls == '\x03' &&
                      ((pcVar4 = pcVar3->def, pcVar4 != (c2_tuple *)0x0 &&
                       (t = pcVar9, pcVar9 = pcVar4, pcVar4->op == 0x2e)))))))))) &&
           (pcVar9 != (c2_tuple *)0x0)) {
          pcVar5 = pcVar9->src->next;
          if ((pcVar5->kind == '\a') &&
             (uVar8 = ~(pcVar5->u18).lo,
             ((1 << (*(byte *)&pcVar6->next->u18 & 0x1f)) - 1U & uVar8) == uVar8)) {
            tuple_replace_src(t,t->src,pcVar9->src);
            tuple_unlink_free(pcVar9);
          }
        }
        break;
      case 0x2d:
      case 0x32:
        if (((t->src->next->kind == '\a') &&
            ((pcVar6 = find_dst_clobbering_reg(t,g_reg_symbols + 0x42),
             (1 << (pcVar6->kind & 0x1f) & 6U) == 0 || (pcVar6->sym->def == (c2_tuple *)0x0)))) &&
           ((g_opt_basic == 0 ||
            (((((t->type & 0xf000) != 0x2000 || (t->dst->kind != '\x01')) ||
              (pcVar9 = find_next_use_of_symbol_2(t,t->dst->sym), pcVar9 == (c2_tuple *)0x0)) ||
             (pcVar9->op != 0x178)))))) {
          pcVar6 = t->src->next;
          if ((pcVar6->u18).reg == (c2_symbol *)0x1) {
            t->op = (-(uint)(t->op != 0x2d) & 0xfffffffd) + 0x21;
            tuple_remove_src(t,pcVar6);
            set_flags_effects(t);
          }
          else {
            iVar7 = const_compare(pcVar6,0xffffffff,-1);
            if (iVar7 == 0) {
              pcVar6 = t->src->next;
              t->op = (-(uint)(t->op != 0x2d) & 3) + 0x1e;
              tuple_remove_src(t,pcVar6);
              set_flags_effects(t);
            }
          }
        }
        break;
      case 0x2f:
        local_c = eliminate_compare_with_zero(t);
      }
    }
    t = local_c;
  }
  return;
}

