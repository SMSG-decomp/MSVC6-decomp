int __fastcall cse_available_value_of(c2_tuple *t,uint16_t type)

{
  uint32_t bucket;
  c2_cse_expr *pcVar1;
  
  cse_set_key_operands(2);
  bucket = hash_expression((int)t,type);
  pcVar1 = cse_lookup(bucket,(uint32_t)t,type);
  if (pcVar1 == (c2_cse_expr *)0x0) {
    return 0;
  }
  return (int)pcVar1->sym;
}

