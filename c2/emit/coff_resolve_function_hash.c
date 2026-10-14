int __fastcall coff_resolve_function_hash(uint32_t key)

{
  uint32_t symbol_index;
  
  symbol_index = coff_hash64_find(key,1);
  coff_hash32_resolve(key,symbol_index);
  return symbol_index;
}

