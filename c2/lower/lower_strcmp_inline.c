void __fastcall lower_strcmp_inline(c2_tuple *t,c2_operand **args)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_fe_symbol *pcVar6;
  c2_tuple *pcVar7;
  c2_const_operand *pcVar8;
  c2_tuple *t_00;
  code *insert_fn_00;
  c2_operand *local_1c;
  c2_operand *local_18;
  c2_tuple *local_14;
  c2_operand *local_10;
  c2_operand *local_c;
  c2_tuple *local_8;
  c2_tuple *local_4;
  c2_insert_fn *insert_fn;
  
  local_14 = t;
  pcVar2 = operand_new_temp_sym(g_ptr_type);
  pcVar7 = (*args)->sym->def;
  local_c = pcVar2;
  pcVar3 = tuple_new(1,g_ptr_type,pcVar2,pcVar7->src,tuple_insert_before,pcVar7);
  lower_tuple(pcVar3);
  if (g_opt_global == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = tuple_get_memeffect_alias(t);
  }
  local_18 = operand_new_mem(0x14c,0x1001,(c2_symbol *)0x0,0,pcVar2,(c2_operand *)0x0,uVar4);
  pcVar2 = operand_new_temp_sym(g_ptr_type);
  pcVar1 = args[1]->sym;
  pcVar3 = pcVar1->def;
  pcVar3 = tuple_new(1,g_ptr_type,pcVar2,pcVar3->src,tuple_insert_before,pcVar3);
  lower_tuple(pcVar3);
  if (g_opt_global == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = tuple_second_memeffect_src_value(t);
  }
  pcVar5 = operand_new_mem(0x14c,0x1001,(c2_symbol *)0x0,0,pcVar2,(c2_operand *)0x0,uVar4);
  tuple_unlink_free(pcVar7);
  tuple_unlink_free(pcVar1->def);
  pcVar7 = local_14->prev;
  pcVar6 = label_symbol_new();
  local_8 = tuple_new_label(pcVar6);
  tuple_insert_after(pcVar7,local_8);
  pcVar6 = label_symbol_new();
  pcVar3 = tuple_new_label(pcVar6);
  pcVar7 = emit_memcmp_step(local_18,pcVar5,0,0x1001,pcVar3,pcVar7->next,&local_1c);
  pcVar7 = pcVar7->next;
  pcVar8 = operand_new_intconst(0x1001,0,0);
  pcVar7 = emit_op_before_with_parts(0x2f,0x1001,local_1c,pcVar8,pcVar7);
  local_10 = pcVar7->dst;
  pcVar6 = label_symbol_new();
  local_4 = tuple_new_label(pcVar6);
  pcVar7 = tuple_new_branch(0xf,'\x01',(c2_node *)local_4,local_10,pcVar7,tuple_insert_after,pcVar7)
  ;
  pcVar7 = emit_memcmp_step(local_18,pcVar5,1,0x1001,pcVar3,pcVar7,&local_1c);
  insert_fn = tuple_insert_after;
  pcVar8 = operand_new_intconst(0x1004,2,0);
  pcVar7 = tuple_new_binary(0x2d,0x1004,local_c,local_c,pcVar8,insert_fn,pcVar7);
  insert_fn_00 = tuple_insert_after;
  pcVar8 = operand_new_intconst(0x1004,2,0);
  pcVar7 = tuple_new_binary(0x2d,0x1004,pcVar2,pcVar2,pcVar8,insert_fn_00,pcVar7);
  pcVar7 = pcVar7->next;
  pcVar8 = operand_new_intconst(0x1001,0,0);
  pcVar7 = emit_op_before_with_parts(0x2f,0x1001,local_1c,pcVar8,pcVar7);
  pcVar7 = tuple_new_branch(0xf,'\x02',(c2_node *)local_8,pcVar7->dst,pcVar7,tuple_insert_after,
                            pcVar7);
  tuple_insert_after(pcVar7,local_4);
  pcVar5 = operand_new_temp_sym(0x1004);
  pcVar7 = build_zero_extend_int64(pcVar5,pcVar7->next,0,0);
  pcVar6 = label_symbol_new();
  t_00 = tuple_new_label(pcVar6);
  pcVar7 = tuple_new_branch(0x10,'\0',(c2_node *)t_00,(c2_operand *)0x0,(c2_tuple *)0x0,
                            tuple_insert_after,pcVar7);
  tuple_insert_after(pcVar7,pcVar3);
  pcVar7 = emit_sbb_mask(pcVar7->next);
  pcVar7 = tuple_new(1,0x1004,pcVar5,pcVar7->dst,tuple_insert_after,pcVar7);
  tuple_insert_after(pcVar7,t_00);
  pcVar2 = local_14->dst;
  pcVar7 = tuple_new(1,0x1004,pcVar2,pcVar5,tuple_insert_after,pcVar7->next);
  if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
     (pcVar1 = pcVar2->sym, pcVar1->def != (c2_tuple *)0x0)) {
    if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
      pcVar1->def = pcVar7;
      return;
    }
    symbol_mark_overlapping_parts(pcVar1,pcVar7);
    return;
  }
  lower_tuple(pcVar7);
  return;
}

