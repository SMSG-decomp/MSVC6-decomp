c2_tuple * __fastcall lower_alloca_intrinsic(c2_tuple *t)

{
  c2_symbol *pcVar1;
  c2_function *pcVar2;
  int iVar3;
  c2_operand *pcVar4;
  c2_const_operand *pcVar5;
  c2_operand *dst;
  c2_tuple *pcVar6;
  code *insert_fn_00;
  c2_tuple *anchor;
  c2_insert_fn *insert_fn;
  
  pcVar2 = g_cur_function;
  g_cur_function->flags = g_cur_function->flags | 0x2000;
  if ((pcVar2->fsym->attrs & 0x1000) != 0) {
    seh_lower_pseudo_op(t);
  }
  pcVar6 = t->src->sym->def;
  pcVar4 = pcVar6->src;
  pcVar6->op = 1;
  if (pcVar4->kind == '\a') {
    pcVar1 = (pcVar4->u18).reg;
    if (((uint)pcVar1 & 3) != 0) {
      (pcVar4->u18).reg = (c2_symbol *)((int)&pcVar1->fe + 3);
      pcVar4->tag = pcVar4->tag + (uint)((c2_symbol *)0xfffffffc < pcVar1);
      (pcVar4->u18).lo = (pcVar4->u18).lo & 0xfffffffc;
      pcVar4->tag = pcVar4->tag;
    }
  }
  else {
    iVar3 = operand_def_is_aligned_imul(pcVar6);
    if (iVar3 == 0) {
      pcVar4 = operand_new_temp(0x1004);
      tuple_replace_dst(pcVar6,pcVar6->dst,pcVar4);
      pcVar1 = pcVar6->dst->sym;
      if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
        pcVar1->def = pcVar6;
      }
      else {
        symbol_mark_overlapping_parts(pcVar1,pcVar6);
      }
      insert_fn = tuple_insert_before;
      pcVar6 = t;
      pcVar5 = operand_new_intconst(0x1004,3,0);
      dst = operand_new_temp(0x1004);
      pcVar6 = tuple_new_binary(0x2d,0x1004,dst,pcVar4,pcVar5,insert_fn,pcVar6);
      pcVar1 = pcVar6->dst->sym;
      if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
        pcVar1->def = pcVar6;
      }
      else {
        symbol_mark_overlapping_parts(pcVar1,pcVar6);
      }
      insert_fn_00 = tuple_insert_before;
      anchor = t;
      pcVar5 = operand_new_intconst(0x1004,0xfffffffc,-1);
      pcVar6 = tuple_new_binary(0x2e,0x1004,t->src,pcVar6->dst,pcVar5,insert_fn_00,anchor);
      pcVar1 = pcVar6->dst->sym;
      if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
        pcVar1->def = pcVar6;
      }
      else {
        symbol_mark_overlapping_parts(pcVar1,pcVar6);
      }
      tie_dest_to_source_temp(pcVar6);
    }
  }
  g_alloca_probe_symbol = fe_symbol_lookup_name("__alloca_probe");
  pcVar4 = operand_for_symbol_ref(g_alloca_probe_symbol);
  pcVar6 = tuple_make_helper_call_2(t,0xe,pcVar4,'\0');
  if (pcVar6->dst != (c2_operand *)0x0) {
    bind_result_to_register(pcVar6,g_reg_symbols + 5);
  }
  return pcVar6;
}

