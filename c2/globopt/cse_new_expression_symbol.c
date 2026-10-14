c2_symbol * __fastcall cse_new_expression_symbol(uint16_t type)

{
  c2_symbol *pcVar1;
  
  pcVar1 = symbol_alloc('\x0f');
  pcVar1->type = type;
  pcVar1->size = type & 0xfff;
  pcVar1->cls = '\x03';
  pcVar1->storage = pcVar1;
  return pcVar1;
}

