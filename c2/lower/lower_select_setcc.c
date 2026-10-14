c2_tuple * __fastcall lower_select_setcc(c2_tuple *t,int emit,uint32_t *cost)

{
  byte bVar1;
  uint16_t type;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  c2_operand_u18 cVar4;
  long lVar5;
  int iVar6;
  c2_const_operand *pcVar7;
  c2_operand *pcVar8;
  c2_tuple *pcVar9;
  c2_operand *pcVar10;
  c2_operand *pcVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint64_t uVar15;
  c2_operand *pcVar16;
  code *pcVar17;
  uint local_28;
  uint local_24;
  uint local_20;
  uint32_t local_1c;
  int local_18;
  uint local_14;
  c2_tuple *local_10;
  c2_operand *local_c;
  c2_tuple *local_8;
  int local_4;
  c2_insert_fn *insert_fn;
  
  *cost = 500;
  pcVar10 = t->dst;
  local_20 = 0;
  local_8 = (c2_tuple *)0x0;
  pcVar11 = pcVar10;
  local_18 = emit;
  local_10 = t;
  if ((((1 << (pcVar10->kind & 0x1f) & 6U) == 0) || (pcVar10->sym->def == (c2_tuple *)0x0)) &&
     (emit != 0)) {
    type = pcVar10->type;
    pcVar11 = operand_new_temp(type);
    tuple_new(1,type,pcVar10,pcVar11,tuple_insert_after,t);
    tuple_replace_dst(t,pcVar10,pcVar11);
    pcVar3 = pcVar11->sym;
    if (pcVar3->storage->part_next == (c2_symbol *)0x0) {
      pcVar3->def = t;
    }
    else {
      symbol_mark_overlapping_parts(pcVar3,t);
    }
  }
  pcVar10 = t->src;
  pcVar8 = pcVar10->next;
  pcVar16 = pcVar8->next;
  local_c = pcVar10;
  iVar6 = select_operands_allow_setcc(pcVar8,pcVar16,(int *)&local_20);
  if ((iVar6 == 0) && (local_18 == 0)) {
    return (c2_tuple *)0x0;
  }
  local_24 = (uint)(local_10->u20).cc;
  if (((local_18 != 0) && (pcVar10->sym->cls == '\x03')) &&
     ((pcVar9 = pcVar10->sym->def, pcVar9 != (c2_tuple *)0x0 && ((pcVar9->type & 0xf000) == 0x2000))
     )) {
    local_24 = (uint)g_unsigned_cc[(local_10->u20).cc];
  }
  local_14 = pcVar11->type & 0xfff;
  if (local_14 == 2) {
    local_14 = 4;
  }
  if ((pcVar8->kind == '\a') && (pcVar16->kind == '\a')) {
    uVar15 = const_normalize(pcVar8->type,(pcVar8->u18).lo,pcVar8->tag);
    iVar6 = (int)uVar15;
    uVar15 = const_normalize(pcVar16->type,(pcVar16->u18).lo,pcVar16->tag);
    local_1c = (uint32_t)uVar15;
    local_4 = iVar6;
    if ((iVar6 < -1) || (((2 < iVar6 || ((int)local_1c < -1)) || (2 < (int)local_1c))))
    goto LAB_1074a21a;
    iVar6 = local_1c + iVar6 * 4;
    local_28 = (uint)(&g_select_setcc_form_by_consts)[iVar6 * 2];
    if (local_28 == 0) goto LAB_1074a21a;
    local_20 = (uint)(&g_select_setcc_swap_by_consts)[iVar6 * 2];
    goto LAB_1074a104;
  }
LAB_1074a21a:
  if ((pcVar8->kind == '\a') && (pcVar16->kind == '\a')) {
    uVar12 = (int)(local_4 - local_1c) >> 0x1f;
    if ((local_4 - local_1c ^ uVar12) - uVar12 != 1) {
      if (local_1c == 0) goto LAB_1074a2b0;
      local_28 = 0xc;
      local_24 = (uint)g_cond_inverse[local_24];
      goto LAB_1074a104;
    }
    local_28 = 9;
    if ((((int)local_1c <= local_4) || ((local_1c == 0x7fffffff && (local_4 == -0x80000000)))) &&
       ((local_4 != 0x7fffffff || (local_1c != 0x80000000)))) goto LAB_1074a104;
    local_20 = 1;
LAB_1074a280:
    local_24 = (uint)g_cond_inverse[local_24];
    pcVar10 = pcVar8;
    pcVar8 = pcVar16;
  }
  else {
LAB_1074a2b0:
    local_28 = 10;
LAB_1074a104:
    pcVar10 = pcVar16;
    if (local_20 != 0) goto LAB_1074a280;
  }
  uVar15 = const_normalize(pcVar8->type,(pcVar8->u18).lo,pcVar8->tag);
  local_4 = (int)uVar15;
  if (pcVar10->kind == '\a') {
    uVar15 = const_normalize(pcVar10->type,(pcVar10->u18).lo,pcVar10->tag);
    local_1c = (uint32_t)uVar15;
  }
  iVar13 = g_opt_favor_speed;
  lVar5 = g_opt_cpu_target;
  iVar6 = g_opt_cpu_target + -4;
  if (g_opt_favor_speed == 0) {
    iVar6 = 2;
  }
  bVar1 = g_select_form_cost_table[local_28][iVar6];
  *cost = (uint)bVar1;
  iVar6 = g_opt_favor_speed;
  if (local_14 != 1) {
    iVar14 = lVar5 + -4;
    if (iVar13 == 0) {
      iVar14 = 2;
    }
    *cost = (uint)g_select_form_cost_table[3][iVar14] + (uint)bVar1;
    iVar13 = iVar6;
  }
  if (((iVar13 == 0) && (local_28 == 10)) && ((pcVar10->type & 0xfff) != 1)) {
    *cost = *cost + 4;
  }
  if (local_18 == 0) {
    return (c2_tuple *)0x0;
  }
  if (local_14 != 1) {
    pcVar9 = local_c->sym->def;
    insert_fn = tuple_insert_before;
    pcVar7 = operand_new_intconst(0x1004,0,0);
    local_8 = tuple_new_unary_temp(1,0x1004,pcVar7,insert_fn,pcVar9);
    local_8->dst->u18 = pcVar11->u18;
  }
  uVar2 = g_setcc_opcode_by_cc[g_cond_to_x86_cc[local_24]];
  if (local_28 == 5) {
    pcVar8 = operand_low_byte(pcVar11,0,0);
  }
  else {
    pcVar8 = operand_new_temp(0x1001);
    pcVar8->u18 = pcVar11->u18;
  }
  pcVar9 = tuple_new(uVar2,0x1001,pcVar8,local_c,tuple_insert_before,local_10);
  pcVar3 = pcVar8->sym;
  if (pcVar3->storage->part_next == (c2_symbol *)0x0) {
    pcVar3->def = pcVar9;
  }
  else {
    symbol_mark_overlapping_parts(pcVar3,pcVar9);
  }
  flags_bind_compare_result(pcVar9,pcVar9->src);
  if (local_8 != (c2_tuple *)0x0) {
    tuple_append_src(pcVar9,local_8->dst);
  }
  switch(local_28) {
  case 5:
    break;
  default:
    pcVar17 = tuple_insert_after;
    pcVar10 = operand_narrow_to(pcVar8,0x1004,0);
    pcVar11 = operand_narrow_to(pcVar11,0x1004,0);
    pcVar9 = tuple_new(g_select_form_opcodes[local_28],0x1004,pcVar11,pcVar10,pcVar17,pcVar9);
    break;
  case 9:
    pcVar17 = tuple_insert_after;
    pcVar7 = operand_new_intconst(0x1004,local_1c,(int)local_1c >> 0x1f);
    pcVar10 = operand_narrow_to(pcVar8,0x1004,0);
    insert_fn = pcVar17;
    goto LAB_1074a403;
  case 10:
    pcVar17 = tuple_insert_after;
    pcVar8 = operand_narrow_to(pcVar8,0x1004,0);
    pcVar9 = tuple_new_unary_temp(0x1e,0x1004,pcVar8,pcVar17,pcVar9);
    pcVar8 = pcVar9->dst;
    pcVar17 = tuple_insert_after;
    pcVar8->u18 = pcVar11->u18;
    pcVar16 = pcVar10;
    pcVar8 = operand_narrow_to(pcVar8,pcVar10->type,0);
    pcVar11 = operand_narrow_to(pcVar11,pcVar10->type,0);
    pcVar9 = tuple_new_binary(0x2e,pcVar10->type,pcVar11,pcVar8,pcVar16,pcVar17,pcVar9);
    if (((pcVar10->type & 0xfff) < 4) && (iVar6 = operand_readable_as_dword(pcVar10), iVar6 != 0)) {
      set_op_width(pcVar9,4);
    }
    break;
  case 0xc:
    insert_fn = tuple_insert_after;
    pcVar10 = operand_narrow_to(pcVar8,0x1004,0);
    pcVar9 = tuple_new_unary_temp(0x1e,0x1004,pcVar10,insert_fn,pcVar9);
    uVar2 = local_1c;
    pcVar10 = pcVar9->dst;
    cVar4 = pcVar11->u18;
    insert_fn = tuple_insert_after;
    pcVar10->u18 = cVar4;
    pcVar7 = operand_new_intconst(0x1004,local_4 - local_1c,(int)(local_4 - local_1c) >> 0x1f);
    pcVar9 = tuple_new_binary_temp(0x2e,0x1004,pcVar10,pcVar7,insert_fn,pcVar9);
    pcVar10 = pcVar9->dst;
    insert_fn = tuple_insert_after;
    pcVar10->u18 = cVar4;
    pcVar7 = operand_new_intconst(0x1004,uVar2,(int)uVar2 >> 0x1f);
LAB_1074a403:
    pcVar11 = operand_narrow_to(pcVar11,0x1004,0);
    pcVar9 = tuple_new_binary(0x2d,0x1004,pcVar11,pcVar10,pcVar7,insert_fn,pcVar9);
  }
  if (local_28 != 5) {
    pcVar3 = pcVar9->dst->sym;
    if (pcVar3->storage->part_next == (c2_symbol *)0x0) {
      pcVar3->def = pcVar9;
      tuple_unlink_free(local_10);
      return pcVar9;
    }
    symbol_mark_overlapping_parts(pcVar3,pcVar9);
  }
  tuple_unlink_free(local_10);
  return pcVar9;
}

