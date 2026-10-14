void __fastcall remove_redundant_extension(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  uint uVar3;
  c2_symbol *pcVar4;
  c2_operand *op;
  c2_tuple *t_00;
  uint16_t type;
  uint32_t uVar5;
  c2_symbol *local_4;
  uint16_t size_facts;
  
  pcVar2 = t->src;
  if (((((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) &&
      (op = t->dst, (1 << (op->kind & 0x1f) & 6U) != 0)) && (op->sym->def != (c2_tuple *)0x0)) {
    uVar5 = temp_operand_piece_mismatch(pcVar2);
    if ((uVar5 == 0) || (local_4 = (pcVar2->u18).reg, pcVar2->sym->storage == local_4->storage)) {
      local_4 = (c2_symbol *)0x0;
    }
    t_00 = pcVar2->sym->def;
    size_facts = *(uint16_t *)&op->sym->u30;
    uVar1 = (op->sym->u30).sizeopt.width_facts;
    if (t_00->dst->sym->offset < 1) {
      tuple_detach_dst(t,op);
      tuple_unlink_free(t);
      op->sym->def = (c2_tuple *)0x0;
      try_substitute_operand(t_00,t_00->dst,op,tuple_replace_dst);
      pcVar4 = t_00->dst->sym;
      *(uint16_t *)&pcVar4->u30 = size_facts;
      (pcVar4->u30).sizeopt.width_facts = uVar1;
      if (pcVar4->storage->part_next == (c2_symbol *)0x0) {
        pcVar4->def = t_00;
      }
      else {
        symbol_mark_overlapping_parts(pcVar4,t_00);
      }
      pcVar4 = local_4;
      if (local_4 == (c2_symbol *)0x0) {
        return;
      }
      (t_00->dst->u18).reg = local_4;
      find_next_use_of_dst(t_00,(c2_operand **)&local_4);
      (local_4->u18).inline_callee = (c2_function *)pcVar4;
      return;
    }
  }
  uVar3 = t->op;
  if ((uVar3 != 0x15b) && ((uVar3 < 0x15f || (0x161 < uVar3)))) {
    tuple_remove_src(t,pcVar2->next);
  }
  if ((t->op == 0) || (0x143 < t->op)) {
    t->op = 0x15b;
  }
  else {
    t->op = 1;
  }
  pcVar2 = t->dst;
  if (((1 << (pcVar2->kind & 0x1f) & 6U) == 0) || (pcVar2->sym->def == (c2_tuple *)0x0)) {
    type = pcVar2->type;
  }
  else {
    type = extension_source_type(t->src,pcVar2);
  }
  operand_retype(t->dst,type,0);
  operand_retype(t->src,type,0);
  t->type = type;
  if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) &&
     (pcVar4 = t->dst->sym, pcVar4->def != (c2_tuple *)0x0)) {
    if (pcVar4->storage->part_next == (c2_symbol *)0x0) {
      pcVar4->def = t;
      return;
    }
    symbol_mark_overlapping_parts(pcVar4,t);
  }
  return;
}

