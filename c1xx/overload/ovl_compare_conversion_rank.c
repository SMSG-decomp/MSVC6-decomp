int __thiscall ovl_compare_conversion_rank(c1_conversion *conv_a,c1_conversion *conv_b)

{
  if (((conv_a->rank ^ conv_b->rank) & 0xf0U) != 0) {
    return ((conv_b->rank <= conv_a->rank) - 1 & 2) - 1;
  }
  return 0;
}

