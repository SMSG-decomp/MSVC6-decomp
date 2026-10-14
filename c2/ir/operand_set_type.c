c2_operand * __fastcall operand_set_type(c2_operand *op,uint16_t type)

{
  c2_symbol *pcVar1;
  
  switch(op->kind) {
  case '\0':
    halt_baddata();
  default:
    pcVar1 = symbol_get_part(op->sym,type,0,0);
    op->sym = pcVar1;
    op->type = type;
    return op;
  case '\x03':
  case '\x04':
    op->type = type;
    return op;
  }
}

