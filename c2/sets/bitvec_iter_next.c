uint32_t __fastcall bitvec_iter_next(c2_bitvec *v)

{
  uint uVar1;
  
  if (v != (c2_bitvec *)0x0) {
    g_bitvec_iter_word = v->words;
    g_bitvec_iter_bits = *g_bitvec_iter_word;
    g_bitvec_iter_index = 0;
    g_bitvec_iter_vec = v;
  }
  if (g_bitvec_iter_bits == 0) {
    do {
      uVar1 = g_bitvec_iter_index << 5;
      g_bitvec_iter_index = g_bitvec_iter_index + 1;
      if ((g_bitvec_iter_vec->nbits & 0xffffff) <= uVar1) {
        return 0xffffffff;
      }
      g_bitvec_iter_bits = g_bitvec_iter_word[1];
      g_bitvec_iter_word = g_bitvec_iter_word + 1;
    } while (g_bitvec_iter_bits == 0);
  }
  g_bitvec_iter_bit = 0;
  while ((g_bitvec_iter_bits & 1 << ((byte)g_bitvec_iter_bit & 0x1f)) == 0) {
    g_bitvec_iter_bit = g_bitvec_iter_bit + 1;
    if (0x1f < g_bitvec_iter_bit) {
      g_bitvec_iter_bit = 0xffffffff;
      return 0xffffffff;
    }
  }
  if (g_bitvec_iter_bit != 0xffffffff) {
    g_bitvec_iter_bit = g_bitvec_iter_index * 0x20 + g_bitvec_iter_bit;
    if (g_bitvec_iter_bit < (g_bitvec_iter_vec->nbits & 0xffffff)) {
      g_bitvec_iter_bits = g_bitvec_iter_bits & ~(1 << ((byte)g_bitvec_iter_bit & 0x1f));
      return g_bitvec_iter_bit;
    }
  }
  return 0xffffffff;
}

