c2_operand * __fastcall convert_operand_wrapper(uint16_t type,c2_operand *v,c2_tuple *at)

{
  c2_operand *local_4;
  
  at = at->prev;
  local_4 = v;
  convert_operand(&local_4,type,&at);
  return local_4;
}

