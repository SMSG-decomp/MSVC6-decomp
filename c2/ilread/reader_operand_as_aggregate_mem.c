c2_operand * __fastcall reader_operand_as_aggregate_mem(c2_tuple *t,uint32_t size)

{
  c2_operand *pcVar1;
  c2_symbol *sym;
  c2_tuple *pcVar2;
  ushort type;
  
  pcVar1 = t->src;
  type = (ushort)size | 0x5000;
  switch(pcVar1->kind) {
  case '\0':
    halt_baddata();
  default:
    break;
  case '\x03':
    sym = symbol_get_part(pcVar1->sym,type,size,0);
    pcVar1 = operand_new_sym(pcVar1->op,type,sym);
    return pcVar1;
  case '\x04':
    pcVar2 = tuple_new_unary_temp(0x15b,t->type,pcVar1,tuple_insert_before,t);
    pcVar1 = pcVar2->dst;
  }
  pcVar1 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,pcVar1,(c2_operand *)0x0,0);
  return pcVar1;
}

