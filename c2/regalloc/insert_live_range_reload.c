c2_tuple * __fastcall insert_live_range_reload(c2_symbol *sym,void *home,c2_tuple *where)

{
  uint8_t uVar1;
  c2_const_operand *src;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *dst;
  uint32_t op;
  uint16_t type;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  if (sym->cls != '\r') {
    if ((sym->u34).parent != (c2_symbol *)0x0) {
      sym = (sym->u34).parent;
    }
    type = sym->type;
    if (type == 0x3004) {
      type = 0x1004;
    }
    uVar1 = sym->cls;
    if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
       (op = 0x14b, uVar1 == '\x06')) {
      op = 0x14a;
    }
    insert_fn_00 = tuple_insert_before;
    pcVar2 = operand_new_sym(op,type,sym);
    dst = operand_new_reg(0x149,type,sym,home);
    pcVar3 = tuple_new(0x163,type,dst,pcVar2,insert_fn_00,where);
    return pcVar3;
  }
  pcVar2 = (sym->u28).const_operand;
  if (pcVar2->kind == '\a') {
    src = operand_new_intconst(0x1004,(pcVar2->u18).lo,pcVar2->tag);
  }
  else {
    src = (c2_const_operand *)node_clone((c2_node *)pcVar2);
  }
  insert_fn = tuple_insert_before;
  pcVar2 = operand_new_reg(0x149,0x1004,sym,home);
  pcVar3 = tuple_new(0x163,0x1004,pcVar2,src,insert_fn,where);
  return pcVar3;
}

