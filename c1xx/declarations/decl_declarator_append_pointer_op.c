void __thiscall decl_declarator_append_pointer_op(c1_decl_record *rec,c1_ptr_operator *op)

{
  c1_u16 cVar1;
  ushort uVar2;
  ushort uVar3;
  c1_type *layer;
  
  uVar3 = 0;
  cVar1 = op->kind;
  if (cVar1 == 0x80) {
    uVar3 = type_check_based_reference(rec,op->modifiers);
  }
  else if (cVar1 == 0x82) {
    uVar3 = op->modifiers;
    uVar2 = op->cv;
    if ((uVar3 & 7) != 0) {
      rec->layer_flags = rec->layer_flags | 1;
    }
    uVar3 = uVar3 | uVar2;
  }
  else if (cVar1 == 0x8a) {
    uVar3 = type_check_based_member_pointer(rec,op->modifiers,op->cv);
  }
  layer = (c1_type *)record_pos_new(op->kind,uVar3,(int *)&op->extra);
  if (op->kind == 0x80) {
    decl_check_modifier_over_reference(rec,layer);
  }
  if (rec->chain_tail == (c1_type *)0x0) {
    rec->chain_tail = layer;
    rec->chain_head = layer;
    return;
  }
  rec->chain_tail->base = layer;
  rec->chain_tail = layer;
  return;
}

