c2_symbol * __fastcall reg_find_subreg(c2_symbol *reg,int bits,int bitoff)

{
  c2_symbol *pcVar1;
  
  for (pcVar1 = reg->storage; (bits != pcVar1->size || (bitoff != pcVar1->offset));
      pcVar1 = pcVar1->part_next) {
  }
  return pcVar1;
}

