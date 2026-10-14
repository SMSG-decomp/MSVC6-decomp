uint hash_fn_name(int key)

{
  return *(uint *)(key + 8) & 0xffff;
}

