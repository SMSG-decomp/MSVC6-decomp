void __fastcall legalize_mem_operand(c2_tuple *t,c2_operand *op,c2_insert_fn *insert_fn)

{
  byte bVar1;
  bool bVar2;
  c2_operand *pcVar3;
  c2_operand *src;
  byte bVar4;
  
  if ((op != (c2_operand *)0x0) && ((1 << (op->kind & 0x1f) & 0x60U) != 0)) {
    pcVar3 = op->index;
    src = op->base;
    bVar2 = false;
    if ((pcVar3 != (c2_operand *)0x0) && (pcVar3->kind != '\x01')) {
      bVar2 = true;
      pcVar3 = emit_load_into_register(1,t,pcVar3,g_reg_symbols);
    }
    if ((src == (c2_operand *)0x0) || (src->kind == '\x01')) {
      if (!bVar2) {
        return;
      }
    }
    else {
      src = emit_load_into_register(1,t,src,g_reg_symbols);
    }
    if (op->kind == '\x06') {
      pcVar3 = operand_new_mem(op->op,op->type,op->base_sym,op->disp,src,pcVar3,op->tag);
    }
    else {
      pcVar3 = operand_new_addr(op->op,op->type,op->base_sym,op->disp,src,pcVar3);
    }
    bVar1 = op->flags;
    bVar4 = (bVar1 ^ pcVar3->flags) & 0xf ^ pcVar3->flags;
    pcVar3->flags11 = (op->flags11 ^ pcVar3->flags11) & 7 ^ pcVar3->flags11;
    pcVar3->flags = (bVar4 ^ bVar1) & 0x40 ^ bVar4;
    (*insert_fn)(t,(c2_tuple *)op);
  }
  return;
}

