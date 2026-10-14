void __fastcall flags_bind_compare_result(c2_tuple *use,c2_operand *op)

{
  byte bVar1;
  c2_tuple *t;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *op_00;
  c2_operand *pcVar4;
  uint32_t uVar5;
  
  (op->u18).reg = g_reg_symbols + 0x42;
  t = op->sym->def;
  pcVar4 = find_dst_symbol_ref(t,op->sym);
  (pcVar4->u18).reg = g_reg_symbols + 0x42;
  pcVar2 = use->prev;
  bVar1 = pcVar2->flags;
  while ((bVar1 & 1) == 0) {
    pcVar2 = pcVar2->prev;
    bVar1 = pcVar2->flags;
  }
  if (pcVar2 != t) {
    pcVar4 = t->src;
    while (op_00 = pcVar4, op_00 != (c2_operand *)0x0) {
      pcVar4 = op_00->next;
      if ((op_00->op != 0x146) &&
         ((((op_00->kind != '\x01' || (op_00->sym->cls != '\x03')) ||
           (op_00->sym->def == (c2_tuple *)0x0)) ||
          (uVar5 = temp_operand_piece_mismatch(op_00), uVar5 != 0)))) {
        pcVar4 = emit_load_into_register(1,t,op_00,g_reg_symbols);
        pcVar4 = tuple_replace_src(t,op_00,pcVar4);
        pcVar4 = pcVar4->next;
      }
    }
    pcVar2 = t->prev;
    pcVar3 = t->next;
    t->next = (c2_tuple *)0x0;
    pcVar2->next = pcVar3;
    pcVar3->prev = pcVar2;
    tuple_insert_before(use,t);
  }
  return;
}

