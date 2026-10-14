void __fastcall vb_insert_float_error_checks(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *t;
  uint32_t uVar2;
  uint32_t uVar3;
  c2_tuple *pcVar4;
  c2_fe_symbol *label_sym;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_operand *src1;
  c2_operand *local_4;
  c2_insert_fn *insert_fn;
  
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if ((((t->flags & 1) != 0) && (t->kind != '\x0e')) && (t->kind != '\x12')) {
      for (src1 = t->src; src1 != (c2_operand *)0x0; src1 = src1->next) {
        if (((((((src1->type & 0xf000) == 0x4000) && ((1 << (src1->kind & 0x1f) & 6U) != 0)) &&
              (pcVar6 = src1->sym->def, pcVar6 != (c2_tuple *)0x0)) &&
             (((uVar2 = t->op, uVar2 == 0x15a || (uVar2 == 0x15f)) ||
              ((pcVar5 = t->dst, pcVar5 == (c2_operand *)0x0 ||
               ((((pcVar5->type & 0xf000) != 0x4000 || ((1 << (pcVar5->kind & 0x1f) & 6U) == 0)) ||
                (pcVar5->sym->def == (c2_tuple *)0x0)))))))) &&
            ((uVar3 = pcVar6->op, uVar3 != 0x15b && (uVar3 != 0x15f)))) &&
           ((uVar3 != 0x184 &&
            ((uVar2 != 0x15a || (pcVar4 = find_next_use_of_dst(t,&local_4), pcVar4->kind != '\x12'))
            )))) {
          if (g_vb_fp_error_label == (c2_tuple *)0x0) {
            label_sym = label_symbol_new();
            g_vb_fp_error_label = tuple_new_label(label_sym);
          }
          uVar1 = t->line;
          if (uVar1 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar1;
            g_cur_line = uVar1;
          }
          insert_fn = tuple_insert_after;
          pcVar5 = operand_new_codeaddr(0x154,g_vb_fp_error_label->src);
          pcVar6 = tuple_new_binary_temp(0x178,src1->type,src1,pcVar5,insert_fn,pcVar6);
          src1 = tuple_replace_src(t,src1,pcVar6->dst);
        }
      }
    }
  }
  return;
}

