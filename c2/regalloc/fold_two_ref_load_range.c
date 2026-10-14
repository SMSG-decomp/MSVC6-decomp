c2_bitset * __fastcall fold_two_ref_load_range(c2_live_range *lr,uint32_t id,c2_bitset *folded)

{
  uint8_t uVar1;
  byte bVar2;
  ushort type;
  c2_tuple *t;
  c2_tuple *t_00;
  c2_block *pcVar3;
  c2_operand *op;
  uint uVar4;
  c2_operand *new_op;
  c2_symbol *sym;
  
  t = (lr->u38).def;
  if (((((t->op == 1) && (t->dst->rank != 0)) && ((t->next->flags & 1) != 0)) &&
      ((uVar1 = t->src->kind, uVar1 == '\x02' || (uVar1 == '\x06')))) &&
     (op = find_src_reg_operand((c2_symbol *)lr,t->next), op != (c2_operand *)0x0)) {
    t_00 = t->next;
    uVar4 = can_use_memory_operand(t_00,op);
    if (((uVar4 != 0) && ((op != t_00->src || ((g_x86_op_flags[t_00->op] & 0x40) == 0)))) &&
       ((g_opt_favor_speed == 0 || (t_00->op != 0xd)))) {
      new_op = t->src;
      type = op->type;
      if (((type ^ new_op->type) & 0xfff) != 0) {
        if (((new_op->type & 0xfff) < (type & 0xfff)) &&
           ((new_op->kind == '\x06' ||
            ((new_op->kind == '\x02' &&
             ((uVar1 = new_op->sym->cls, uVar1 == '\a' || (uVar1 == '\b')))))))) {
          return folded;
        }
        if (new_op->kind == '\x02') {
          sym = symbol_get_part(new_op->sym,type,type & 0xfff,op->sym->offset - t->dst->sym->offset)
          ;
          new_op = operand_new_sym(new_op->op,type,sym);
        }
        else {
          bVar2 = new_op->flags;
          new_op = operand_new_mem(new_op->op,type,new_op->base_sym,
                                   (op->sym->offset - t->dst->sym->offset) + new_op->disp,
                                   new_op->base,new_op->index,new_op->tag);
          new_op->flags = (new_op->flags ^ bVar2 & 0xf) & 0xf ^ new_op->flags;
        }
      }
      tuple_replace_src(t->next,op,new_op);
      tuple_unlink_free(t);
      if (folded == (c2_bitset *)0x0) {
        folded = bitset_new(6);
      }
      bitset_set(folded,id);
      pcVar3 = lr->first_block;
      bitset_clear(pcVar3->live,id);
      pcVar3->flags = pcVar3->flags | 0x80000;
      free_live_range(lr,1);
      return folded;
    }
  }
  return folded;
}

