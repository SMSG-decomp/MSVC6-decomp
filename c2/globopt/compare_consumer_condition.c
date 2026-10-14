uint8_t __fastcall compare_consumer_condition(c2_tuple *cmp)

{
  c2_tuple *pcVar1;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)cmp;
  pcVar1 = find_next_use_of_dst(cmp,&local_4);
  if (pcVar1->kind != '\x10') {
    return (uint8_t)pcVar1->type;
  }
  return (pcVar1->u20).cc;
}

