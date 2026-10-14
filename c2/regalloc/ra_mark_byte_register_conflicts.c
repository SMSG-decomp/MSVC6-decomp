c2_tuple * __fastcall
ra_mark_byte_register_conflicts(c2_tuple *t,c2_bitset *bs,c2_live_range *picked)

{
  c2_live_range *pcVar1;
  uint32_t id;
  c2_tuple *pcVar2;
  int iVar3;
  c2_operand *pcVar4;
  c2_symbol *reg;
  uint32_t uVar5;
  c2_bitset *bs_00;
  c2_bitset *local_c;
  int local_8;
  c2_symbol *src_sym;
  
  bs_00 = (c2_bitset *)0x0;
  pcVar4 = t->src;
  local_8 = 0;
  local_c = (c2_bitset *)0x0;
  for (; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
    if ((((pcVar4->kind == '\x01') && (pcVar1 = (pcVar4->u18).range, pcVar1->kind == '\x02')) &&
        (pcVar1 != picked)) && (pcVar1->colour == (c2_register_descriptor *)0x0)) {
      src_sym = pcVar4->sym;
      if (src_sym->cls == '\r') {
        if (local_c == (c2_bitset *)0x0) {
          local_c = bitset_new(6);
        }
        bitset_set(local_c,pcVar1->id);
        pcVar4 = tuple_replace_src_with_base_copy(t,pcVar4,src_sym);
        bs_00 = local_c;
      }
      else {
        local_8 = local_8 + 1;
        bs_00 = local_c;
      }
    }
  }
  id = bitset_iter_next(bs);
  while (id != 0xffffffff) {
    reg = (c2_symbol *)live_range_from_id(id);
    if (((reg != (c2_symbol *)picked) &&
        (iVar3._0_2_ = reg->type, iVar3._2_2_ = reg->x12, iVar3 == 0)) &&
       ((bs_00 == (c2_bitset *)0x0 || (uVar5 = bitset_test(bs_00,id), uVar5 == 0)))) {
      iVar3 = bitset_intersects((c2_bitset *)reg->size,g_nonbyte_register_set);
      if ((iVar3 == 0) ||
         (((1 < local_8 && (pcVar4 = find_src_reg_operand(reg,t), pcVar4 != (c2_operand *)0x0)) &&
          (pcVar4 = find_dst_reg_operand(reg,t), pcVar4 == (c2_operand *)0x0)))) {
        reg->flags6 = reg->flags6 | 2;
        pcVar4 = find_dst_reg_operand(reg,t);
        if ((pcVar4 == (c2_operand *)0x0) &&
           ((((reg->flags5 & 0x80) == 0 ||
             (pcVar4 = find_src_reg_operand(reg,t), pcVar4 == (c2_operand *)0x0)) ||
            ((t->src->type & 0xfff) != 1)))) {
          if (bs_00 == (c2_bitset *)0x0) {
            bs_00 = bitset_new(6);
          }
          bitset_set(bs_00,id);
          if ((1 < local_8) && (pcVar4 = find_src_reg_operand(reg,t), pcVar4 != (c2_operand *)0x0))
          {
            insert_split_marker_after(t->prev,id);
          }
        }
      }
      else {
        bitset_and((c2_bitset *)reg->size,g_nonbyte_register_set);
      }
    }
    id = bitset_iter_next((c2_bitset *)0x0);
  }
  if (bs_00 != (c2_bitset *)0x0) {
    if ((t->flags12 != '\0') && (pcVar2 = t->next, pcVar2->kind == '\x1b')) {
      bitset_or((pcVar2->u14).regs,bs_00);
      bitset_free(bs_00);
      return pcVar2;
    }
    pcVar2 = insert_pressure_split_marker(t,(c2_bitset *)0x0,(c2_bitset *)0x0,bs_00);
    bitset_free(bs_00);
    return pcVar2;
  }
  return (c2_tuple *)0x0;
}

