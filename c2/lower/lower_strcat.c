void __fastcall lower_strcat(c2_tuple *t,c2_operand **args)

{
  char cVar1;
  c2_fe_symbol *pcVar2;
  c2_tuple *pcVar3;
  c2_init *pcVar4;
  c2_const_operand *src;
  uint uVar5;
  c2_operand *pcVar6;
  c2_operand *str;
  uint32_t lo;
  char *pcVar7;
  c2_operand *local_14;
  c2_operand *local_10;
  c2_operand *local_c;
  c2_operand **local_8;
  c2_const_operand *local_4;
  c2_insert_fn *insert_fn;
  
  str = args[1];
  pcVar6 = str->sym->def->src;
  local_8 = args;
  if ((((1 << (pcVar6->kind & 0x1f) & 0x18U) == 0) ||
      (pcVar2 = pcVar6->sym->fe, pcVar2 == (c2_fe_symbol *)0x0)) || (pcVar2->role != '%')) {
    lo = 0;
    local_14 = emit_repne_scasb_strlen(t,str,&local_10,1,0);
    pcVar3 = emit_string_op_step(0x32,0x1004,&local_10,&local_14,t->prev,2);
    pcVar3 = tuple_new_unary_temp(1,0x1004,local_10,tuple_insert_after,pcVar3);
    pcVar6 = pcVar3->dst;
    pcVar3 = tuple_new_unary_temp(1,0x1004,local_14,tuple_insert_after,pcVar3);
    local_c = pcVar3->dst;
  }
  else {
    lo = (uint32_t)(pcVar2->u44).length;
    if (lo == 0) {
      pcVar4 = data_def_find_by_id(pcVar2->id);
      uVar5 = 0xffffffff;
      pcVar7 = (char *)(pcVar4->next->u08).header.offset;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      (pcVar2->u44).length = (uint16_t)~uVar5;
      lo = ~uVar5 & 0xffff;
    }
    local_c = operand_new_intconst(0x1004,lo,0);
    pcVar6 = local_4;
  }
  emit_repne_scasb_strlen(t,*local_8,&local_10,2,0);
  local_4 = operand_new_intconst(0x1004,0xffffffff,-1);
  emit_string_op_step(0x2d,0x1004,&local_10,&local_4,t->prev,1);
  if (lo == 0) {
    local_14 = operand_new_temp_in_reg(2,0x1004);
    build_fill_pattern(1,0x1004,local_14,&local_c,t->prev);
    str = pcVar6;
  }
  else {
    insert_fn = tuple_insert_before;
    pcVar3 = t;
    src = operand_new_intconst(0x1004,(int)lo >> 2,0);
    pcVar3 = tuple_new_unary_temp(0x15a,0x1004,src,insert_fn,pcVar3);
    local_14 = pcVar3->dst;
    (local_14->u18).reg = g_reg_symbols + 2;
    tuple_append_src(t,local_14);
    local_8[2] = local_14;
    (str->u18).reg = g_reg_symbols + 7;
  }
  emit_string_block_op(lo,local_14,local_c,local_10,str,1,(c2_operand *)0x0,1,0,1,1,t,0);
  return;
}

