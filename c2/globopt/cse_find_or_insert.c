int __fastcall cse_find_or_insert(uint32_t op,uint16_t type)

{
  uint32_t bucket;
  c2_cse_expr *pcVar1;
  
  bucket = hash_expression(op,type);
  pcVar1 = cse_lookup(bucket,op,type);
  if (pcVar1 == (c2_cse_expr *)0x0) {
    pcVar1 = cse_insert(bucket,op,type);
  }
  return (int)pcVar1->sym;
}

