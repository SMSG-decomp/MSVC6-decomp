void __fastcall sym_detail_set_flag3f_bit3(c1_symbol *tag)

{
  c1_u8 *pcVar1;
  
  pcVar1 = &((tag->detail).cls)->flags3f;
  *pcVar1 = *pcVar1 | 8;
  return;
}

