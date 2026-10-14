void __fastcall x87_spill_one_entry(c2_tuple *anchor,int slot)

{
  ushort type;
  c2_tuple *t;
  c2_operand *pcVar1;
  c2_symbol **stack_entry;
  c2_operand *src1;
  c2_fe_symbol *label_sym;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_symbol *spilled_sym;
  int iVar4;
  c2_insert_fn *insert_fn;
  
  spilled_sym = g_fp_lower_stack_syms[slot];
  stack_entry = g_fp_lower_stack_syms + slot;
  *stack_entry = (c2_symbol *)0x0;
  if (slot < g_fp_lower_depth) {
    iVar4 = g_fp_lower_depth - slot;
    do {
      *stack_entry = stack_entry[1];
      stack_entry = stack_entry + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  t = anchor->next;
  g_fp_lower_depth = g_fp_lower_depth + -1;
  src1 = (c2_operand *)anchor;
  while ((t != (c2_tuple *)0x0 &&
         (((t->flags & 1) == 0 ||
          (src1 = find_src_symbol_ref(t,spilled_sym), src1 == (c2_operand *)0x0))))) {
    t = t->next;
  }
  if ((((g_opt_vb_float_checks != 0) && (pcVar3 = spilled_sym->def, pcVar3->kind != '\x0e')) &&
      (pcVar3 != anchor)) && (pcVar3->op != 0x178)) {
    if (pcVar3->op == 0x88) {
      pcVar3 = pcVar3->next;
    }
    if (g_vb_fp_error_label == (c2_tuple *)0x0) {
      label_sym = label_symbol_new();
      g_vb_fp_error_label = tuple_new_label(label_sym);
    }
    insert_fn = tuple_insert_after;
    pcVar2 = operand_new_codeaddr(0x154,g_vb_fp_error_label->src);
    pcVar3 = tuple_new_binary_temp(0x178,src1->type,src1,pcVar2,insert_fn,pcVar3);
    pcVar2 = operand_new_reg(0x149,0x1004,g_reg_symbols + 1,g_reg_symbols + 1);
    tuple_append_dst(pcVar3,pcVar2);
    pcVar2 = operand_new_reg(0x149,0x8000,g_reg_symbols + 0x42,g_reg_symbols + 0x42);
    tuple_append_dst(pcVar3,pcVar2);
    pcVar2 = pcVar3->dst;
    (pcVar3->src->u18).reg = g_reg_symbols + 0x1f;
    src1 = tuple_replace_src(t,src1,pcVar2);
    (pcVar2->u18).reg = g_reg_symbols + 0x1f;
    spilled_sym = src1->sym;
  }
  type = src1->type;
  pcVar2 = operand_new_temp_sym(type);
  pcVar3 = spilled_sym->def;
  if (pcVar3->op == 0x88) {
    pcVar3 = pcVar3->next;
  }
  pcVar3 = tuple_new(99,type,pcVar2,src1,tuple_insert_after,pcVar3);
  pcVar1 = pcVar3->src;
  (pcVar1->u18).reg = g_reg_symbols + 0x1f;
  if (type != pcVar1->type) {
    pcVar1->type = type;
    spilled_sym = symbol_get_part(pcVar1->sym,type,type & 0xfff,0);
    pcVar1->sym = spilled_sym;
  }
  tuple_replace_src(t,src1,pcVar2);
  return;
}

