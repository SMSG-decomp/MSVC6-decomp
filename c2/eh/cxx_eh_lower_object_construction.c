void __fastcall cxx_eh_lower_object_construction(c2_tuple *cursor)

{
  ushort type;
  c2_eh_state *rec;
  c2_operand *op;
  c2_symbol *sym;
  int iVar1;
  c2_tuple *pcVar2;
  c2_const_operand *size;
  c2_insert_fn *insert_fn;
  
  rec = ((cursor->u20).eh_construct)->object;
  if ((char)rec->flags != '\x04') {
    push_eh_state(rec);
    insert_eh_state_store(rec->state,rec->to_state,rec,cursor);
  }
  op = cursor->src;
  if (cursor->dst == (c2_operand *)0x0) {
    if (((op != (c2_operand *)0x0) && ((1 << (op->kind & 0x1f) & 6U) != 0)) &&
       (op->sym->def != (c2_tuple *)0x0)) {
      tuple_drop_unused_results(op);
    }
  }
  else {
    if (((1 << (op->kind & 0x1f) & 6U) != 0) && (pcVar2 = op->sym->def, pcVar2 != (c2_tuple *)0x0))
    {
      reader_spill_eh_value(pcVar2);
    }
    type = cursor->type;
    insert_fn = tuple_insert_after;
    if ((type & 0xf000) == 0x5000) {
      pcVar2 = cursor;
      size = operand_new_intconst(0x1004,type & 0xfff,0);
      pcVar2 = tuple_new_blockop(0x16b,cursor->type,cursor->dst,cursor->src,size,insert_fn,pcVar2);
    }
    else {
      pcVar2 = tuple_new(0x15b,type,cursor->dst,cursor->src,tuple_insert_after,cursor);
    }
    if (((1 << (cursor->dst->kind & 0x1f) & 6U) != 0) &&
       (sym = cursor->dst->sym, sym->def != (c2_tuple *)0x0)) {
      if (sym->storage->part_next == (c2_symbol *)0x0) {
        sym->def = pcVar2;
        tuple_remove_dst(cursor,cursor->dst);
        goto LAB_10755ac7;
      }
      symbol_mark_overlapping_parts(sym,pcVar2);
    }
    tuple_remove_dst(cursor,cursor->dst);
  }
LAB_10755ac7:
  if (((cursor->u20).eh_construct)->object->funclet != (c2_function *)0x0) {
    iVar1 = cxx_eh_compile_funclet(cursor);
    if (iVar1 != 0) {
      tuple_remove_src(cursor,cursor->src);
      cursor->type = 0x1004;
      return;
    }
  }
  if (((cursor->u20).eh_construct)->object->funclet != (c2_function *)0x0) {
    rec->funclet->funclet_refs = rec->funclet->funclet_refs + -1;
    ((cursor->u20).cond_cells)->op = 0;
  }
  tuple_unlink_free(cursor);
  return;
}

