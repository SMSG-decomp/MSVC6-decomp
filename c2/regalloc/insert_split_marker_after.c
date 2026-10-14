c2_tuple * __fastcall insert_split_marker_after(c2_tuple *pos,uint32_t n)

{
  c2_bitset *bs;
  c2_tuple *t;
  
  bs = bitset_new(6);
  bitset_set(bs,n);
  t = (c2_tuple *)new_split_marker(bs);
  tuple_insert_after(pos,t);
  return t;
}

