void __fastcall expand_udiv_by_constant(c2_tuple *anchor)

{
  uint uVar1;
  c2_symbol *sym;
  c2_const_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  uint32_t lo;
  c2_operand *pcVar5;
  uint16_t type;
  uint uVar6;
  int iVar7;
  int iVar8;
  c2_udiv_magic *pcVar9;
  uint uVar10;
  uint uVar11;
  c2_operand *pcVar12;
  code *insert_fn_00;
  uint local_c;
  uint local_8;
  int local_4;
  c2_insert_fn *insert_fn;
  
  uVar1 = (anchor->src->next->u18).lo;
  if ((uVar1 < 3) || (0xc < uVar1)) {
    g_udiv_magic_result.add_one = 0;
    local_4 = 0x1f;
    uVar11 = -(-uVar1 % uVar1) - 1;
    local_c = (uint)(0x80000000 / (ulonglong)uVar11);
    uVar10 = 0x80000000 - local_c * uVar11;
    local_8 = (uint)(0x7fffffff / (ulonglong)uVar1);
    iVar8 = 0x7fffffff - local_8 * uVar1;
    iVar7 = local_4;
    do {
      local_4 = iVar7;
      iVar7 = local_4 + 1;
      if (uVar10 < uVar11 - uVar10) {
        uVar10 = uVar10 * 2;
        local_c = local_c * 2;
      }
      else {
        local_c = local_c * 2 + 1;
        uVar10 = uVar10 * 2 - uVar11;
      }
      if (iVar8 + 1U < uVar1 - iVar8) {
        if (0x7fffffff < local_8) {
          g_udiv_magic_result.add_one = 1;
        }
        local_8 = local_8 * 2;
        iVar8 = iVar8 * 2;
      }
      else {
        if (0x7ffffffe < local_8) {
          g_udiv_magic_result.add_one = 1;
        }
        local_8 = local_8 * 2 + 1;
        iVar8 = iVar8 * 2 - uVar1;
      }
      iVar8 = iVar8 + 1;
      uVar6 = (uVar1 - iVar8) - 1;
    } while ((iVar7 < 0x40) && ((local_c < uVar6 || ((local_c == uVar6 && (uVar10 == 0))))));
    g_udiv_magic_result.multiplier = local_8 + 1;
    g_udiv_magic_result.shift = local_4 + -0x1f;
    pcVar9 = &g_udiv_magic_result;
  }
  else {
    pcVar9 = g_udiv_magic_table + (uVar1 - 3);
  }
  pcVar12 = anchor->src;
  if (pcVar9->add_one == 0) {
    if (pcVar12->type != 0x2004) {
      pcVar3 = tuple_new_unary_temp(0x15f,0x2004,pcVar12,tuple_insert_before,anchor);
      pcVar12 = pcVar3->dst;
    }
    insert_fn = tuple_insert_before;
    pcVar3 = anchor;
    pcVar2 = operand_new_intconst(0x2004,pcVar9->multiplier,0);
    pcVar3 = tuple_new_binary_temp(0x170,0x2004,pcVar12,pcVar2,insert_fn,pcVar3);
    lo = pcVar9->shift;
  }
  else {
    pcVar5 = operand_new_temp_sym(0x2004);
    mark_operand_register_candidate(pcVar5);
    pcVar3 = tuple_new((-(uint)(pcVar12->type != 0x2004) & 4) + 0x15b,0x2004,pcVar5,pcVar12,
                       tuple_insert_before,anchor);
    pcVar12 = pcVar3->dst;
    pcVar5 = operand_new_temp_sym(0x2004);
    mark_operand_register_candidate(pcVar5);
    insert_fn = tuple_insert_before;
    pcVar3 = anchor;
    pcVar2 = operand_new_intconst(0x2004,pcVar9->multiplier,0);
    pcVar3 = tuple_new_binary(0x170,0x2004,pcVar5,pcVar12,pcVar2,insert_fn,pcVar3);
    pcVar5 = pcVar3->dst;
    pcVar4 = tuple_new_binary_temp(0x16e,0x2004,pcVar12,pcVar5,tuple_insert_before,anchor);
    insert_fn_00 = tuple_insert_before;
    pcVar3 = anchor;
    pcVar2 = operand_new_intconst(0x2004,1,0);
    pcVar3 = tuple_new_binary_temp(0x177,0x2004,pcVar4->dst,pcVar2,insert_fn_00,pcVar3);
    pcVar3 = tuple_new_binary_temp(0x16d,0x2004,pcVar3->dst,pcVar5,tuple_insert_before,anchor);
    lo = pcVar9->shift - 1;
  }
  if (0 < (int)lo) {
    insert_fn = tuple_insert_before;
    pcVar4 = anchor;
    pcVar2 = operand_new_intconst(0x2004,lo,(int)lo >> 0x1f);
    pcVar3 = tuple_new_binary_temp(0x177,0x2004,pcVar3->dst,pcVar2,insert_fn,pcVar4);
  }
  pcVar12 = anchor->dst;
  insert_fn = tuple_insert_before;
  type = pcVar12->type;
  pcVar4 = anchor;
  if ((type & 0xfff) == 4) {
    pcVar5 = pcVar3->dst;
    type = 0x2004;
  }
  else {
    iVar8 = 0;
    pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar3->dst);
    pcVar5 = operand_retype(pcVar5,type,iVar8);
  }
  pcVar3 = tuple_new(0x15b,type,pcVar12,pcVar5,insert_fn,pcVar4);
  if (((1 << (pcVar12->kind & 0x1f) & 6U) != 0) && (sym = pcVar12->sym, sym->def != (c2_tuple *)0x0)
     ) {
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = pcVar3;
      tuple_unlink_free(anchor);
      return;
    }
    symbol_mark_overlapping_parts(sym,pcVar3);
  }
  tuple_unlink_free(anchor);
  return;
}

