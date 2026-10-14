c2_symbol * __fastcall symbol_new_temp(uint16_t type)

{
  c2_symbol *pcVar1;
  
  pcVar1 = symbol_alloc('\x03');
  pcVar1->type = type;
  pcVar1->size = type & 0xfff;
  pcVar1->cls = '\x03';
  pcVar1->storage = pcVar1;
  pcVar1->flags5 = pcVar1->flags5 | 1;
  return pcVar1;
}

