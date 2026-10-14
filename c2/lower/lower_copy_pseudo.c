void __fastcall lower_copy_pseudo(c2_tuple *t)

{
  ushort type;
  c2_operand *op;
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_const_operand *size;
  c2_operand *local_8;
  c2_operand *local_4;
  c2_insert_fn *insert_fn;
  
  op = t->src;
  if (((1 << (op->kind & 0x1f) & 6U) == 0) || (op->sym->def == (c2_tuple *)0x0)) {
    pcVar2 = t->dst;
    if (pcVar2 != (c2_operand *)0x0) {
      tuple_detach_dst(t,pcVar2);
      tuple_detach_src((c2_node *)t,op);
      if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) {
        pcVar1 = find_next_use_of_symbol((c2_node *)t,pcVar2->sym,&local_8);
        if (((local_8->flags & 0x20) == 0) || (op->kind != '\x03')) {
          tuple_replace_src(pcVar1,local_8,op);
          tuple_unlink_free(t);
          return;
        }
        pcVar2 = find_mem_operand_using(pcVar1,local_8,&local_4);
        operand_to_memory_form(op);
        operand_set_type(op,pcVar2->type);
        if (pcVar2->disp != 0) {
          pcVar3 = op->sym;
          pcVar3 = symbol_get_part(pcVar3,pcVar3->type,pcVar3->size,pcVar2->disp);
          op->sym = pcVar3;
        }
        if (local_4 == pcVar1->src) {
          tuple_replace_src(pcVar1,pcVar2,op);
          tuple_unlink_free(t);
          return;
        }
        tuple_replace_dst(pcVar1,pcVar2,op);
        tuple_unlink_free(t);
        return;
      }
      type = t->type;
      insert_fn = tuple_insert_before;
      if ((type & 0xf000) == 0x5000) {
        pcVar1 = t;
        size = operand_new_intconst(0x1004,type & 0xfff,0);
        tuple_new_blockop(0x16b,type,pcVar2,op,size,insert_fn,pcVar1);
        tuple_unlink_free(t);
        return;
      }
      tuple_new(0x15b,type,pcVar2,op,tuple_insert_before,t);
    }
  }
  else {
    pcVar2 = t->dst;
    if (pcVar2 == (c2_operand *)0x0) {
      tuple_drop_unused_results(op);
      tuple_unlink_free(t);
      return;
    }
    tuple_detach_dst(t,pcVar2);
    pcVar1 = op->sym->def;
    tuple_replace_dst(pcVar1,pcVar1->dst,pcVar2);
    if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) {
      symbol_mark_overlapping_parts(pcVar1->dst->sym,pcVar1);
      tuple_unlink_free(t);
      return;
    }
  }
  tuple_unlink_free(t);
  return;
}

