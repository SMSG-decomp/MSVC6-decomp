void init_register_class_sets(void)

{
  c2_bitset *bs;
  
  bs = bitset_new(0);
  bitset_set(bs,1);
  bitset_set(bs,2);
  bitset_set(bs,3);
  bitset_set(bs,4);
  bitset_set(bs,6);
  bitset_set(bs,7);
  bitset_set(bs,8);
  g_class_allowed_sets[0] = bs;
  g_class_allowed_sets[1] = bitset_new(0);
  g_byte_register_set = bitset_new(0);
  bitset_set(g_byte_register_set,1);
  bitset_set(g_byte_register_set,2);
  bitset_set(g_byte_register_set,3);
  bitset_set(g_byte_register_set,4);
  g_nonbyte_register_set = bitset_new(0);
  bitset_set(g_nonbyte_register_set,6);
  bitset_set(g_nonbyte_register_set,7);
  bitset_set(g_nonbyte_register_set,8);
  return;
}

