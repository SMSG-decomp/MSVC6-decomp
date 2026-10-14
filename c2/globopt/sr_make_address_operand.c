c2_operand * __fastcall sr_make_address_operand(c2_operand *a,c2_operand *b)

{
  c2_operand *pcVar1;
  uint32_t op;
  uint32_t local_8;
  c2_symbol *local_4;
  
  local_4 = (c2_symbol *)0x0;
  op = 0x14c;
  local_8 = 0;
  pcVar1 = (c2_operand *)0x0;
  switch(a->kind) {
  case '\x01':
  case '\x02':
    op = 0x14d;
    pcVar1 = b;
    b = a;
    break;
  case '\x03':
    local_4 = a->sym;
    break;
  default:
    return (c2_operand *)0x0;
  case '\a':
    local_8 = (a->u18).lo;
  }
  pcVar1 = operand_new_addr(op,0x1004,local_4,local_8,b,pcVar1);
  return pcVar1;
}

