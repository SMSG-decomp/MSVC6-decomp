void __fastcall
bitset_assign_diff_union(c2_bitset *dst,c2_bitset *set,c2_bitset *src,c2_bitset *src2)

{
  bitset_assign_andnot(dst,set,src);
  bitset_or(dst,src2);
  return;
}

