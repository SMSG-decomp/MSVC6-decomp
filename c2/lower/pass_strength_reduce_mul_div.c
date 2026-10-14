void __fastcall pass_strength_reduce_mul_div(c2_function *fn)

{
  uint8_t uVar1;
  uint8_t uVar2;
  ushort uVar3;
  c2_tuple *pcVar4;
  c2_symbol *pcVar5;
  c2_tuple *t;
  c2_tuple *pcVar6;
  
  init_mul_decomposition_cache();
  pcVar4 = fn->cfg->first->head;
joined_r0x10719ad4:
  do {
    do {
      while( true ) {
        do {
          t = pcVar4;
          if (t == (c2_tuple *)0x0) {
            return;
          }
          uVar3 = t->line;
          if (uVar3 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar3;
            g_cur_line = uVar3;
          }
          pcVar4 = t->next;
        } while ((t->flags & 1) == 0);
        if (t->op == 0x16f) break;
        if (((((t->op == 0x175) && (g_opt_favor_speed != 0)) &&
             ((1 << (byte)(t->type >> 0xc) & 0xeU) != 0)) &&
            (((t->type & 0xfff) != 8 && (t->src->next->kind == '\a')))) && (t->src->kind != '\a')) {
          expand_div_by_constant(t);
        }
      }
    } while (((1 << (byte)(t->type >> 0xc) & 0xeU) == 0) ||
            (t->type == 0x1008
                    ));
    uVar1 = t->src->kind;
    uVar2 = t->src->next->kind;
    if (uVar2 != '\a') goto LAB_10719bc2;
    if (uVar1 == '\a') goto sr_mul_swap_constant_second;
  } while (((g_opt_basic != 0) && ((1 << (t->dst->kind & 0x1f) & 6U) != 0)) &&
          ((pcVar5 = t->dst->sym, pcVar5->cls == '\x03' &&
           ((pcVar6 = find_next_use_of_symbol_2(t,pcVar5), pcVar6 != (c2_tuple *)0x0 &&
            (pcVar6->op == 0x178))))));
  goto LAB_10719b29;
LAB_10719bc2:
  if (uVar1 == '\a') {
sr_mul_swap_constant_second:
    if ((uVar2 != '\a') &&
       ((((g_opt_basic == 0 || ((1 << (t->dst->kind & 0x1f) & 6U) == 0)) ||
         (pcVar5 = t->dst->sym, pcVar5->cls != '\x03')) ||
        ((pcVar6 = find_next_use_of_symbol_2(t,pcVar5), pcVar6 == (c2_tuple *)0x0 ||
         (pcVar6->op != 0x178)))))) {
      tuple_swap_first_srcs(t);
LAB_10719b29:
      expand_mul_by_constant(t);
    }
  }
  goto joined_r0x10719ad4;
}

