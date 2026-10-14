c2_symbol * __fastcall symbol_get_part_2(c2_symbol *s,uint16_t type,uint32_t size,int offset)

{
  c2_symbol *pcVar1;
  
  pcVar1 = symbol_get_part(s,type,size,offset);
  return pcVar1;
}

