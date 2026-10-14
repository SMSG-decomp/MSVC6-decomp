c2_tuple * __fastcall
insert_live_range_spill_store(c2_symbol *sym,c2_symbol *storage,c2_tuple *anchor)

{
  uint8_t uVar1;
  c2_operand *src;
  c2_operand *dst;
  c2_tuple *pcVar2;
  uint32_t op;
  uint16_t type;
  c2_insert_fn *insert_fn;
  
  type = sym->type;
  if (type == 0x3004) {
    type = 0x1004;
  }
  uVar1 = sym->cls;
  if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
     (op = 0x14b, uVar1 == '\x06')) {
    op = 0x14a;
  }
  insert_fn = tuple_insert_after;
  src = operand_new_reg(0x149,type,sym,storage);
  dst = operand_new_sym(op,type,sym);
  pcVar2 = tuple_new(0x164,type,dst,src,insert_fn,anchor);
  return pcVar2;
}

